#include <Arduino.h>

const int buttonPin = 4;  
const int ledPin =  5;

int buttonState = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(1000);
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}