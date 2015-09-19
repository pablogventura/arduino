#include "motores.h"
#include "motor.h"
#include <Arduino.h>

byte state = STOP;
int odoIzq = 0;
int odoDer = 0;
Motor mIzq = Motor(5, 6, 2);
Motor mDer = Motor(10, 11, 3);

void initMotores(){
    attachInterrupt(digitalPinToInterrupt(2), lineIzq, FALLING);
    attachInterrupt(digitalPinToInterrupt(3), lineDer, FALLING);
    stopMotores();
}

void stopMotores(){
    state = STOP;
    mIzq.stop();
    mDer.stop();
}

void runMotores(int vel, int dist){
    odoIzq = dist;
    odoDer = dist;
    mIzq.run(vel);
    mDer.run(vel);
}

void turnMotores(int degrees){
    int vel = 255;
    if (degrees < 0){
        vel=-vel;
        degrees = -degrees;
    }
    odoIzq = degrees;
    odoDer = degrees;
    mIzq.run(vel);
    mDer.run(-vel);
}

void lineIzq(){
    Serial.println("izq");
    if (odoIzq > 0){
        odoIzq--;
    } else {
        odoIzq = 0;    
        mIzq.stop();
    }
}
void lineDer(){
    Serial.println("der");
    if (odoDer > 0){
        odoDer--;
    } else {
        odoDer = 0;    
        mDer.stop();
    }
}
