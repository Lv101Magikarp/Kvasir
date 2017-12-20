#ifndef _SERVOROTATIVO_H__
#define _SERVOROTATIVO_H__

#include "VarSpeedServo.h"
#include "BotConstantes.h"

class ServoRotativo{
private:
    VarSpeedServo servo;
    int pinoPWM; //--pino que controla o motor
    float velocidadeMaxima; //--Velocidade Máxima que o conjunto motor+rodas atinge
    int velAjuste;

public:
    ServoRotativo(int _pinoPWM, float _velocidadeMaxima, int _VelAjuste);
    ~ServoRotativo() {};
    float getVelAjuste();
    void setVelocidade(float velocidadeIN);
    void setCalibragem();
};

#endif
