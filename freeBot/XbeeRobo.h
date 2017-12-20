#ifndef _XBEEROBO_H_
#define _XBEEROBO_H_

#include <Arduino.h>
#include "BotConstantes.h"
#include "Buffer.h"

class XbeeRobo{
private:
    float velocidadeX;
    float velocidadeY;
    float velAng;
    Buffer* queue;
    
public:
    XbeeRobo();
    int atualizarBuffer();
    float getVelX();
    float getVelY();
    float getVelAng();
    void receberRS232();
    ~XbeeRobo() {};
};
#endif


