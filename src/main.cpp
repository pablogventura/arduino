// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Arduino.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {


  motor1.run(RELEASE);
    motor1.run(BACKWARD);
    motor1.setSpeed(255);
 
  motor2.run(RELEASE);
    motor2.run(FORWARD);
    motor2.setSpeed(255);  
}

void loop() {  


}
