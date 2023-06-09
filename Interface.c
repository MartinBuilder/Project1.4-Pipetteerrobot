#include "Interface.h"
#use delay(clock=8867238)

int HoeVaakGedrukt = 0;

void ScanBlack()
{
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
}
