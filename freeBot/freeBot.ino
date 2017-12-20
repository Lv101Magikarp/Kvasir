#include "Principal.h"

void setup() 
{
  //--Sets
     Serial.begin(57600);
     pinMode(MOTOR1_PINO, OUTPUT);
     pinMode(MOTOR2_PINO, OUTPUT);
     pinMode(MOTOR3_PINO, OUTPUT);
     pinMode(MOTOR4_PINO, OUTPUT);
     PrincipalStart();
}

void loop() {}

