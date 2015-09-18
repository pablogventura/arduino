#include "motor.h"


unsigned long vIzq = 0;
unsigned long vDer = 0;

Motor::Motor(byte pinForward, byte pinBackward, byte pinEncoder){
    minpulse = 0;
    pinF=pinForward;
    pinB=pinBackward;
    pinE=pinEncoder;
    pinMode(pinF, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinE, INPUT);
    stop();
}
void Motor::internalRun(int velocidad){
    if (abs(velocidad) <= minpulse){
        stop();
        return;
    }
    if (velocidad > 255){
        velocidad = 255;
    }
    if (velocidad < -255){
        velocidad = -255;
    }
        
    if (velocidad >= 0){
        sentido = FORWARD;
        pulse = velocidad;
        analogWrite(pinF, pulse);
        digitalWrite(pinB, LOW);
    }else{
        sentido = BACKWARD;
        pulse = -velocidad;
        digitalWrite(pinF, LOW);
        analogWrite(pinB, pulse);
    }
}
void Motor::run(int velocidad){
    if (velocidad == 0 || abs(velocidad) <= minpulse){
        stop();
        return;
    }
    if (pulse == 0){
        if (velocidad > 0){
            internalRun(255);
            delay(10);
        }else{
            internalRun(-255);
            delay(10);
        }
    }
    internalRun(velocidad);
}
    
        
unsigned long Motor::timeToLine(){
    unsigned long result = pulseIn(pinE,HIGH,50000);
    while (result < 1000 && result != 0){
        result = pulseIn(pinE,HIGH,50000);
    }
    if (result == 0)
        minpulse = max(pulse,minpulse);
    return result;
}

int Motor::rps(){
    int result = 50000/timeToLine();
    return result;
}

void Motor::stop(){
    pulse = 0;
    digitalWrite(pinF, LOW);
    digitalWrite(pinB, LOW);
}

void Motor::calibrate(){
    stop();
    int cvel = -255;
    Serial.begin(9600);
    for (cvel = -255;cvel <=255;cvel++){
        Serial.print(cvel);
        Serial.print(" ,");
        Serial.println(timeToLine());
        delay(100);
        run(cvel);
        cvel++;
    }
    stop();
}
