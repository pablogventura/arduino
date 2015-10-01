// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <Arduino.h>
#include "motores.h"
#define VEL (5000)

void setup() {

    Serial.begin(9600);
    //mIzq.calibrate();
    //mDer.calibrate();
    initMotores();
    
   
}

void loop() {
    turnMotores(90);
    waitMotores();
    runMotores(100,120);
    waitMotores();
    runMotores(-100,120);
    waitMotores();
    //TODO ACA TODO SE REPITE
}
