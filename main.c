#include <main.h>
#include <16F877A.h>
#use delay(clock=8867238)
#fuses HS,NOWDT
int HoeVaakGedrukt;

void main()
{

   set_tris_a (0x07);
   set_tris_b (0x03);
   set_tris_c (0x0F);
   set_tris_d (0x00);
   
   while(TRUE)
   {
      if(input_b()==2)
      {
      HoeVaakGedrukt++;
      if(HoeVaakGedrukt == 1)
      {
         output_b(16);
         // voer functie prep uit
      }
      if(HoeVaakGedrukt == 2)
      {
         output_b(25);
         // voer functie hoofprogramma uit
      HoeVaakGedrukt = 0;
      }
        
      
      }
   }
}

