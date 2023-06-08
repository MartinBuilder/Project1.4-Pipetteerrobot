#include <16F877A.h>
#include "MotorManager.h"
#include "MotorManager.c"
#use delay(clock=8867238)
#fuses HS,NOWDT

void main(void){
   while(1){
      motor1Right();
      delay_ms(2000);
      motor1Off();
      delay_ms(1000);     
         
      motor1Left();
      delay_ms(2000);
      motor1Off();
      delay_ms(1000);  
      
      motor2Right();
      delay_ms(2000);
      motor2Off();
      delay_ms(1000);    
         
      motor2Left();
      delay_ms(2000);
      motor2Off();
      delay_ms(1000);
      
      pneumatiekOn();
      delay_ms(2000);
      pneumatiekOff();
      delay_ms(1000);
   }
}
