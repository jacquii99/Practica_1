
#include "lib/include.h"

unsigned long Led;
volatile uint32_t ui32Loop;
volatile uint32_t valor;
int main() 
{   
  Configurar_GPIO(); 

    while((SYSCTL->PRGPIO&0x00000100) == 0){;} // allow time for clock to stabilize
    ui32Loop = SYSCTL->RCGCGPIO;
    Led= 0x01; 
    GPIOF_AHB -> DATA =Led; 
    Delay();
      Led= 0x02; 
    GPIOF_AHB -> DATA =Led; 
    Delay();
      Led= 0x04; 
    GPIOF_AHB -> DATA =Led; 
    Delay();
      Led= 0x0A; 
    GPIOF_AHB -> DATA =Led; 
    Delay();
    
  /*Super micros*/
/*esto es una actualizacion*/
 valor=200000;
  while (1U)
  {
        //
        // Turn on the LED.
        //
         GPION->DATA |= 0x02 | 0x01;

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < valor; ui32Loop++)
        {
        }
         GPION->DATA |= 0x02 | 0x01;
        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < valor; ui32Loop++)
        {
        }
        //
        // Turn off the LED.
        //
        GPION->DATA &= ~(0x02 |0x01);

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < valor; ui32Loop++)
        {
        }
                GPION->DATA &= ~(0x02 | 0x01);

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < valor; ui32Loop++)
        {
        }
  }
}