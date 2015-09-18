#ifndef __MOTORES_H__
#define __MOTORES_H__

#include "Arduino.h"
#include "motor.h"
#define FORWARD  1
#define BACKWARD 0

class Motores
{
private:

    Motor mIzq;
    Motor mDer;

public:
    static int odoIzq;
    static int odoDer;

    // Constructores
    Motores(byte pinFi, byte pinBi, byte pinEi,byte pinFd, byte pinBd, byte pinEd);
    void stop(void);
    void run(int vel, int distCM);
    void turn(int degrees);
    static void lineIzq();
    static void lineDer();
};
#endif
