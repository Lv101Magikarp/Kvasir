#include "Hardware.h"

Hardware::Hardware()
{
    comunicacao = new Comunicacao();
    movimentacao = new Movimentacao();
}

void Hardware::atualizar(EspinhaDorsal *espinhaDorsal)
{
    int tempo, aux;
    tempo = 0; 
    aux = 0;
    //tempo = millis();
    comunicacao->aguardarDados();
    /*aux = millis()-tempo;
    Serial.print("tempo da Comunicacao ");
    Serial.println(aux);
    
    tempo = millis();*/
    espinhaDorsal->setRadioEixoX(comunicacao->getVelocidadeEixoX());//--Atualiza o campo na espinha dorsal
    espinhaDorsal->setRadioEixoY(comunicacao->getVelocidadeEixoY());//--Atualiza o campo na espinha dorsal
    espinhaDorsal->setRadioVelAng(comunicacao->getVelocidadeAng());

    movimentacao->mover(espinhaDorsal->getMovimentacaoEixoX(), espinhaDorsal->getMovimentacaoEixoY(), espinhaDorsal->getVelAng());
}
