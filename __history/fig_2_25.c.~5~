#include <16F877.h>
#use delay(clock=8000000)
#fuses HS,NOWDT
int outs = 1;//preset to start process
long delay ;

void motor1R()
{
output_bit( PIN_RB4, 0);
output_bit( PIN_RB5, 0);
output_bit( PIN_RB4, 1);//motor 1 Rechtsom
}

void motor1uit()
{
output_bit( PIN_RB5, 0);
output_bit( PIN_RB4, 0);// motor 1 stoppen
delay_ms(3);
}

void motor1L()
{
output_bit( PIN_RB4, 0);
output_bit( PIN_RB5, 0);
output_bit( PIN_RB5, 1);//motor 1 Linksom
}

void motor2R()
{
output_bit( PIN_RC4, 0);
output_bit( PIN_RC5, 0);
output_bit( PIN_RC4, 1);//motor 2 Rechtsom
}

void motor2uit()
{
output_bit( PIN_RC4, 0);
output_bit( PIN_RC5, 0);//motor 1 stoppen
delay_ms(3);
}

void motor2L()
{
output_bit( PIN_RC4, 0);
output_bit( PIN_RC5, 0);
output_bit( PIN_RC5, 1);//motor 2 Linksom
}  

#int_CCP1
TCCP1_isr()
{
   CCP_1 = CCP_1 + 40000;      //increment compare cpounter 8Mhz/4  =  2 Mhz
                               // tijd per puls is 1 / 2000000 = 0,5 microsec (400000 * 0,5 microsec = 20 milliseconden)
   output_bit(PIN_D0, 1);      //output bit to pin
   output_bit(PIN_D1, 1);      //output bit to pin
   for (delay = 0; delay <200; delay++);
   output_bit(PIN_D0,0);  
   for (delay = 0; delay <100; delay++);
   output_bit(PIN_D1,0);
}

void main()
{
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1); //timer1 enabled, instruction clock / 1
   setup_ccp1(CCP_COMPARE_INT);            //set CCP1 to cause an interrupt on match
   enable_interrupts(INT_CCP1);            //unmask Timer2 match interrupt
   enable_interrupts(global);              //enabled all unmasked interrupts
   
   while(1)
   {
      motor1R ();
      delay_ms(2000);
      motor1uit();
      delay_ms(1000);     
         
      motor1L ();
      delay_ms(2000);
      motor1uit();
      delay_ms(1000);  
      
      motor2R ();
      delay_ms(2000);
      motor2uit();
      delay_ms(1000);    
         
      motor2L ();
      delay_ms(2000);
      motor2uit();
      delay_ms(1000);
   }

}
