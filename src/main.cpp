#include <Arduino.h>
//#include "LiquidCrystal.h"

//#include <WiFi.h>
//#include "API.h"
//#include <ArduinoJson.h>
#include "measureing.h"

//LCD 
//LiquidCrystal lcd();


const char* ssid = "mohamed_Laptop";
const char* password = "mohamed202333";

//Your Domain name with URL path or IP address with path
#define ch1_volt 26
#define ch1_current 27
#define ch2_dc_volt 25
#define ch2_dc_current 14
#define ch2_ac_volt 12
#define ch2_ac_current 13

//channel1 volt,current-channel2 volt,current
//uint8_t channel_pins[26,]; 
String mac_add = "";
//task for channel1 measuring

//task for channel2 DC measuring
unsigned long currT,prevT,deltaT;
uint16_t measuring_timer = 3000;

void setup() {

  Serial.begin(115200);
  delay(1000);
  // connect to WiFi
  /*
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
*/
  // get device MacAddress
  Serial.print(" MAC address ");
  //mac_add= WiFi.macAddress();
  Serial.println(mac_add);
  
  //registerDevice(mac_add);
  //sendDeviceReadings(mac_add,1.011,50);

  

  analogReadResolution(12);
  //analogSetAttenuation(ADC_2_5db);
}

//hi from laptop
void loop() {

voltage = (analogRead(26) *3.3/4096);///0.0643;
current = (analogRead(27) *3.3/4096);///0.3;
Serial.print("c:");
Serial.println(current);
Serial.print("v:");
Serial.println(voltage);
delay(3000);
/*
currT = millis();

if(currT-prevT >= measuring_timer){
  deltaT =currT-prevT;
  //Measure_DC_Power(ch1_volt,ch1_current,deltaT);
  //sendDeviceReadings(mac_add,voltage,power);

voltage = (analogRead(ch1_volt) );//*3.3/4096)/0.0643;
current = (analogRead(ch1_current) );//*3.3/4096);///0.3;

power = current * voltage;
energy+= (power * deltaT);

Serial.print("c:");
Serial.println(current);
Serial.print("v:");
Serial.println(voltage);
Serial.print("p:");
Serial.println(power);
Serial.print("e:");
Serial.println(energy);
  prevT=currT;
}

*/
}
