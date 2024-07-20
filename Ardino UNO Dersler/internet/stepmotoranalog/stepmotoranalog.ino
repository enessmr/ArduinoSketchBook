// Pin tanımlamaları
int IN1 = A0;
int IN2 = A1;
int IN3 = A2;
int IN4 = A3;

void setup() {
  // Pinleri çıkış olarak ayarlayın
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Step motoru ileri doğru döndür
  ileri_don(2048);  // 2048 adım (yaklaşık bir tur)
  delay(1000);  // 1 saniye bekle

  // Step motoru geri doğru döndür
  geri_don(2048);  // 2048 adım (yaklaşık bir tur)
  delay(1000);  // 1 saniye bekle
}

void ileri_don(int adimlar) {
  for (int i = 0; i < adimlar; i++) {
    adim_ileri();
  }
}

void geri_don(int adimlar) {
  for (int i = 0; i < adimlar; i++) {
    adim_geri();
  }
}

void adim_ileri() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2);
}

void adim_geri() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2);
}
