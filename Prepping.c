//This manages the Prepping before the start.
#include "Prepping.h"
#use delay(clock=8867238)

int prep = 0;

void prepping()
{
   prep = 1;
   delay_ms(500);
   if(TRUE) motor1Left();
   delay_ms(10000);
   if(TRUE) motor1Off();
   delay_ms(500);
   prep = 0;
   delay_ms(2000);
}
