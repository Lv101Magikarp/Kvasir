#ifndef _MOVIMENTACAO_H_
#define _MOVIMENTACAO_H_

#include <math.h>
#include "BotConstantes.h"
#include "ServoRotativo.h"

struct VelocidadeDosMotores{
    float motor1;
    float motor2;
    float motor3;
    float motor4;
};

class Movimentacao{
private:
    ServoRotativo* motor1;
    ServoRotativo* motor2;
    ServoRotativo* motor3;
    ServoRotativo* motor4;

    void calculo(float velX, float velY, float w);
    VelocidadeDosMotores velocidade;

public:
    Movimentacao();
    ~Movimentacao() {};
    void mover(float velX, float velY, float w);


};
#endif

