#include <16F877A.h>
#include "MotorManager.h"
#include "MotorManager.c"
#include "Prepping.h"
#include "Prepping.c"
#use delay(clock=8867238)
#fuses HS,NOWDT
int LichtGaten;
long delay;

#int_CCP1
void TCCP1_isr(void)
{
   CCP_1 = CCP_1 + 44336;      //increment compare counter 8.867238Mhz/4  =  2.2168095 Mhz
   // tijd per puls is 1 / 2216809  = 0,45 microsec  (   44336 * 0,45 microsec = 20 milliseconden
   output_bit(PIN_D0, 1);  //output bit to pin

   if (prep == 1){
   if(!input(PIN_B1))
   {
      motor2Right();
   }
   else
   {
      motor2Off();
   }
   for (delay = 0; delay <360; delay++);
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
   setup_ccp1(CCP_COMPARE_INT);  //set CCP1 to cause an interrupt on match
   enable_interrupts(INT_CCP1);  //unmask Timer2 match interrupt
   enable_interrupts(global);    //enabled all unmasked interrupts
  
   output_a(0x00);
   output_c(0x00);
   
   while(TRUE)
   {
      if(input(PIN_C3))
      {
         prepping();
         LichtGaten = 0;
      }
      if(input(PIN_A1))
      {  
         LichtGaten = 0;
         While(!input(PIN_B1))
         {
            motor2Right();
         }
         motor2Off();
         while(LichtGaten < 8)
         {
            if(!input(PIN_A0))
            {
                  motor2Off();
                  motor1Left();
                  delay_ms(1000);
                  motor1Off();
                  pneumatiekOn();
                  delay_ms(200);
                  motor1Left();
                  delay_ms(1000);
                  motor1Off();
                  pneumatiekOff();
                  if(LichtGaten < 7)
                  {
                     motor2Left();
                     delay_ms(500);
                  }
                  else
                  {
                     While(!input(PIN_B1))
                     {
                        motor2Right();
                     }
                     motor2Off();
                  }
                  LichtGaten++;
               }
            }
         }
         delay_ms(500);
      }
}

