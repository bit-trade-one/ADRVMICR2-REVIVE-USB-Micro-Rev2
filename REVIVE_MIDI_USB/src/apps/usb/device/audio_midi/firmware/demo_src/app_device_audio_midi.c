/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
*******************************************************************************/
// 2022-03-24   V001   Bit Trade One REVIVE USB MIDI

/** INCLUDES *******************************************************/
#include <stdint.h>
#include <stdbool.h>

#include "system.h"

#include "usb.h"
#include "usb_device_midi.h"

#define DEAD_TIME   20      // chattering eliminattion time

/** VARIABLES ******************************************************/
/* Some processors have a limited range of RAM addresses where the USB module
 * is able to access.  The following section is for those devices.  This section
 * assigns the buffers that need to be used by the USB module into those
 * specific areas.
 */
#if defined(FIXED_ADDRESS_MEMORY)
    #if defined(COMPILER_MPLAB_C18)
        #pragma udata DEVICE_AUDIO_MIDI_RX_DATA_BUFFER=DEVCE_AUDIO_MIDI_RX_DATA_BUFFER_ADDRESS
            static uint8_t ReceivedDataBuffer[64];
        #pragma udata DEVICE_AUDIO_MIDI_EVENT_DATA_BUFFER=DEVCE_AUDIO_MIDI_EVENT_DATA_BUFFER_ADDRESS
            static USB_AUDIO_MIDI_EVENT_PACKET midiData;
        #pragma udata
    #elif defined(__XC8)
        static uint8_t ReceivedDataBuffer[64] DEVCE_AUDIO_MIDI_RX_DATA_BUFFER_ADDRESS;
        static USB_AUDIO_MIDI_EVENT_PACKET midiData DEVCE_AUDIO_MIDI_EVENT_DATA_BUFFER_ADDRESS;
    #endif
#else
    static uint8_t ReceivedDataBuffer[64];
    static USB_AUDIO_MIDI_EVENT_PACKET midiData;
#endif

static USB_HANDLE USBTxHandle;
static USB_HANDLE USBRxHandle;

static uint8_t  tone[13] = {              // V001 support 13 keys
//  note
    0x3c,           // C4
    0x3d,           // C#4
    0x3e,           // D4
    0x3f,           // D#4
    0x40,           // E4
    0x41,           // F4
    0x42,           // F#4
    0x43,           // G4
    0x44,           // G#4
    0x45,           // A4
    0x46,           // A#4
    0x47,           // B4
    0x48            // C5
};

//static uint8_t pitch;
static bool sentNoteOff[13];              // V001 support 13 keys

static USB_VOLATILE uint8_t msCounter[13];// V001 support 13 keys

/*********************************************************************
* Function: void APP_DeviceAudioMIDIInitialize(void);
*
* Overview: Initializes the demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceAudioMIDIInitialize()
{
    uint8_t i;

    USBTxHandle = NULL;
    USBRxHandle = NULL;

//    pitch = 0x3C;

    for (i = BUTTON_SC; i <= BUTTON_SC2; i++) {       // V001 support 13 keys
        sentNoteOff[i] = true;
        msCounter[i] = 0;
    }
    //enable the HID endpoint
    USBEnableEndpoint(USB_DEVICE_AUDIO_MIDI_ENDPOINT,USB_OUT_ENABLED|USB_IN_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);

    //Re-arm the OUT endpoint for the next packet
    USBRxHandle = USBRxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&ReceivedDataBuffer,64);
}

/*********************************************************************
* Function: void APP_DeviceAudioMIDIInitialize(void);
*
* Overview: Initializes the demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceAudioMIDISOFHandler()
{
    uint8_t i;

    for (i = BUTTON_SC; i <= BUTTON_SC2; i++) {       // V001 support 13 key
        if(msCounter[i] != 0) {
            msCounter[i]--;
        }
    }
}


/*********************************************************************
* Function: void APP_DeviceAudioMIDITasks(void);
*
* Overview: Keeps the Custom HID demo running.
*
* PreCondition: The demo should have been initialized and started via
*   the APP_DeviceAudioMIDIInitialize() and APP_DeviceAudioMIDIStart() demos
*   respectively.
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceAudioMIDITasks()
{
    uint8_t i;
    /* If the device is not configured yet, or the device is suspended, then
     * we don't need to run the demo since we can't send any data.
     */
    if( (USBGetDeviceState() < CONFIGURED_STATE) ||
        (USBIsDeviceSuspended() == true))
    {
        return;
    }

    if(!USBHandleBusy(USBRxHandle))
    {
        //We have received a MIDI packet from the host, process it and then
        //  prepare to receive the next packet

        //INSERT MIDI PROCESSING CODE HERE

        //Get ready for next packet (this will overwrite the old data)
        USBRxHandle = USBRxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&ReceivedDataBuffer,64);
    }

    /* If the user button is pressed... */
    for (i = BUTTON_SC; i <= BUTTON_SC2; i++) {       // V001 support 8 key
        if(BUTTON_IsPressed(i) == true) {
            /* and we haven't sent a transmission in the past 100ms... */
            if(msCounter[i] == 0)
            {
                /* and we have sent the NOTE_OFF for the last note... */
                if(sentNoteOff[i] == true)
                {
                    /* and we aren't currently trying to transmit data... */
                    if(!USBHandleBusy(USBTxHandle))
                    {
                        //Then reset the 100ms counter
                        msCounter[i] = DEAD_TIME;       // V001 100->20ms
                        midiData.Val = 0;   //must set all unused values to 0 so go ahead
                                            //  and set them all to 0
                        midiData.CableNumber = 0;
                        midiData.CodeIndexNumber = MIDI_CIN_NOTE_ON;
                        midiData.DATA_0 = 0x90;         //Note on
                        midiData.DATA_1 = tone[i];      //pitch
                        midiData.DATA_2 = 0x7F;         //velocity

                        USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&midiData,4);

                        /* we now need to send the NOTE_OFF for this note. */
                        sentNoteOff[i] = false;
                    }
                }
            }
        } else {
            if(msCounter[i] == 0)
            {
                if(sentNoteOff[i] == false)
                {
                    if(!USBHandleBusy(USBTxHandle))
                    {
                        //Debounce counter for 100ms
                        msCounter[i] = DEAD_TIME;   // V001 100->20ms
                        midiData.Val = 0;           //must set all unused values to 0 so go ahead
                                                    //  and set them all to 0
                        midiData.CableNumber = 0;
                        midiData.CodeIndexNumber = MIDI_CIN_NOTE_ON;
                        midiData.DATA_0 = 0x90;     //Note on
                        midiData.DATA_1 = tone[i];  //pitch
                        midiData.DATA_2 = 0x00;     //velocity = note off

                        USBTxHandle = USBTxOnePacket(USB_DEVICE_AUDIO_MIDI_ENDPOINT,(uint8_t*)&midiData,4);
                        sentNoteOff[i] = true;
                    }
                }
            }
        }
    }
}
