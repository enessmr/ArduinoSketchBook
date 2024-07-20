#define LDR A5
#define Buzzer 11
#define Led 10
int deger;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  pinMode(Led,OUTPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  deger = analogRead(LDR);
  Serial.println(deger);
  if (deger < 2000)
  {
    digitalWrite(Led, HIGH);
    tone(Buzzer,500);
    delay(200);
    digitalWrite(Led, LOW);
    noTone(Buzzer);
    delay(200);
  }
}
