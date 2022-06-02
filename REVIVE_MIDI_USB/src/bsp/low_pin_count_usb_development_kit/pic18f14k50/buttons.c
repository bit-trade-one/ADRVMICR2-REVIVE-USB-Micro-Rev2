/********************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC(R) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *******************************************************************/
// 2022-03-24   V001   Bit Trade One REVIVE USB MIDI 

#include <xc.h>
#include <stdbool.h>
#include <buttons.h>

/*** Button Definitions *********************************************/
//#define S1_PORT  PORTAbits.RA3
//#define S1_PORT  PORTCbits.RC7
//#define S1_PORT_TRIS TRISCbits.TRISC7

// V001 add 13 keys for 1 Octave Keyboard
#define SC_PORT      PORTCbits.RC0
#define SC_PORT_TRIS TRISCbits.TRISC0
#define SD_PORT      PORTCbits.RC1
#define SD_PORT_TRIS TRISCbits.TRISC1
#define SE_PORT      PORTCbits.RC2
#define SE_PORT_TRIS TRISCbits.TRISC2
#define SF_PORT      PORTCbits.RC3
#define SF_PORT_TRIS TRISCbits.TRISC3
#define SG_PORT      PORTCbits.RC4
#define SG_PORT_TRIS TRISCbits.TRISC4
#define SA_PORT      PORTCbits.RC5
#define SA_PORT_TRIS TRISCbits.TRISC5
#define SB_PORT      PORTCbits.RC6
#define SB_PORT_TRIS TRISCbits.TRISC6
#define SC2_PORT      PORTCbits.RC7
#define SC2_PORT_TRIS TRISCbits.TRISC7

#define SCS_PORT      PORTBbits.RB4
#define SCS_PORT_TRIS TRISBbits.TRISB4
#define SDS_PORT      PORTBbits.RB5
#define SDS_PORT_TRIS TRISBbits.TRISB5
#define SFS_PORT      PORTBbits.RB6
#define SFS_PORT_TRIS TRISBbits.TRISB6
#define SGS_PORT      PORTBbits.RB7
#define SGS_PORT_TRIS TRISBbits.TRISB7
#define SAS_PORT      PORTAbits.RA3
//#define SAS_PORT_TRIS TRISAbits.TRISA3

#define BUTTON_PRESSED      0 
#define BUTTON_NOT_PRESSED  1

#define PIN_INPUT           1
#define PIN_OUTPUT          0

#define PIN_DIGITAL         1
#define PIN_ANALOG          0

/*********************************************************************
* Function: bool BUTTON_IsPressed(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names 
*        of the buttons on the silkscreen on the board (as the demo 
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: TRUE if pressed; FALSE if not pressed.
*
********************************************************************/
bool BUTTON_IsPressed(BUTTON button)
{
    // V001 add 13 Keys
    switch(button)
    {
        case BUTTON_SC:
            return ( (SC_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SCS:
            return ( (SCS_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SD:
            return ( (SD_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SDS:
            return ( (SDS_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SE:
            return ( (SE_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SF:
            return ( (SF_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SFS:
            return ( (SFS_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SG:
            return ( (SG_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SGS:
            return ( (SGS_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SA:
            return ( (SA_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SAS:
            return ( (SAS_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SB:
            return ( (SB_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_SC2:
            return ( (SC2_PORT == BUTTON_PRESSED) ? true : false);
    }
    
    return false;
}

/*********************************************************************
* Function: void BUTTON_Enable(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names
*        of the buttons on the silkscreen on the board (as the demo
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: None
*
********************************************************************/
void BUTTON_Enable(BUTTON button)
{
    // V001 add 13 Keys
    switch(button)
    {
        case BUTTON_SC:
            SC_PORT_TRIS = PIN_INPUT;
            ANSELbits.ANS4 = 0;    // Make RB5 pin digital
            break;
        case BUTTON_SCS:
            SCS_PORT_TRIS = PIN_INPUT;
            ANSELHbits.ANS10 = 0;    // Make RB5 pin digital
            break;
        case BUTTON_SD:
            SD_PORT_TRIS = PIN_INPUT;
            ANSELbits.ANS5 = 0;    // Make RB5 pin digital
            break;
        case BUTTON_SDS:
            SDS_PORT_TRIS = PIN_INPUT;
            ANSELHbits.ANS11 = 0;    // Make RB5 pin digital
            break;
        case BUTTON_SE:
            SE_PORT_TRIS = PIN_INPUT;
            ANSELbits.ANS6 = 0;    // Make RB5 pin digital
            break;
        case BUTTON_SF:
            SF_PORT_TRIS = PIN_INPUT;
            ANSELbits.ANS7 = 0;    // Make RB5 pin digital
            break;
        case BUTTON_SFS:
            SFS_PORT_TRIS = PIN_INPUT;
            break;
        case BUTTON_SG:
            SG_PORT_TRIS = PIN_INPUT;
            break;
        case BUTTON_SGS:
            SGS_PORT_TRIS = PIN_INPUT;
            break;
        case BUTTON_SA:
            SA_PORT_TRIS = PIN_INPUT;
            break;
        case BUTTON_SAS:
//BUTTON_SAS            SAS_PORT_TRIS = PIN_INPUT;
            break;
        case BUTTON_SB:
            SB_PORT_TRIS = PIN_INPUT;
            ANSELHbits.ANS8 = 0;    // Make RB5 pin digital
            break;
        case BUTTON_SC2:
            SC2_PORT_TRIS = PIN_INPUT;
            ANSELHbits.ANS9 = 0;    // Make RB5 pin digital
            break;
    }
}
