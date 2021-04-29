//Lesson 25 4桁7セグメントLED ダイナミック点灯方式を体感
//https://omoroya.com/

// 74HC595 pin        QA,QB,QC,QD,QE,QF,QG,QH 
// 7segment Mapping   a, b, c, d, e, f, g ,D.P

int tDelay = 500;   // 100ms遅延設定←ここの時間を短くしていく。
int srclkPin = 10;   // (10)  SH_CP [SRCLK] on 74HC595
int rclkPin = 11;   // (11) ST_CP [RCLK] on 74HC595
int dsPin = 12;     // (12) DS [SER] on 74HC595

int dig1 = 2;       // DIG1を1番ピンに割り当て
int dig2 = 3;       // DIG2を2番ピンに割り当て
int dig3 = 4;       // DIG3を3番ピンに割り当て
int dig4 = 5;       // DIG4を4番ピンに割り当て

// seven_ledsをbyte型として定義
// 配列にDisplay表示用のデータ0~9と全消灯を設定
// 1 = LED on, 0 = LED off
byte seven_leds[12] =       { B11111100,  // 0
                              B01100000,  // 1
                              B11011010,  // 2
                              B11110010,  // 3
                              B01100110,  // 4
                              B10110110,  // 5
                              B10111110,  // 6
                              B11100000,  // 7
                              B11111110,  // 8
                              B11100110,  // 9
                              B00000001,  // D.P 
                              B00000000,  // OFF
                             };

//シフトレジスタ部分を関数化
void funcShiftReg(int x)
{
  digitalWrite(rclkPin, LOW);                         //送信中のRCLKをLowにする
  shiftOut(dsPin, srclkPin, LSBFIRST, seven_leds[x]); //シフト演算を使って点灯するLEDを選択
  digitalWrite(rclkPin, HIGH);                        //送信終了後RCLKをHighにする
}
  
void setup() 
{
  pinMode(rclkPin, OUTPUT);   //11番ピンをOUTPUTとして定義
  pinMode(dsPin, OUTPUT);     //12番ピンをOUTPUTとして定義
  pinMode(srclkPin, OUTPUT);  //9番ピンをOUTPUTとして定義
  pinMode(dig1, OUTPUT);      //1番ピンをOUTPUTとして定義
  pinMode(dig2, OUTPUT);      //2番ピンをOUTPUTとして定義
  pinMode(dig3, OUTPUT);      //3番ピンをOUTPUTとして定義
  pinMode(dig4, OUTPUT);      //4番ピンをOUTPUTとして定義
  digitalWrite(dig1, HIGH);    //1番ピンをHIGH DI1 OFF
  digitalWrite(dig2, HIGH);    //2番ピンをHIGH DI2 OFF
  digitalWrite(dig3, HIGH);    //3番ピンをHIGH DI3 OFF
  digitalWrite(dig4, HIGH);    //4番ピンをHIGH DI4 OFF
  funcShiftReg(11);           //信号初期化
}

void loop() 
{
  //DIG1の表示
  delay(tDelay);
  digitalWrite(dig1, LOW); 
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
  //DIG1に1を表示
  funcShiftReg(1);
  delay(tDelay);
  funcShiftReg(11);

  
  //DIG2の表示
  delay(tDelay);
  digitalWrite(dig1, HIGH); 
  digitalWrite(dig2, LOW);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
  //DIG2に2を表示
  funcShiftReg(2);
  delay(tDelay);
  funcShiftReg(11);


  //DIG3の表示
  delay(tDelay);
  digitalWrite(dig1, HIGH); 
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, LOW);
  digitalWrite(dig4, HIGH);
  //DIG3に3を表示
  funcShiftReg(3);
  delay(tDelay);
  funcShiftReg(11);


  //DIG4の表示
  delay(tDelay);
  digitalWrite(dig1, HIGH); 
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, LOW);
  //DIG4に4を表示
  funcShiftReg(4);
  delay(tDelay);
  funcShiftReg(11);
}
