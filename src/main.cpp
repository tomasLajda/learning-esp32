#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C address is 0x27
int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  lcd.init();
  lcd.backlight();
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear(); 
}