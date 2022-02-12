#ifndef _MEASURING_H_
#define _MEASURING_H_
#include "Arduino.h"
float current,voltage,power;
unsigned long energy = 0;
void initADC(void){

}

void Measure_DC_Power(uint8_t Pin_Volt,uint8_t Pin_current,char delta_t)
{
voltage = (analogRead(Pin_Volt) *3.3/4096)/0.0643;
current = (analogRead(Pin_current) *3.3/4096);///0.3;
power = current * voltage;
energy+= (power * delta_t); 
Serial.print("c:");
Serial.println(current);
Serial.print("v:");
Serial.println(voltage);
Serial.print("p:");
Serial.println(power);
Serial.print("e:");
Serial.println(energy);
}
#endif