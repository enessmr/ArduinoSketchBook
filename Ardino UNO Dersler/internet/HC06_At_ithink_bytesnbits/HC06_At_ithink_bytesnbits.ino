#include "Arduino.h"
#include <SoftwareSerial.h>

const byte rxPin= 8;
const byte txPin= 9;
SoftwareSerial BTSerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}

String messageBuffer = "";
String message = "";
char dataByte;
void loop() {
  while(BTSerial.available()) {
    dataByte = BTSerial.read();
    Serial.write(dataByte);
  }

  while(Serial.available()) {
    dataByte = Serial.read();
    BTSerial.write(dataByte);
  }
}