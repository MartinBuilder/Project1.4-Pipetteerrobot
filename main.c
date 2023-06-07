#include <16F877.h>
#use delay(clock=8000000)
#fuses HS,NOWDT

void motor1R(){
   output_bit( PIN_B5, 0);
   output_bit( PIN_B4, 1);//motor 1 Rechtsom
}

void motor1uit(){
   output_bit( PIN_B5, 0);
   output_bit( PIN_B4, 0);// motor 1 stoppen
}

void motor1L(){
   output_bit( PIN_B4, 0);
   output_bit( PIN_B5, 1);//motor 1 Linksom
}

void motor2R(){
   output_bit( PIN_C5, 0);
   output_bit( PIN_C4, 1);//motor 2 Rechtsom
}

void motor2uit(){
   output_bit( PIN_C4, 0);
   output_bit( PIN_C5, 0);//motor 1 stoppen
}

void motor2L(){
   output_bit( PIN_C4, 0);
   output_bit( PIN_C5, 1);//motor 2 Linksom
}  

void hydrauliekAan(){
   output_bit( PIN_A4, 1);//hydraulish systeem aan
}

void hydrauliekUit(){
   output_bit( PIN_A5, 0);//hydraulish systeem stoppen
}

void main(){
   while(1){
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
      
      hydrauliekAan();
      delay_ms(2000);
      hydrauliekUit();
      delay_ms(1000);
   }
}
