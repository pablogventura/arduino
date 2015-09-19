#ifndef __MOTORES_H__
#define __MOTORES_H__

#include "Arduino.h"
#include "motor.h"
#define BACKWARD 0
#define FORWARD  1
#define TURN     2
#define STOP     3

void initMotores();

void stopMotores();

void runMotores(int vel, int dist);

void turnMotores(int degrees);

void lineIzq();
void lineDer();
#endif
