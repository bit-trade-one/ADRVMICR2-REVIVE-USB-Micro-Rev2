# ファイルリスト

 - [Rev2](https://github.com/bit-trade-one/ADRVMICR2-REVIVE-USB-Micro-Rev2/raw/master/App/Rev2)
    - Revive_Micro_CT_Ex_v311.exe(通常版)
    - Revive_Micro_CT_Ex_v311en.exe(通常版・英語)
 - [Rev1](https://github.com/bit-trade-one/ADRVMICR2-REVIVE-USB-Micro-Rev2/raw/master/App/Rev1)
    - Revive_Micro_CT.exe(旧通常版(Rev2FW未対応))
    - Revive_Micro_CT_en.exe(old version(Rev2FW未対応)・英語)
 - [Matrix](https://github.com/bit-trade-one/ADRVMICR2-REVIVE-USB-Micro-Rev2/raw/master/App/Matrix)
    - Revive_Micro_MATRIX_CT.exe(マトリックス版)
    - Revive_Micro_MATRIX_CT_en.exe(マトリックス版・英語)
 - [iOS](https://github.com/bit-trade-one/ADRVMICR2-REVIVE-USB-Micro-Rev2/raw/master/App/iOS)
    - Revive_Micro_CT_v200.exe(iOS対応・通常版)
    - Revive_Micro_MATRIX_CT_v200.exe(iOS対応・マトリックス版)

### **Rev1/Rev2/Matrix版について**
**Rev2・Matrix版ではファームウェアレベルで改修を行い機能を追加しております。**  
**PC上の設定ツールと、REVIVE本体のFWのRevが異なる場合は設定ツールがREVIVEを認識できません。**  
**事前にファームの書き込みを行い、ツールとファームのRevを揃えてください。**

### **iOS版について**
**iOS版を使用する場合は、REVIVE Micro本体のファームウェアの書き換えが必要になります。**  
**iOS版はキーボードのみ対応となります。マウス・ジョイパッドについては設定は可能ですが動作しません。**  
**iOS版につきましては暫定対応となり、すべてのiOSバージョン/デバイスにおいて動作を保証するものではありません。**

# REVIVE USB MICRO Configuration Toolの使い方

## 1. 概要

ここでは、REVIVE USB MICROのピン設定ツール、REVIVE USB MICRO Configuration Toolの使い方を紹介します。  
REVIVE USB, Configuration Toolを用いると、各ピンに「マウス」「キーボード」「ジョイパッド」のキーを様々な組み合わせで登録する事が出来ます。  
Configuration Toolを用いて行った設定はREVIVE USBのチップの中に記憶されます。  
以後はConfiguration Toolを立ち上げる事無く動作します。（常駐ソフトも必要無し）  

## 2. 設定方法

### 2.1 REVIVE USB MICROの立ち上げ

REVIVE USB MICRO Configuration Toolを立ち上げ、REVIVE USB MICROを接続すると、自動的にデバイスが認識され、以下の様な画面となります。  
![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-1.png)  
デバイスが認識されていないと、以下の画面となります。  
![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-2.png)  
各画面の情報は以下のとおりです。  
![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-3.png)  
### 2.2 設定順序

設定は以下の順番で行ないます。  

    1. 設定するピンを選ぶ  
    2. デバイスタイプを選ぶ  
    3. 割当てを選ぶ  
    4. 「設定」ボタンを押す  

これを全てのピンに対して行っていきます。  

### 2.3 設定するピン番号の選択

まず、設定するピンを選びます。  
ピンは以下の選び方が出来ます。  
![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-4.png)  
### 2.4 デバイスタイプ／割当てを選択  

設定するピンを選んだ後、デバイスタイプ／割当てを選択します。  
デバイスタイプの選択はコンボボックスから行ないます。  

#### 2.4.1 マウス

マウスは以下の割当てから選ぶ事が出来ます。

 - 左クリック
 - 右クリック
 - ホイールクリック
 - 上移動
 - 下移動
 - 左移動
 - 右移動
 - ホイール上
 - ホイール下
 - カーソル速度変更

##### 2.4.1.1 左クリック

左クリックに割当てられたピンがONになると、マウスの左クリックが押されます。  

##### 2.4.1.2 右クリック

右クリックに割当てられたピンがONになると、マウスの右クリックが押されます。  

##### 2.4.1.3 ホイールクリック

ホイールクリックに割当てられたピンがONになると、マウスのホイール（真ん中ボタン）が押されます。  

##### 2.4.1.4 上移動／下移動／左移動／右移動

各移動に割当てられたピンがONになると、マウスカーソルが設定した方向に移動します。  
マウスカーソルのスピードは「移動速度」で設定出来ます。デフォルトは50で、1～255の範囲で設定し、値が小さい程カーソル速度は遅く、値が大きいほどカーソル速度は早くなります。  
![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-5.png)  

##### 2.4.1.5 ホイール上／ホイール下

各ホイールに割当てられたピンがONになると、マウスのホイールを上または下に回したのと同じ動作をします。  
ホイールの速度は「移動速度」で設定出来ます。デフォルトは50で、1～255の範囲で設定し、値が小さいほど、ホイール速度は遅く、値が大きいほどホイール速度は早くなります。  

##### 2.4.1.6 カーソル速度変更

カーソル速度変更に割当てられたピンがONになると、上移動／下移動／左移動／右移動のカーソル速度がこのピンに設定された値に変更されます。  
この変更は、このボタンが押されている間のみ、有効になります。  
01ピンにカーソル左移動を移動速度50で、02ピンにカーソル速度変更を移動速度100で設定すると、01ピンだけを押した場合には左に速度50で、02ピンを押しながら01ピンを押した場合には速度が100になります。  

#### 2.4.2 キーボード

割当てのCtrl／Shift／Alt／Winのチェックボックスにチェックを入れ、「ここに入力」の所でキーを入力し、設定すると、ピンにその動作が割当てられます。  
![](http://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-6.png)  
例えば、「CTRL + ALT + DEL」を設定したい場合には、[Ctrl]と[Alt]にチェックを入れ、「ここに入力」の所で「Delキー」を押し、「設定」を押します。  
そのピンがONになると、CTRL + ALT + DELが押されます。  

#### 2.4.3 ジョイパッド

レバー上下左右／ボタン1～12の中からそのピンに対応させたい物を選んでチェックを入れます。  
チェックを入れたもの全てが反応する様になります。  
例えば、「ボタン１」と「ボタン３」にチェックを入れた場合、そのピンをONにすると、「ボタン１／３」が同時におされます。  
![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-7.png)  

### 2.5 エンコーダ設定

拡張機能で、エンコーダ読み取り機能の設定ができます。  
読み取れるエンコーダはA/B2相タイプのものになります。  
隣り合う2ピンを一つのエンコーダに割り当てることができます。

![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-9.png)  

機能は回転方向ごとにそれぞれ割り当てられます。  
通常の機能設定と同様に設定してください。  
パルスが入力されるごとに、回転方向に応じて信号をPCに送出します。  

![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-10.png)  

*回転方向と機能の割り当てを逆にしたい場合は以下のどちらかを行ってください。*
 - ツール上でペアのピンのそれぞれに割り当てた機能を逆にする
 - エンコーダのA相/B相の結線を逆にする

### 2.6 チャタリング防止設定

拡張機能で、チャタリング防止のための複数時点検出機能の設定ができます。  
スイッチが一度ONになると、そのタイミングから"サンプリング周期\[ms\]"で設定した間隔ごとにスイッチの状態を確認します。  
連続で"一致検出回数"で設定した回数以上スイッチがONであることが確認されれば、そのピンに指定された信号をPCに送出します。  


![](https://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/RVMICR2-8.png)  


![](http://bit-trade-one.co.jp/wp/wp-content/uploads/2022/02/Anti-Chatter.png) 

