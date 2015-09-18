#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "Arduino.h"
#define FORWARD  1
#define BACKWARD 0

class Motor
{
private:

    byte pinF;
    byte pinB;
    byte pinE;
    byte pulse;
    byte sentido;
    unsigned long minvel;

public:

    // Constructores
    Motor(byte pinForward, byte pinBackward, byte pinEncoder);
    void stop(void);
    unsigned long vel();
    void run(int velocidad);
    void internalRun(int velocidad);

};
#endif
