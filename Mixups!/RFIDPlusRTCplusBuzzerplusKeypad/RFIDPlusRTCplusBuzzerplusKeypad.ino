
#include <Keypad.h>
#include <SPI.h>
#include <MFRC522.h>
#include <DS1302.h>

// Keypad tanımlamaları
const byte ROWS = 4; // Satır sayısı
const byte COLS = 4; // Sütun sayısı
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; // Satır pinleri (analog pinler)
byte colPins[COLS] = {A4, A5, 2, 3}; // Sütun pinleri (2 ve 3 dijital pinler)
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// RFID tanımlamaları
#define SS_PIN 10
#define RST_PIN 7 // Reset pini olarak 7'yi kullanıyoruz
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Buzzer ve Röle pinleri
const int buzzerPin = 6; // Buzzer pini olarak 6'yı kullanıyoruz
const int relayPin1 = 8; // Röle 1 pini
const int relayPin2 = 9; // Röle 2 pini

// DS1302 RTC modülü tanımlamaları
const int DS1302_CLK = SCL; // CLK pini (Arduino'nun SCL pini)
const int DS1302_DAT = SDA; // DAT pini (Arduino'nun SDA pini)
const int DS1302_RST = 4;   // RST pini (Dijital pin 4)
DS1302 rtc(DS1302_RST, DS1302_CLK, DS1302_DAT);


// Doğru şifre
String password = "3478";
String enteredPassword = "";

// Buzzer tonları
void playBuzzerTone(int type) {
  switch (type) {
    case 0: // Doğru şifre tonu
      tone(buzzerPin, 1000, 500);
      break;
    case 1: // Yanlış şifre tonu
      tone(buzzerPin, 200, 500);
      break;
    case 2: // RFID doğru tonu
      tone(buzzerPin, 1500, 500);
      break;
    case 3: // RFID yanlış tonu
      tone(buzzerPin, 100, 500);
      break;
    case 4: // Tuş basma sesi
      tone(buzzerPin, 500, 100);
      break;
  }
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);

  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);

}

void loop() {
  char key = keypad.getKey();
   if (key != NO_KEY) {
    Serial.println(key);
    // Tuşa basıldığında yapılacak işlemler buraya yazılır
  }
  
  if (key) {
    playBuzzerTone(4); // Tuş basma sesi
    if (key == '#') {
      if (enteredPassword == password) {
        playBuzzerTone(0);
        openDoor();
      } else {
        playBuzzerTone(1);
      }
      enteredPassword = "";
    } else {
      enteredPassword += key;
    }
  }

  // RFID işlemleri
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid += String(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println(uid);
    if (uid == "933A46C8" || "22EA7453") { // Doğru RFID kart UID
      playBuzzerTone(2);
      openDoor();
    } else {
      playBuzzerTone(3);
    }
    mfrc522.PICC_HaltA();
  }

  rtc.time(19, 15, 59);  // Set the time to 7:15:59 PM
  // Set date (day, month, year)
  rtc.setDate(4, 7, 2024);

  // RTC bilgilerini seri monitöre yazdırma
  Time t = rtc.t();
  Serial.print(t.hr);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(":");
  Serial.print(t.sec);
  Serial.print(" ");
  Serial.print(t.date);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.yr);
  Serial.println();
  delay(1000);
}

void openDoor() {  
  digitalWrite(relayPin2, HIGH); // Röle 1'i etkinleştir (kapıyı aç)
  delay(5000); // 5 saniye boyunca kapı açık
  digitalWrite(relayPin2, LOW); // Röle 1'i devre dışı bırak (kapıyı kapat)
  digitalWrite(relayPin1, HIGH); // Röle 1'i etkinleştir (kapıyı aç)
  delay(5000); // 5 saniye boyunca kapı açık
  digitalWrite(relayPin1, LOW); // Röle 1'i devre dışı bırak (kapıyı kapat)
}
