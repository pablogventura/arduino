// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Arduino.h>
#define VEL (5000)

AF_DCMotor motorizq(1);
AF_DCMotor motorder(2);
int izq;
int der;
int vder;
int vizq;

void setup() {

    Serial.begin(9600);
    
    

    motorizq.run(FORWARD);
    motorizq.setSpeed(255);

    motorder.run(FORWARD);
    motorder.setSpeed(255);  
}

void loop() {  
    delay(100);
    pulseIn(9,LOW);
    der = abs(pulseIn(9,HIGH));
    
    pulseIn(10,LOW);
    izq= abs(pulseIn(10,HIGH));
    Serial.print("Der: ");
    Serial.println(der);
    Serial.print("Izq: ");
    Serial.println(izq);
    Serial.print("VDer: ");
    Serial.println(vder);
    Serial.print("VIzq: ");
    Serial.println(vizq);    
    if (izq > VEL){
        vizq=vizq-1;
    }
    if (izq < VEL){
        vizq=vizq+1;
    }
    if (der > VEL){
        vder=vder-1;
    }
    if (der < VEL){
        vder=vder+1;
    }
    
    if (vizq>255){

        vizq=255;
    }
    if (vder>255){

        vder=255;
    }    
    if (vizq<100){

        vizq=100;
    }
    if (vder<100){

        vder=100;
    }
    motorizq.setSpeed(vizq);
    motorder.setSpeed(vder);  
}
