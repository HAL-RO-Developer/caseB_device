/*
    Main.ino
    システムメイン

    Created 2018/06/28
    By Nakajim Yam
*/
/* Include Files */
#include "ArduinoLibrary.h"
#include "ServerCommunication.h"
#include "function.h"
#include "constants.h"
#include "System.h"

Servo servo;          //Servo Lib
WiFiClient client;     //Wifi Instance
WIFICONFIG internet;

/* --- プロトタイプ宣言 --- */
void deviceInit( void );

void setup() 
{
  deviceInit();
  
  if(internet.device_id==NULL){
    Serial.println("testDevice1HEre");
    registerDevice();
  }
}

void loop()
{
  SINT servo_angle;
  if(digitalRead(APSWT) == LOW){
    //POST & PUT
    getAngle(servo_angle);
    //サーボを回転
    Serial.println("Done 1");
    rotateServo(servo_angle);
    //ブザーを鳴らす
    bip();
  }
  delay(100);
}

void deviceInit()
{
  /* シリアル通信 */
  Serial.begin(115200);
  Serial.println();
  /* ピン設定 */
  pinMode(APSWT, INPUT );    /* push Button */
  pinMode(LED_PIN, OUTPUT);  /* LED         */
  pinMode(BUZ_PIN, OUTPUT);  /* Buzzer      */
  digitalWrite(LED_PIN, LOW);/* LED OFF     */
  /* サーボモータ設定*/
  servo.attach(2);
  /* ファイルシステム */
  SPIFFS.begin();
  /* マイコンのモード設定 */
  Serial.println("wait 3second for AP button");
  Serial.println("Pushed = AP, Release = none");
  delay(3000); //ボタン待ち

  if(digitalRead(APSWT)==LOW){
    Serial.println("WiFi Settings");
    setupWifi();
  } 
  else if(digitalRead(APSWT)==HIGH) {
    connectRouter();
  }
}
