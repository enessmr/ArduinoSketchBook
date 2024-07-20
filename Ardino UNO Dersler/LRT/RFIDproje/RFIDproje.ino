/*
Lezzetli Robot Tarifleri 
https://lezzetlirobottarifleri.com/arduino-ile-rfid-uygulamasi
*/

#include <SPI.h>
#include <RFID.h>

const byte kirmizi_led = 7;
const byte yesil_led = 6;

RFID rfid(10, 9);

byte anahtarlik[5] = {34, 234, 116, 83, 239};
byte kart[5] = {147, 58, 70, 200, 39};

boolean izin = true;

void setup() {
  Serial.begin(9600);

  SPI.begin();
  rfid.init();

  pinMode(kirmizi_led, OUTPUT);
  pinMode(yesil_led, OUTPUT);
}

void loop() {
  izin = true;
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      Serial.print("Kart bulundu ID: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(",");
      Serial.print(rfid.serNum[1]);
      Serial.print(",");
      Serial.print(rfid.serNum[2]);
      Serial.print(",");
      Serial.print(rfid.serNum[3]);
      Serial.print(",");
      Serial.println(rfid.serNum[4]);

      // Check the card ID against predefined IDs
      for (int i = 0; i < 5; i++) {
        if (rfid.serNum[i] != kart[i] && rfid.serNum[i] != anahtarlik[i]) {
          izin = false;
          break; // Exit loop as soon as a mismatch is found
        }
      }

      if (izin == true) {
        Serial.println("İzin Verildi");
        digitalWrite(yesil_led, HIGH);
        delay(1000);
        digitalWrite(yesil_led, LOW);
      } else {
        Serial.println("İzinsiz Giriş");
        digitalWrite(kirmizi_led, HIGH);
        delay(1000);
        digitalWrite(kirmizi_led, LOW);
      }
    }

    rfid.halt();
  }
}
