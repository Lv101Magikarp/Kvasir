//Este programa tem por objetivo captar as informacoes recebidas da porta serial e transmití-las aos receptores

#include "Principal.h"
#include <printf.h>

void setup()
{
  //--Sets
     Serial1.begin(BDRATE);
     Serial.begin(BDRATE);
     printf_begin();
     Principal principal = Principal();
     principal.PrincipalStart();
}

void loop() {}
