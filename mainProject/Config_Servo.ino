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
