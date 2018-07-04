#include "ArduinoLibrary.h"
#include "ServerCommunication.h"
#include "function.h"
#include "constants.h"
#include "System.h"

extern Servo servo;

void rotateServo( SINT servo_angle )
{
  digitalWrite(LED_PIN, HIGH);
  servo.write(servo_angle);
  delay(1000);
}

void bip ( void )
{
  tone(BUZ_PIN,1000);
  delay(100);
  noTone(BUZ_PIN);
  digitalWrite(LED_PIN,LOW);
}
