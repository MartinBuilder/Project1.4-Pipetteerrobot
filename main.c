//prepping

#include <16F877.h>
#use delay(clock=8867238)
#fuses HS,NOWDT
int outs = 1;  //preset to start process
long delay ;
#int_CCP1
TCCP1_isr()
{
   CCP_1 = CCP_1 + 44336;      //increment compare counter 8.867238Mhz/4  =  2.2168095 Mhz
 // tijd per puls is 1 / 2216809  = 0,45 microsec  (   44336 * 0,45 microsec = 20 milliseconden
   output_bit(PIN_D0, 1);  //output bit to pin
   output_bit(PIN_D1, 1);  //output bit to pin
   for (delay = 0; delay <361; delay++); // 361 voor onder pomp - 230 voor startpositie
    output_bit(PIN_D0,0);  
   for (delay = 0; delay <100; delay++);
    output_bit(PIN_D1,0);
}


void main()
{
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1); //timer1 enabled, instruction clock / 1
   setup_ccp1(CCP_COMPARE_INT); //set CCP1 to cause an interrupt on match
   enable_interrupts(INT_CCP1);  //unmask Timer2 match interrupt
   enable_interrupts(global);    //enabled all unmasked interrupts
   while(TRUE)
   {
   }
}

