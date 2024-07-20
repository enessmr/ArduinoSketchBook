#include <SoftwareSerial.h>
SoftwareSerial BTSerial(8,9);
void setup() {
  Serial.begin(9600);
  Serial.println("Enter AT Commands");
  BTSerial.begin(38400);
}

void loop() {
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  

  if (Serial.available())
    BTSerial.write(Serial.read());
}