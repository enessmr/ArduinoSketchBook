int Konum;
int Bekleme;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Konum = 8;
  Bekleme = 10;
}

void loop() {
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