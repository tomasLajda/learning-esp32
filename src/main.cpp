#include <Arduino.h>
#include <WiFi.h>
#include "config.h"

const int LedPin = 4;

void setup() {
  Serial.begin(921600);
  pinMode(LedPin, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Starting WiFi connection...");
}

bool isConnected = false;

void loop() {
  if (WiFi.status() == WL_CONNECTED && !isConnected) {
    Serial.println("Connected to WiFi!");
    digitalWrite(LedPin, WiFi.status() == WL_CONNECTED);
    isConnected = true;
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    digitalWrite(LedPin, !digitalRead(LedPin));
    delay(1000);
    isConnected = false;
  }
}