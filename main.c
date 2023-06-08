#include <main.h>
#include <16F877A.h>
#use delay(clock=8867238)
#fuses HS,NOWDT
int HoeVaakGedrukt;
int inputKnop;

void main()
{

   set_tris_a (0xFF);
   set_tris_b (0x00);
   set_tris_c (0x0F);
   set_tris_d (0x00);
   
   output_bit(PIN_B4, 0);
   output_bit(PIN_B5, 0);
   
   while(TRUE)
   {
      inputKnop = input(PIN_A1);
      if(inputKnop == 1)
      {
      HoeVaakGedrukt++;
      if(HoeVaakGedrukt == 1)
      {
         output_bit(PIN_B4, 1);
         output_bit(PIN_B5, 0);
         // voer functie prep uit
      }
      if(HoeVaakGedrukt == 2)
      {
         output_bit(PIN_B5, 1);
         output_bit(PIN_B4, 0);
         // voer functie hoofprogramma uit
         HoeVaakGedrukt = 0;
      }
        
      
      }
   }
}

