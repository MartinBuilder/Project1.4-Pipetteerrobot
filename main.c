#include <16F877A.h>
#include "MotorManager.h"
#include "MotorManager.c"
#include "Prepping.h"
#include "Prepping.c"
#include "Interface.h"
#include "Interface.c"
#use delay(clock=8867238)
#fuses HS,NOWDT
//int HoeVaakGedrukt;
long delay;

#int_CCP1
TCCP1_isr()
{
   CCP_1 = CCP_1 + 44336;      //increment compare counter 8.867238Mhz/4  =  2.2168095 Mhz
   // tijd per puls is 1 / 2216809  = 0,45 microsec  (   44336 * 0,45 microsec = 20 milliseconden
   output_bit(PIN_D0, 1);  //output bit to pin

   if (prep == 1){
   for (delay = 0; delay <361; delay++);
   output_bit(PIN_D0,0); 
   }
   
   if (prep == 0){
   for (delay = 0; delay <230; delay++);
    output_bit(PIN_D0,0);
   }
}

void main()
{
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1); //timer1 enabled, instruction clock / 1
   setup_ccp1(CCP_COMPARE_INT); //set CCP1 to cause an interrupt on match
   enable_interrupts(INT_CCP1);  //unmask Timer2 match interrupt
   enable_interrupts(global);    //enabled all unmasked interrupts
  
   if(TRUE) ScanBlack();
   //output_a(0x00);
   //output_b(0x00);
   
   /*while(TRUE)
   {
      //prep = 0;
      //delay_ms(5000);
      //prep = 1;
      if(input(PIN_A1))
      {
         HoeVaakGedrukt++;
         if(HoeVaakGedrukt == 0)
         {
            prepping();
         }
         else if(HoeVaakGedrukt == 1)
         {
            // voer functie hoofprogramma uit
            HoeVaakGedrukt = 0;
         }
         delay_ms(1000);
      }
   }*/
}

