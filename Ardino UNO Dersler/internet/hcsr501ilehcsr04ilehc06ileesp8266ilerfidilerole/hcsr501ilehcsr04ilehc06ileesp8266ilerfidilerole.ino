#include <SPI.h>a
#include <MFRC522.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>

// RFID Pinleri
#define SS_PIN 10
#define RST_PIN 9

// Röle Pinleri
#define RELAY1_PIN 5
#define RELAY2_PIN 8

// Ultrasonik Sensör Pinleri
#define TRIG_PIN 7
#define ECHO_PIN 6

// PIR Sensör Pin
#define PIR_PIN 4

// Bluetooth HC06 Pinleri
#define BT_RX 2 // Arduino RX
#define BT_TX 3 // Arduino TX

SoftwareSerial bluetooth(BT_RX, BT_TX);

// RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

const int masterCard[4] = {0xDE, 0xAD, 0xBE, 0xEF}; // Master kart ID'sini burada belirleyin
bool programmingMode = false;

void setup() {
  // Seri İletişim
  Serial.begin(9600);
  bluetooth.begin(9600);

  // RFID
  SPI.begin();
  mfrc522.PCD_Init();

  // Röle Pinleri Çıkış Olarak Ayarla
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Ultrasonik Sensör Pinleri
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // PIR Sensör Pini
  pinMode(PIR_PIN, INPUT);

  Serial.println("Sistem Başlatıldı.");
  bluetooth.println("Sistem Başlatıldı.");
}

void loop() {
  // RFID Kart Okuma
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String cardID = "";
    byte uid[4];
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardID += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      cardID += String(mfrc522.uid.uidByte[i], HEX);
      uid[i] = mfrc522.uid.uidByte[i];
    }
    Serial.println("Kart ID: " + cardID);
    sendBluetoothData("Kart ID: " + cardID);

    if (isMasterCard(uid)) {
      programmingMode = !programmingMode;
      if (programmingMode) {
        Serial.println("Programlama moduna geçildi.");
        sendBluetoothData("Programlama moduna geçildi.");
      } else {
        Serial.println("Programlama modu kapatıldı.");
        sendBluetoothData("Programlama modu kapatıldı.");
      }
    } else if (programmingMode) {
      if (isCardAuthorized(uid)) {
        Serial.println("Kart yetkili, EEPROM'dan siliniyor...");
        sendBluetoothData("Kart yetkili, EEPROM'dan siliniyor...");
        removeCardFromEEPROM(uid);
        Serial.println("Kart EEPROM'dan silindi.");
        sendBluetoothData("Kart EEPROM'dan silindi.");
      } else {
        Serial.println("Kart yetkili değil, EEPROM'a yazılıyor...");
        sendBluetoothData("Kart yetkili değil, EEPROM'a yazılıyor...");
        writeNewCardToEEPROM(uid);
        Serial.println("Kart EEPROM'a yazıldı.");
        sendBluetoothData("Kart EEPROM'a yazıldı.");
      }
    } else {
      if (isCardAuthorized(uid)) {
        Serial.println("Kart yetkili.");
        sendBluetoothData("Kart yetkili.");
      } else {
        Serial.println("Kart yetkili değil.");
        sendBluetoothData("Kart yetkili değil.");
      }
    }
  }

  // PIR Sensör
  if (digitalRead(PIR_PIN) == HIGH) {
    Serial.println("Hareket Algılandı!");
    sendBluetoothData("Hareket Algılandı!");
    digitalWrite(RELAY1_PIN, HIGH);
  } else {
    digitalWrite(RELAY1_PIN, LOW);
  }

  // Ultrasonik Sensör
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");
  sendBluetoothData("Mesafe: " + String(distance) + " cm");

  // Ultrasonik Mesafe Kontrolü ile Röle Kontrolü
  if (distance < 10) {
    digitalWrite(RELAY2_PIN, HIGH);
  } else {
    digitalWrite(RELAY2_PIN, LOW);
  }

  // Bluetooth ile veri alma
  if (bluetooth.available() > 0) {
    String command = bluetooth.readStringUntil('\n');
    executeCommand(command);
  }

  delay(1000);
}

bool isMasterCard(byte *uid) {
  for (int i = 0; i < 4; i++) {
    if (uid[i] != masterCard[i]) {
      return false;
    }
  }
  return true;
}

void writeNewCardToEEPROM(byte *uid) {
  for (int i = 0; i < 4; i++) {
    EEPROM.write(i, uid[i]);
  }
}

bool isCardAuthorized(byte *uid) {
  for (int i = 0; i < 4; i++) {
    if (EEPROM.read(i) != uid[i]) {
      return false;
    }
  }
  return true;
}

void removeCardFromEEPROM(byte *uid) {
  for (int i = 0; i < 4; i++) {
    EEPROM.write(i, 0xFF); // EEPROM'dan kartı silmek için 0xFF yazılır
  }
}

void sendBluetoothData(String data) {
  bluetooth.println(data);
}

void executeCommand(String command) {
  if (command == "RELAY1_ON") {
    digitalWrite(RELAY1_PIN, HIGH);
  } else if (command == "RELAY1_OFF") {
    digitalWrite(RELAY1_PIN, LOW);
  } else if (command == "RELAY2_ON") {
    digitalWrite(RELAY2_PIN, HIGH);
  } else if (command == "RELAY2_OFF") {
    digitalWrite(RELAY2_PIN, LOW);
  } else {
    Serial.println("Bilinmeyen komut: " + command);
  }
}
