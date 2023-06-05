#include <main.h>
#include <16F877A.h>
#use delay(clock=8867238)
#fuses HS,NOWDT
int outs = 1;  //preset to start process
long delay;

void main()
{
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1); //timer1 enabled, instruction clock / 1
   setup_ccp1(CCP_COMPARE_INT); //set CCP1 to cause an interrupt on match
   enable_interrupts(INT_CCP1);  //unmask Timer2 match interrupt
   enable_interrupts(global);    //enabled all unmasked interrupts
   
   while(TRUE)
   {
      delay_ms(2000);
      output_bit( PIN_C2, 0);     
      output_bit( PIN_C3, 0);
      delay_ms(2000);
      output_bit( PIN_C2, 1);     
      output_bit( PIN_C3, 1);
   }
}
