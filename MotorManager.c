//This manages the Relay for the DC engines and the Pneumatiek.
#include "MotorManager.h"
void motor1Right(){
   output_bit( PIN_B5, 0);
   output_bit( PIN_B4, 1);//motor 1 Rechtsom
}

void motor1Off(){
   output_bit( PIN_B5, 0);
   output_bit( PIN_B4, 0);// motor 1 stoppen
}

void motor1Left(){
   output_bit( PIN_B4, 0);
   output_bit( PIN_B5, 1);//motor 1 Linksom
}

void motor2Right(){
   output_bit( PIN_C5, 0);
   output_bit( PIN_C4, 1);//motor 2 Rechtsom
}

void motor2Off(){
   output_bit( PIN_C4, 0);
   output_bit( PIN_C5, 0);//motor 1 stoppen
}

void motor2Left(){
   output_bit( PIN_C4, 0);
   output_bit( PIN_C5, 1);//motor 2 Linksom
}  

void pneumatiekOn(){
   output_bit( PIN_A2, 1);//hydraulish systeem aan
}

void pneumatiekOff(){
   output_bit( PIN_A2, 0);//hydraulish systeem stoppen
}
