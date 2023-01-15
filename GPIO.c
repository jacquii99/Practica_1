#include "lib/include.h"
extern void Configuar_GPIO(void)
{
    SYSCTL->RCGCGPIO |= (1<<12)|(1<<8)|(1<<5)|(1<<1); //habilitar puertos 
    SYSCTL->RCGCGPIO |= 0x1122;
    GPIOF_AHB ->AMSEL = 0x00;
    GPIOF_AHB-> PCTL = 0X00000000; 
    GPIOF_AHB -> DIR= 0x0E; // PF0 y PF4 
    GPION-> DIR = 0x03; //PN1 y PN2
    GPIOB_AHB -> DIR = 0x0F;//PB
    GPIOJ_AHB ->PUR = 0x11;//pull-up PF0 Y PF4 
    GPIOJ_AHB->DIR |= (0<<1)|(0<<0);//puerto J 
//Funciones alternativas
    GPIOB_AHB->AFSEL |= 0x00;
    GPIOJ_AHB->AFSEL |= 0x11;
    GPION->AFSEL |= 0x1F;
    GPIOF_AHB->AFSEL |= 0x00;
    GPIOF_AHB -> AFSEL= 0x00;
//GPIOCTL 
    GPIOB_AHB->PCTL |= 0x01;
    GPIOJ_AHB->PCTL |= 0x00;
    GPION->PCTL |= 0x01;
    GPIOF_AHB->PCTL |= 0x00;
    GPIOF_AHB -> DEN = (1<<12)|(1<<8)|(1<<5)|(1<<1);//habilita como digitales los puertos 

     //Salidas
   // GPIOB_AHB->DIR |= (1<<4);
   // GPIOF_AHB->DIR |= (1<<4) | (1<<0);
     //   GPION->DIR |= (1<<1) | (1<<0);
    //Entradas
    //GPIOJ_AHB->DIR |= (0<<1)|(0<<0);
    //GPIOJ_AHB->PUR  |= (1<<1)|(1<<0);//Estado alto
    //Funciones alternativas
    //GPIOB_AHB->AFSEL |= 0x00;
    //GPIOJ_AHB->AFSEL |= 0x11;
      //  GPION->AFSEL |= 0x1F;
    //GPIOF_AHB->AFSEL |= 0x00;
    //Tabla con GPIOCTL
    //GPIOB_AHB->PCTL |= 0x01;
   // GPIOJ_AHB->PCTL |= 0x00;
     //   GPION->PCTL |= 0x01;
    //GPIOF_AHB->PCTL |= 0x00;
    //Habilitarlos como digitales
    //GPIOB_AHB->DEN |= (1<<4);
   // GPIOJ_AHB->DEN |= (1<<1) | (1<<0);
     //   GPION->DEN |= (1<<1) | (1<<0);
   // GPIOF_AHB->DEN |= (1<<4) | (1<<0);
    //GPION->DIR  = 0x03; 
    //GPION->DEN  = 0x03;
}


extern void Delay (void)

{
  unsigned long volatile time;
  time = 1600000; 
  while(time)
  {
        time--;
  }
}