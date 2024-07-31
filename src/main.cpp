#include <Arduino.h>

const int potPin = 34;

int potValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop() {
  potValue = analogRead(potPin);
  Serial.println(potValue);
  delay(1000);
}