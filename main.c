#include <main.h>
#include <16F877A.h>
#use delay(clock=8867238)
#fuses HS,NOWDT
int HoeVaakGedrukt;
int inputKnop;

void main()
{
   output_a(0x00);
   output_b(0x00);
   
   while(TRUE)
   {
      if(input(PIN_A1))
      {
         HoeVaakGedrukt++;
         if(HoeVaakGedrukt == 0)
         {
            output_b(0x10);
            // voer functie prep uit
         }
         else if(HoeVaakGedrukt == 1)
         {
            output_b(0x20);
            // voer functie hoofprogramma uit
            HoeVaakGedrukt = 0;
         }
         delay_ms(1000);
      }
   }
}

