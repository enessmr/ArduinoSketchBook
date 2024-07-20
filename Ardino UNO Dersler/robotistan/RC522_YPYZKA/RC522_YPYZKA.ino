

#include <SPI.h>                   //SPI kütüphanemizi tanımlıyoruz.
#include <MFRC522.h>              //MFRC522 kütüphanemizi tanımlıyoruz.
#include <Servo.h>               //Servo kütüphanemizi tanımlıyoruz.

int RST_PIN = 9; //RC522 modülü reset pinini tanımlıyoruz.
int SS_PIN = 10; //RC522 modülü chip select pinini tanımlıyoruz.
int servoPin = 8; //Servo motor pinini tanımlıyoruz.

Servo motor; //Servo motor için değişken oluşturuyoruz.
MFRC522 rfid(SS_PIN, RST_PIN); //RC522 modülü ayarlarını yapıyoruz.

// Yetkili kart ID'lerini tanımlıyoruz.
byte authorizedIDs[2][4] = {
  {34, 234, 116, 83},
  {147, 58, 70, 200}
};

void setup() {
  motor.attach(servoPin); //Servo motor pinini motor değişkeni ile ilişkilendiriyoruz.
  Serial.begin(9600); //Seri haberleşmeyi başlatıyoruz.
  SPI.begin(); //SPI iletişimini başlatıyoruz.
  rfid.PCD_Init(); //RC522 modülünü başlatıyoruz.
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) //Yeni kartın okunmasını bekliyoruz.
    return;

  if (!rfid.PICC_ReadCardSerial()) //Kart okunmadığı zaman bekliyoruz.
    return;

  // Okunan kart ID'si yetkili ID'lerden biriyle eşleşiyor mu kontrol ediyoruz.
  if (isAuthorized(rfid.uid.uidByte)) {
    Serial.println("Kapi acildi");
    ekranaYazdir();
    motor.write(180); //Servo motoru çalıştırıyoruz (hız ve yönü belirler).
    delay(10000); //10 saniye bekliyoruz.
    motor.write(90); //Servo motoru durduruyoruz (hız ve yön 90 derece merkez pozisyonunda durma).
  } else { //Yetkisiz girişte içerideki komutlar çalıştırılır.
    Serial.println("Yetkisiz Kart");
    ekranaYazdir();
  }

  rfid.PICC_HaltA();
}

bool isAuthorized(byte *readID) {
  for (int i = 0; i < 2; i++) {
    if (checkID(readID, authorizedIDs[i])) {
      return true;
    }
  }
  return false;
}

bool checkID(byte *readID, byte *authorizedID) {
  for (int i = 0; i < 4; i++) {
    if (readID[i] != authorizedID[i]) {
      return false;
    }
  }
  return true;
}

void ekranaYazdir() {
  Serial.print("ID Numarasi: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(rfid.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println("");
}
