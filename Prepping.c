//This manages the Prepping before the start.
#include "Prepping.h"
#use delay(clock=8867238)

int prep = 0;
int LichtGatenPomp = 0;

void prepping()
{
   output_bit(PIN_C1, 1);//Rood
   output_bit(PIN_C0, 0);//Groen
   pneumatiekOff();
   prep = 1;
   delay_ms(500);
   motor1Left();
   delay_ms(10000);
   while(input(PIN_A4)) {}
   motor1Off();
   delay_ms(200);
   pneumatiekOn();
   delay_ms(100);
   pneumatiekOff();
   prep = 0;
   output_bit(PIN_C1, 0);//Rood
   output_bit(PIN_C0, 1);//Groen
}

void fill()
{ 
   motor1Left();
   LichtGatenPomp = 0;
   while(LichtGatenPomp < 4)
   {
      motor1Left();
      if(input(PIN_A4))
      {
         LichtGatenPomp++;
         delay_ms(500);
      }
   }
   motor1Off();
   delay_ms(100);
}
