#ifndef _API_H
#define _API_H
#include "Arduino.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

/*
String postToserver(){
    HTTPClient http;
    String 
 // check if WiFi connected
 if(WiFi.status() == WL_CONNECTED) {
    http.begin("http://9ijjl9ilf7.execute-api.us-east-2.amazonaws.com/dev/registerDevice");
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST("{\"deviceMacAddress\":\""+deviceMacAddress+"\"}");
    Serial.print("responeCode:");
    Serial.println(httpResponseCode);
    Serial.println("successful post");
  }else {
    Serial.println("error connecting device to WiFi");  
  }
  http.end()

}
*/

const char* serverName = "http://9ijjl9ilf7.execute-api.us-east-2.amazonaws.com/dev/";

String api_key ="AKIAUKUACIUJPWPXRP67";
void registerDevice(String deviceMacAddress) {

 // this function is called only once when device is booted up
 // send POST request to this endpoint "https://9ijjl9ilf7.execute-api.us-east-2.amazonaws.com/dev/registerDevice" with deviceMacId as a BODY parameter
  HTTPClient http;

 // check if WiFi connected
 if(WiFi.status() == WL_CONNECTED) {
    http.begin("https://9ijjl9ilf7.execute-api.us-east-2.amazonaws.com/dev/registerDevice");
    
    http.addHeader("Content-Type", "application/json");
    //int httpResponseCode = http.POST("{\"deviceMacAddress\":\""+deviceMacAddress+"\"}");

    //WiFiClientSecure client;

    String strJson = "{\"deviceMacAddress\":\""+deviceMacAddress+"\"}";          
      // Send HTTP POST request
    int httpResponseCode = http.POST(strJson);
    Serial.print("responeCode:");
    Serial.println(httpResponseCode);
    Serial.print("responeMessage:");
    Serial.println(http.getString());
    Serial.println("successful post");
  }else {
    Serial.println("error connecting device to WiFi");  
  }
  http.end();
}

void sendDeviceReadings (String deviceMacAddress, float generatedPower, float consumedPower) {
  // this function is called each 5 seconds delay for sake of testing, real duration will be set on production
  // send POST request to this endpoint "https://9ijjl9ilf7.execute-api.us-east-2.amazonaws.com/dev/updateDeviceReadings" with deviceMacId, generatedPower, consumedPower as a BODY parameter
  // check if WiFi connected
  HTTPClient http;
  if(WiFi.status() == WL_CONNECTED) {
     http.begin("https://9ijjl9ilf7.execute-api.us-east-2.amazonaws.com/dev/updateDeviceReadings");
     http.addHeader("Content-Type", "application/json");
     int httpResponseCode = http.POST("{\"deviceMacAddress\":\""+deviceMacAddress+"\", \"generatedPower\":\""+generatedPower+"\",\"consumedPower\":\""+consumedPower+"\"}");
     Serial.print("respone:");
     Serial.println(httpResponseCode);
     Serial.println("successful post");
   }else {
     Serial.println("error connecting device to WiFi");  
   }

   http.end();
}
#endif