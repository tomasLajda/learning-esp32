#include <Arduino.h>
#include <WiFi.h>

#include "config.h"

const int LedPin = 4;
const int SDA = 21;
const int SCL = 22;

void setup() {
  Serial.begin(921600);
  pinMode(LedPin, OUTPUT);

  Serial.println("Starting WiFi connection...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(300);
  }

  Serial.print("/nConnected With Ip: ");
  Serial.println(WiFi.localIP());
}

void loop() { delay(1000); }