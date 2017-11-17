#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

class Constantes{
public:
    const float VELOCIDADE_MAXIMA = 0.3; //--Velocidade Máxima atingida pelo motor + roda
    //const int ATIVAR_CALIBRAGEM = 1; //--Comportamento do robo: (1)Calibragem, (0)Habilita os Motores à serem controlados
                                      //--PS: A calibragem DEVE SER realizada com o XBee desligado!!
                                      //---PS: Usar o programa auxiliar motors calibration
    const int ATIVAR_TESTE = 0; //--Ativa o modo teste: (0)Funcionamento Normal; (1)Modo Teste;
    const float pi = 3.1415926536;
    const int MOTOR1_VEL_AJUSTE = 109;
    const int MOTOR2_VEL_AJUSTE = 106;
    const int MOTOR3_VEL_AJUSTE = 95;
    const int MOTOR4_VEL_AJUSTE = 93;
    const float RAIO_ROBO = 0.0375; 
    const float ANG = 0;//rad
    
public:
      Constantes(){};
      ~Constantes(){};
};

class Pinagem{
  public:
  //--Motores
    //--Sinais PWM
     
      const int MOTOR1_PINO = 4;
      const int MOTOR2_PINO = 7;
      const int MOTOR3_PINO = 10;
      const int MOTOR4_PINO = 13;

    //--Sinais Analógicos
      //const int MOTOR1_AJUSTE = 0; //--A0
      //const int MOTOR2_AJUSTE = 1; //--A1
      //const int MOTOR3_AJUSTE = 2; //--A4
      //const int MOTOR4_AJUSTE = 3; //--A5

  public:
    Pinagem(){};
    ~Pinagem(){};
};

#endif
