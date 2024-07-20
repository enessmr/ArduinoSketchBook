const int LEDpin = 13;
const int butonPin = 12;

int butonDurumu = 0;

void setup() {
  pinMode(butonPin, INPUT);

  digitalWrite(butonPin, HIGH);

  pinMode(LEDpin, OUTPUT);
}

void loop(){
  butonDurumu = digitalRead(butonPin);

  if(butonDurumu == HIGH){
    digitalWrite(LEDpin, HIGH);
  }
  else {
    digitalWrite(LEDpin, LOW);
  }
}