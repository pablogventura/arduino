// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <Arduino.h>
#include "motores.h"
#define VEL (5000)


Motores motores = Motores(5, 6, 2, 10, 11, 3);
void setup() {

    Serial.begin(9600);
    //mIzq.calibrate();
    //mDer.calibrate();
    motores.run(255,100);
}

void loop() {
    //TODO ACA TODO SE REPITE
}
