#include "XbeeRobo.h"

XbeeRobo::XbeeRobo()
{
    velocidadeY = 0;
    velocidadeX = 0;
    velAng = 0;
    queue = NULL;
}

void XbeeRobo::receberRS232()
{
    int i, siz;
    siz = Serial.available();
    if(siz>0)
    {
        for(i=0; i<siz; i++)
        {
            queue = queue->addByte(Serial.read(), queue);
        }
    }
}

int XbeeRobo::atualizarBuffer()
{
    unsigned char byte_entrada[12];
    int i;
    while(queue!=NULL&&queue->getByte()!=0xa0)
    {
        queue = queue->removeByte(queue);
    }
    if(queue!=NULL&&queue->getByte()==0xa0&&queue->getSize()>12)
    {
        for(i=0; i<12; i++)
        {
            queue = queue->removeByte(queue);
            byte_entrada[i] = queue->getByte();
        }
        velocidadeX = *(float*)&byte_entrada[0];            
        velocidadeY = *(float*)&byte_entrada[4];
        velAng = *(float*)&byte_entrada[8];
    }
    if(queue!=NULL&&queue->getSize()>13)
    {
        return 0;
    }
    return 1;
}

float XbeeRobo::getVelY()
{
    return velocidadeY;
}

float XbeeRobo::getVelX()
{
    return velocidadeX;
}
float XbeeRobo::getVelAng()
{
    return velAng;
}

