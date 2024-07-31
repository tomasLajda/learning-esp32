#include <Arduino.h>
#include "config.h"
#include <WiFiMulti.h>

WiFiMulti wifiMulti;

const int LedPin = 4;

void setup() {
  Serial.begin(921600);
  pinMode(LedPin, OUTPUT);

  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting ...");
  while(wifiMulti.run() != WL_CONNECTED) {
    delay(100);
  }
  Serial.println("Connected to wifi");

}

void loop() {
  digitalWrite(LedPin, WiFi.status() == WL_CONNECTED);
}