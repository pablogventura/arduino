#include "motores.h"
#include "motor.h"
#include <Arduino.h>

int Motores::odoIzq = 0;
int Motores::odoDer = 0;

Motores::Motores(byte pinFi, byte pinBi, byte pinEi,byte pinFd, byte pinBd, byte pinEd){
    mIzq = Motor(pinFi,pinBi,pinEi);
    attachInterrupt(digitalPinToInterrupt(2), lineIzq, FALLING);
    mDer = Motor(pinFd,pinBd,pinEd);
    attachInterrupt(digitalPinToInterrupt(3), lineDer, FALLING);
    stop();
}

void Motores::stop(){
    mIzq.stop();
    mDer.stop();
}

void Motores::run(int vel, int distCM){
    int dist = distCM * 2.71;
    mIzq.run(vel);
    mDer.run(vel);
    while ((Motores::odoIzq + Motores::odoDer)/2 < dist){
        delay(1); // hay que poner algo sino el compilador saca todo el while
    }
    stop();
}
void Motores::turn(int degrees){
    mIzq.run(255);
    mDer.run(-255);
}
void Motores::lineIzq(){
    odoIzq++;
}
void Motores::lineDer(){
    odoDer++;
}
