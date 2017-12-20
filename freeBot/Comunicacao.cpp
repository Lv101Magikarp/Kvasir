#include "Comunicacao.h"

Comunicacao::Comunicacao()
{
    radio = new XbeeRobo();
}

void Comunicacao::aguardarDados()
{
    int fim;
    if(ATIVAR_TESTE == 0)
    {
        radio->receberRS232();
        fim = radio->atualizarBuffer();
        while(fim==0)
        {
            velocidadeEixoX = radio->getVelX();
            velocidadeEixoY = radio->getVelY();
            velAng = radio->getVelAng();
            fim = radio->atualizarBuffer();
        }
        velocidadeEixoX = radio->getVelX();
        velocidadeEixoY = radio->getVelY();
        velAng = radio->getVelAng();
    }
    else
    {
        velocidadeEixoX = VELOCIDADE_MAXIMA;
        velocidadeEixoY = VELOCIDADE_MAXIMA;
        velAng=0;
    }
}

float Comunicacao::getVelocidadeEixoX()
{
    return velocidadeEixoX;
}

float Comunicacao::getVelocidadeEixoY()
{
    return velocidadeEixoY;
}

float Comunicacao::getVelocidadeAng()
{
    return velAng;
}

