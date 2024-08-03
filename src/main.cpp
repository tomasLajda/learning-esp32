#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>

#include "config.h"

const byte LedPin = 4;
const byte MotionPin = 5;

const byte LcdAddress = 0x27;
const byte LcdRows = 2;
const byte LcdColumns = 16;

LiquidCrystal_I2C lcd(LcdAddress, LcdColumns, LcdRows);

void setup() {
  Serial.begin(115200);
  pinMode(LedPin, OUTPUT);
  pinMode(MotionPin, INPUT);

  lcd.init();
  lcd.backlight();

  Serial.println("Starting WiFi connection...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(300);
  }

  Serial.print("Connected With Ip: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.clear();

  if (digitalRead(MotionPin) == HIGH) {
    lcd.print("Motion detected");
    digitalWrite(LedPin, HIGH);
    Serial.println("High");
  } else {
    lcd.print("No motion.");
    digitalWrite(LedPin, LOW);
    Serial.println("LOW");
  }

  delay(500);
}