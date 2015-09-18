// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <Arduino.h>
#include "motor.h"
#define VEL (5000)


Motor mIzq = Motor(5, 6, 2);

int vel = -255;


void setup() {

    Serial.begin(9600);
}

void loop() {

    Serial.print(vel);
    Serial.print(" ,");
    Serial.println(mIzq.vel());
    delay(100);
    mIzq.run(vel);
    vel++;

}
