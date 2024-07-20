#include <Servo.h>
#include <SPI.h>
#include <RFID.h>

Servo myServo;
RFID lrt720(10, 9);

// Anahtarlık ID'si
byte anahtarlikID[5] = {34, 234, 116, 83, 239};
// Kart ID'si
byte kartID[5] = {147, 58, 70, 200, 39};

void setup()
{
  myServo.attach(3);
  Serial.begin(9600);
  SPI.begin();
  lrt720.init();
}

void loop()
{
  if (lrt720.isCard()) {
    
    if (lrt720.readCardSerial()) {
      Serial.println("Kart Bulundu ID : ");
      for (int i = 0; i < 5; i++) {
        Serial.print(lrt720.serNum[i]);
        if (i < 4) {
          Serial.print(" , ");
        } else {
          Serial.println(" ");
        }
      }

      // Anahtarlık ID'sini kontrol et
      if (compareID(lrt720.serNum, anahtarlikID)) {
        Serial.println("Anahtarlık ID'si bulundu, servo saat yönünde dönüyor.");
        myServo.write(180); // Servo'yu saat yönünde döndür
      }
      // Kart ID'sini kontrol et
      else if (compareID(lrt720.serNum, kartID)) {
        Serial.println("Kart ID'si bulundu, servo saat yönünün tersine dönüyor.");
        myServo.write(0); // Servo'yu saat yönünün tersine döndür
      }
      // Tanınmayan ID
      else {
        Serial.println("Bilinmeyen kart, servo duruyor.");
        myServo.write(90); // Servo'yu durdur
      }
    }
  }
  lrt720.halt();
}

// İki ID'nin aynı olup olmadığını kontrol eden fonksiyon
bool compareID(byte *id1, byte *id2)
{
  for (int i = 0; i < 5; i++) {
    if (id1[i] != id2[i]) {
      return false;
    }
  }
  return true;
}
