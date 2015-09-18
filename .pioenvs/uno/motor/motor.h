#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "Arduino.h"

class Motor
{
private:

    byte pinF;
    byte pinB;
    byte pinE;

public:

    // Constructores
    Motor(byte pinForward, byte pinBackward, byte pinEncoder);
    void stop(void);
    static void encoder2Line();
    static void encoder3Line();
    unsigned long vel();
    void run(int velocidad);
    

};
#endif
