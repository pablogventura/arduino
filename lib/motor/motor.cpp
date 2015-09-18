#include "motor.h"


unsigned long vIzq = 0;
unsigned long vDer = 0;

Motor::Motor(byte pinForward, byte pinBackward, byte pinEncoder){
    pinF=pinForward;
    pinB=pinBackward;
    pinE=pinEncoder;
    pinMode(pinF, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinE, INPUT);
    stop();
    if (pinE == 2){
        //izquierdo
        attachInterrupt(digitalPinToInterrupt(pinE), &encoder2Line, CHANGE);
    } else if (pinE == 3){
        attachInterrupt(digitalPinToInterrupt(pinE), &encoder3Line, CHANGE);
    }
}
void Motor::run(int velocidad){
    if (velocidad >= 0){
        analogWrite(pinF, velocidad);
        digitalWrite(pinB, LOW);
    }else{
        analogWrite(pinF, LOW);
        digitalWrite(pinB, -velocidad);
    }
}
unsigned long Motor::vel(){
    unsigned long result;
    if (pinE == 2){
        //izquierdo
        result = vIzq;
    } else if (pinE == 3){
        result = vDer;
    }
    return result;
}
void Motor::encoder2Line(){
    static unsigned long time = millis();
    vIzq = time - millis();
    time = millis();    
}

void Motor::encoder3Line(){
    static unsigned long time = millis();
    vDer = time - millis();
    time = millis();    
}

void Motor::stop(){
    digitalWrite(pinF, LOW);
    digitalWrite(pinB, LOW);
}
