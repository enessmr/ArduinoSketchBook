#include <RFID.h>
#include <SPI.h>

RFID lrt720(10,9);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  lrt720.init();
}

void loop() {
  if(lrt720.isCard()) {

    if(lrt720.readCardSerial())
    {
      Serial.print(" Kart Bulundu ID: ");
      Serial.print(lrt720.serNum[0]);
      Serial.print(",");
      Serial.print(lrt720.serNum[1]);
      Serial.print(",");
      Serial.print(lrt720.serNum[2]);
      Serial.print(",");
      Serial.print(lrt720.serNum[3]);
      Serial.print(",");
      Serial.println(lrt720.serNum[4]);
    }
  lrt720.halt();
  }
}