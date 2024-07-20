#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define trigPin 3
#define echoPin 2
#define led 10
#define buzzer 11
long mesafe;
int mesafeCm;
void setup() {
  lcd.backlight();
  lcd.init();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
mesafe = pulseIn(echoPin, HIGH);
mesafeCm = (mesafe / 2) / 29.1;
Serial.print("Mesafe = ");
Serial.print(mesafeCm);
Serial.println("cm");
lcd.setCursor(0,0);

if (mesafeCm < 10) {
  lcd.print("!Carpma Tehlikesi!");
  tone(buzzer, 200);
  digitalWrite(led, HIGH);
}
else if (mesafeCm < 15) {
  lcd.print("Mesafe: ");
  lcd.print(mesafeCm);
  lcd.print("cm");
  tone(buzzer, 400);
  digitalWrite(led, HIGH);
  delay(100);
  }
else if (mesafeCm < 20) {
   lcd.print("Mesafe: ");
  lcd.print(mesafeCm);
  lcd.print("cm");
  tone(buzzer, 600);
  digitalWrite(led, HIGH);
  delay(200);
  noTone(buzzer);
digitalWrite(led,LOW);
delay(200);
}
else if (mesafeCm <= 25) {
  lcd.print("Mesafe: ");
  lcd.print(mesafeCm);
  lcd.print("cm");
  tone(buzzer, 400);
  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led,LOW);
  delay(250);
   }


else if (mesafeCm > 30) {
  noTone(buzzer);
  digitalWrite(led, LOW);
  lcd.println("Engel Yok");
  delay(300);
   }
lcd.clear();
}
