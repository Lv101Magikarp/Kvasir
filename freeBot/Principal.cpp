#include "Principal.h"

void PrincipalStart()
{
<<<<<<< HEAD
	   Hardware hardware = Hardware();//--Corpo do Robo
=======
     Hardware hardware = Hardware();//--Corpo do Robo
>>>>>>> cb7f1da065620fe6ff221ce749a10261c0cfc086
     Software software = Software();//--Estrategia do Robo
     EspinhaDorsal espinhaDorsal = EspinhaDorsal();//--Comunicação das princiopais classes
	   //--O metodo espinha dorsal eh dividido em dois
        //--1) O metodo sem atributos retorna o ponteiro de uma classe chamada EspinhaDorsal
      //--2) O metodo que recebe  atriutos recebe o ponteiro de uma classe  chamada EspinhaDorsal
     //--A EspinhaDorsal ira realizar a comunicacao entre Estrategia e Eletronica.

     while(1)
     {
            hardware.atualizar(&espinhaDorsal);//--Verifica e modifica dados novos no hardware
            software.atualizar(&espinhaDorsal);//--Verifica e modifica dados novos na Estrategia

             //Serial.println("cheguei no delay");
             //a++;
             //if(a==100)
             //{
              //Serial.println("1 segundo");
              //a=0;
             //}



            //else
              //  Serial.println(aux);
            delay(10);
     }
     /* Caso se resolva desligar o arduino de alguma maneira
     delete hardware;
     delete software;
     delete espinhaDorsal;
     */
}
