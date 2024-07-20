#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Değerleri kalibrasyonunuza göre değiştirin
#define soilWet 500   // Toprağın 'ıslak' kabul edildiği maksimum değer
#define soilDry 750   // Toprağın 'kuru' kabul edildiği minimum değer

// Sensör pinleri
#define sensorPower 4
#define sensorPin A0

int sensorPin2 = 2;                // Sensörün bağlanacağı pin
int dijitalEsikDegeri = 1;         // Su miktarı için eşik değeri
int buzzerPin = 7;                 // Buzzer pini
int buttonPin = 5;                 // Uyku modu buton pini

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Uyku modu değişkeni
bool isSleeping = false;

// Debouncing için gerekli değişkenler
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 300;  // 300ms debouncing gecikmesi

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(sensorPower, OUTPUT);

  // Sensörü başlangıçta kapalı tut
  digitalWrite(sensorPower, LOW);

  pinMode(buzzerPin, OUTPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Uyku modu butonunu kontrol et
  int buttonState = digitalRead(buttonPin);
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonState == LOW) {
      isSleeping = !isSleeping;
      if (isSleeping) {
        enterSleepMode();
      } else {
        exitSleepMode();
      }
      lastDebounceTime = millis();
    }
  }

  if (!isSleeping) {
    // Sensörden okumayı al ve yazdır
    int moisture = readSensor();
    Serial.print("Analog Output: ");
    Serial.println(moisture);

    // Toprağın durumunu belirle
    lcd.setCursor(0, 0);
    if (moisture < soilWet) {
      lcd.print("Cok islak!  ");
      Serial.println("Status: Soil is too wet");
    } else if (moisture >= soilWet && moisture < soilDry) {
      lcd.print("Cok iyi!    ");
      Serial.println("Status: Soil moisture is perfect");
    } else {
      lcd.print("Sulayin!    ");
      Serial.println("Status: Soil is too dry - time to water!");
    }

    // A1 pininden okuma
    int value = analogRead(A1);
    lcd.setCursor(0, 1);
    if (value < 300) {
      noTone(buzzerPin);
      lcd.print("yes2 ");
    } else {
      tone(buzzerPin, 860);
      lcd.print("no2  ");
    }

    // Dijital sensörden okuma
    int digitalValue = digitalRead(sensorPin2);
    lcd.setCursor(5, 1);
    if (digitalValue == dijitalEsikDegeri) {
      lcd.print("3yes ");
      noTone(buzzerPin);
    } else {
      tone(buzzerPin, 450);
      lcd.print("3no  ");
    }

    delay(1000);  // Test için her saniyede bir okuma yapar, normalde günde bir veya iki kez okuma yapılmalı
    Serial.println();
  }
}

// Bu fonksiyon, analog toprak nem ölçümünü döndürür
int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Sensörü aç
  delay(10);                        // Güçün oturması için bekle
  int val = analogRead(sensorPin);  // Sensörden analog değeri oku
  digitalWrite(sensorPower, LOW);   // Sensörü kapat
  return val;                       // Analog nem değerini döndür
}

void enterSleepMode() {
  lcd.clear();
  lcd.noBacklight(); // LCD'yi kapat
  noTone(buzzerPin); // Buzzer'ı kapat
  Serial.println("Entering sleep mode...");
}

void exitSleepMode() {
  lcd.backlight(); // LCD'yi aç
  Serial.println("Exiting sleep mode...");
  delay(1000);     // Mesajı göstermek için kısa bir süre bekle
  lcd.clear();     // LCD'yi temizle
}
