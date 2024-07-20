#include <SoftwareSerial.h>

SoftwareSerial bt_iletisim(7,6);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt_iletisim.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
    if (bt_iletisim.available()) {
    char data = bt_iletisim.read();
    Serial.println(data);
  }
  
  // put your main code here, to run repeatedly:
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
}
