#include <Servo.h>

Servo myServo;

int Konum;
int Bekleme;

void setup() {
  // Servonun atacchlanmasını sağlıyoruz
  myServo.attach(3);

  // Step motor :D
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  Konum = 8;
  Bekleme = 10;
}

void loop() {
  // Servonun 360 derece dönmesini sağlıyoruz.
  myServo.write(360);
  // Step motorun Dönmesini sağlıyoruz.
  sagaDon (500);
  sagaDon(100);
  
}

void sagaDon (int Adim) {
  for (int i = 0; i < Adim; i++) {
    digitalWrite(Konum, HIGH);
    delay(Bekleme);
    digitalWrite(Konum, LOW);
    KonumArttir();
  }
}

void KonumArttir() {
  Konum++;
  if (Konum == 12) Konum = 8;
}
