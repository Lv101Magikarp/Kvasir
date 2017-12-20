#include "ServoRotativo.h"

ServoRotativo::ServoRotativo(int _pinoPWM, float _velocidadeMaxima, int _velAjuste)
{
    pinoPWM = _pinoPWM;
    velAjuste = _velAjuste;
    velocidadeMaxima = _velocidadeMaxima;
    servo.attach(pinoPWM);
    servo.write(velAjuste);//--Manda iniciar com o motor parado
}

void ServoRotativo::setVelocidade(float velocidade)
{
    float angulo;
    angulo = (velocidade*90)/velocidadeMaxima;
    if(velocidade==0)
    {
        servo.detach();
    }
    else
    {
        servo.attach(pinoPWM);
        servo.write(angulo + velAjuste);//--sentido horário se angulo é positivo ou ~
    }
}

float ServoRotativo::getVelAjuste()
{
    return velAjuste;
}


