// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <Arduino.h>
#include "motor.h"
#define VEL (5000)


Motor mIzq = Motor(5, 6, 2);
Motor mDer = Motor(10, 11, 3);
void setup() {

    Serial.begin(9600);
    mIzq.calibrate();
    mDer.calibrate();
}

void loop() {


}
