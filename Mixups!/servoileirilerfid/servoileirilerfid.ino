#include <IRremote.h>
#include <RFID.h>
#include <SPI.h>
#include <Servo.h>

RFID lrt720(10, 9);
IRrecv irrecv(2);
decode_results results;

#define BUTON1 4294967295
#define BUTON2 4294967295
#define BUTON3 4294967295
#define BUTON4 4294967295
#define BUTON5 4294967295
#define BUTON6 4294967295
#define BUTON7 4294967295
#define BUTON8 4294967295
#define BUTON9 4294967295
#define YILDIZ 4294967295
#define BUTON0 4294967295
#define YUKARI 4294967295
#define SOL 4294967295
#define OK 4294967295
#define SAG 4294967295
#define ASAGI 4294967295

const int GREEN_LED_PIN = 3;  // Yeşil LED pini
const int RED_LED_PIN = 4;    // Kırmızı LED pini
const int SERVO_PIN = 5;      // Servo pini

Servo myServo;
unsigned long lastActionTime;
bool isServoActive = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  lrt720.init();
  irrecv.enableIRIn();
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Servoyu başlangıç pozisyonuna getir
}

void loop() {
  if (lrt720.isCard()) {
    if (lrt720.readCardSerial()) {
      Serial.print("Kart Bulundu ID: ");
      Serial.print(lrt720.serNum[0]);
      Serial.print(",");
      Serial.print(lrt720.serNum[1]);
      Serial.print(",");
      Serial.print(lrt720.serNum[2]);
      Serial.print(",");
      Serial.print(lrt720.serNum[3]);
      Serial.print(",");
      Serial.println(lrt720.serNum[4]);

      if (isValidCard()) { // Geçerli bir kart olup olmadığını kontrol eden fonksiyon
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(RED_LED_PIN, LOW);
        turnServo();
        lastActionTime = millis(); // Son doğru eylem zamanını güncelle
      } else {
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(RED_LED_PIN, HIGH);
        stopServo(); // Geçersiz kart okutulunca servo duracak
      }
    }
    lrt720.halt();
  }

  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if (results.value == BUTON0) {  // Doğru buton kodunu buraya girin
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
      turnServo();
      lastActionTime = millis(); // Son doğru eylem zamanını güncelle
    } else {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
      stopServo(); // Yanlış butona basıldığında servo duracak
    }
    irrecv.resume();
  }

  // 2 saniye içinde doğru eylem olmadıysa servo motoru durdur
  if (isServoActive && (millis() - lastActionTime >= 2000)) {
    stopServo();
    Serial.println("Servo stopped due to timeout.");
  }
}

bool isValidCard() {
  // Geçerli kart ID'lerini burada tanımlayın
  byte validCards[][5] = {
    {147,58,70,200,39}, // Örnek kart ID'si
    {34,234,116,83,239}, // Diğer geçerli kart ID'si
    // Diğer geçerli kart ID'lerini buraya ekleyin
  };

  for (int i = 0; i < sizeof(validCards) / sizeof(validCards[0]); i++) {
    bool match = true;
    for (int j = 0; j < 5; j++) {
      if (lrt720.serNum[j] != validCards[i][j]) {
        match = false;
        break;
      }
    }
    if (match) {
      return true;
    }
  }
  return false;
}

void turnServo() {
  myServo.write(180); // Servoyu 180 derece döndür
  isServoActive = true; // Servo motoru aktif olarak işaretle
  Serial.println("Servo turned to 180 degrees.");
}

void stopServo() {
  myServo.write(90); // Servo motorunu durdurmak için 90 dereceye getir (durdurma pozisyonu)
  isServoActive = false; // Servo motoru durdurma işaretini kapat
  Serial.println("Servo stopped.");
}
