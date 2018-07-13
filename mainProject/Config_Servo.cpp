#include "ArduinoLibrary.h"
#include "ServerCommunication.h"
#include "function.h"
#include "constants.h"
#include "System.h"

extern Servo servo;

void rotateServo( SINT servo_angle )
{
  servo.write(servo_angle);
  delay(1000);
}

void apBlink()
{
  for(int i = 0; i < 4; i++){
    digitalWrite(LED_PIN, HIGH);/* LED ON      */
    delay(100);
    digitalWrite(LED_PIN, LOW); /* LED OFF     */
    delay(100);
  }
}

void runBlink()
{
  for(int i = 0; i < 4; i++){
    digitalWrite(LED_PIN, HIGH);/* LED ON      */
    delay(500);
    digitalWrite(LED_PIN, LOW); /* LED OFF     */
    delay(100);
  }
}
void regBlink()
{
  for(int i = 0; i < 2; i++){
    digitalWrite(LED_PIN, HIGH);/* LED ON      */
    delay(100);
    digitalWrite(LED_PIN, LOW); /* LED OFF     */
    delay(100);
  }
}
