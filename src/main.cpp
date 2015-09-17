// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <Arduino.h>
#define VEL (5000)

int motor_left[] = {5, 6};
int motor_right[] = {10, 11};
int izq;
int der;
int flag = 0;

void drive_forward();
void drive_backward();
void encizq();
void encder();
void cambia();

void setup() {

    Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(2), encizq, CHANGE); 
    attachInterrupt(digitalPinToInterrupt(3), encder, CHANGE); 

  int i;
  for (i = 0; i < 2; i++) {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
  drive_forward();
}

void loop() {
    if (izq >= 40){
        cambia();
        izq = 0;
    }
}

void cambia(){
    flag = !flag;
    if (flag){
        drive_forward();
    }else{
        drive_backward();
    }
}

void encizq(){
    izq++;
}
void encder(){
    der++;
}


void drive_forward() {
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_left[1], LOW);

  digitalWrite(motor_right[0], HIGH);
  digitalWrite(motor_right[1], LOW);
}

void drive_backward() {
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], HIGH);

  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], HIGH);
}
