#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C address is 0x27
int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

String messageStatic = "Static message";
String messageToScroll = "This is a scrolling message with more than 16 characters";

void scrollMessage(int row, String message, int delayTime, int lcdColumns) {
  for (int i = 0; i < lcdColumns; ++i) {
    message = " " + message;  
  } 
  message = message + " "; 

  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

void setup(){
  lcd.init();                    
  lcd.backlight();
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print(messageStatic);
  
  scrollMessage(1, messageToScroll, 250, lcdColumns);
}