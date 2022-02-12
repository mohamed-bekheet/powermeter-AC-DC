#ifndef _LCD__H_
#define _LCD__H_
#include "Arduino.h"
#include <LiquidCrystal.h>
#include <Wire.h>

// LCD
#define rs 4
#define e 16
#define d4 17
#define d5 5
#define d6 18
#define d7 19
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void lcd_init(float voltage, float current, float power, float energy)
{
    lcd.begin(16, 2);
    lcd.setCursor(4, 0);
    lcd.print("Welcome!");
    lcd.setCursor(5, 1);
    lcd.print("ROBe2");
     delay(5000);
    lcd.setCursor(0, 0);
    lcd.print("V1:");
    lcd.print(voltage);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print("C1:");
    lcd.print(current);
    lcd.print(" ");

    lcd.setCursor(8, 0);
    lcd.print("P1:");
    lcd.print(power, 2);
    lcd.print(" ");
    lcd.setCursor(8, 1);
    lcd.print("E1:");
    lcd.print(energy);
    lcd.print(" ");
}

void lcd_update(float voltage, float current, float power, float energy)
{
    lcd.setCursor(0, 0);
    lcd.print("V1:");
    lcd.print(voltage);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print("C1:");
    lcd.print(current);
    lcd.print(" ");

    lcd.setCursor(8, 0);
    lcd.print("P1:");
    lcd.print(power, 2);
    lcd.print(" ");
    lcd.setCursor(8, 1);
    lcd.print("E1:");
    lcd.print(energy);
    lcd.print(" ");
}
void serial_readings(float volt, float current, float power, float energy)
{
  Serial.print("voltage : ");
  Serial.print(volt, 2);
  Serial.print(" V\t");
  Serial.print("Current : ");
  Serial.print(current, 2);
  Serial.print(" A\t");
  Serial.print("power : ");
  Serial.print(power, 2);
  Serial.print(" W\t");
  Serial.print("energy : ");
  Serial.print(energy, 2);
  Serial.print(" Wh\t");
  Serial.print("\n..............................\t\n");
}
#endif