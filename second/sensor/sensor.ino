#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;
int prevDist = 60;

void setup() {
  Serial.begin(9600);
  myDFPlayer.begin(Serial);
  delay(1);
  myDFPlayer.volume(30);
}

void loop() {
  delay (100);
  
  long distAns ;
  distAns = IDMread(3)  ;           // アナログピン3番のセンサーの値を読込む
  long distAns1 = map(distAns,0,1023,0,500) ; // 電圧値に変換する(0から5V)
  long distAns2 = map(distAns1,55,220,50,4) ;  // 電圧値から距離に変換する(0.55から2.2Vを50から4cmに)
  int distResult = distAns2;
   
  if (distResult < 11 && prevDist > 11) {
//    myDFPlayer.volume(30);
//    delay(1);
    myDFPlayer.play(1);
  }

  Serial.println(distResult);
  if (distResult <= 50) {
    prevDist = distResult;  
  }
}

// 赤外線測距モジュールから読み込む処理
int IDMread(int PinNo) {
  long distA ;
  int i ;
  distA = 0 ;
  for (i=0 ; i < 100; i++) {
    distA  = distA + analogRead(PinNo) ;   // アナログピンから読取る
  } 
  return distA / 100 ;                        // 100回の平均値を返す
}
