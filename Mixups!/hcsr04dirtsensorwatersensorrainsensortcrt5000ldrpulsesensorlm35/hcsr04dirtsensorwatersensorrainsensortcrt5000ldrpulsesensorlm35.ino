#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PulseSensorPlayground.h>

// Pin tanımlamaları
#define trigPin 9
#define echoPin 10
#define soilMoisturePin A0
#define waterSensorPin 2
#define rainSensorPin A1
#define tcrt5000Pin A2
#define ldrPin A3
#define pulsePin A4
#define lm35Pin A5
#define soundSensorPin 3
#define vibrationSensorPin 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
PulseSensorPlayground pulseSensor;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(waterSensorPin, INPUT);
  pinMode(soundSensorPin, INPUT);
  pinMode(vibrationSensorPin, INPUT);
  
  lcd.init();
  lcd.backlight();
  pulseSensor.analogInput(pulsePin);
  pulseSensor.begin();
  
  lcd.setCursor(0, 0);
  lcd.print("Sensörler Baslatildi");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Ultrasonik Mesafe Sensörü
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  // Toprak Nem Sensörü
  int soilMoistureValue = analogRead(soilMoisturePin);
  
  // Su Sensörü
  int waterSensorValue = digitalRead(waterSensorPin);
  
  // Yağmur Sensörü
  int rainSensorValue = analogRead(rainSensorPin);
  
  // TCRT5000 Sensörü
  int tcrt5000Value = analogRead(tcrt5000Pin);
  
  // LDR (Işık Sensörü)
  int ldrValue = analogRead(ldrPin);
  
  // Nabız Ölçer
  int myBPM = pulseSensor.getBeatsPerMinute();
  
  // LM35 (Sıcaklık Sensörü)
  int lm35Value = analogRead(lm35Pin);
  float temperature = (lm35Value * 5.0 * 100.0) / 1024;
  
  // Ses Sensörü
  int soundSensorValue = digitalRead(soundSensorPin);
  
  // Titreşim Sensörü
  int vibrationSensorValue = digitalRead(vibrationSensorPin);
  
  // LCD Ekran Güncelleme
  lcd.setCursor(0, 0);
  lcd.print("Mesafe: ");
  lcd.print(distance);
  lcd.print(" cm");
  
  lcd.setCursor(0, 1);
  lcd.print("Sicaklik: ");
  lcd.print(temperature);
  lcd.print(" C");
  
  // Seri Monitör Çıktısı
  Serial.print("Mesafe: "); Serial.print(distance); Serial.println(" cm");
  Serial.print("Toprak Nem: "); Serial.println(soilMoistureValue);
  Serial.print("Su Tespiti: "); Serial.println(waterSensorValue ? "Evet" : "Hayir");
  Serial.print("Yağmur: "); Serial.println(rainSensorValue);
  Serial.print("TCRT5000: "); Serial.println(tcrt5000Value);
  Serial.print("Işık: "); Serial.println(ldrValue);
  Serial.print("Kalp Atış Hızı: "); Serial.println(myBPM);
  Serial.print("Sıcaklık: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Ses: "); Serial.println(soundSensorValue ? "Algılandı" : "Algılanmadı");
  Serial.print("Titreşim: "); Serial.println(vibrationSensorValue ? "Algılandı" : "Algılanmadı");
  
  delay(1000);
}
