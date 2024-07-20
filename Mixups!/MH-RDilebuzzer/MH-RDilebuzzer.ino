int buzzerPin=7;

void setup() {
  pinMode (buzzerPin,OUTPUT);
  Serial.begin(9600);
  pinMode(4, OUTPUT);

}

void loop() {
  int value = analogRead(A3);
  Serial.print("Value: ");
  Serial.println(value);
  delay(200);
  if (value >= 500) {
  Serial.print("No rain. ");
  Serial.println(value);
  delay(200);
  }
  if (value >= 300 && value < 500 ) {
    digitalWrite(4, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.print("Medium rain.");
    delay(200);
  }
  if (value < 300) {
    digitalWrite(4, HIGH);
    digitalWrite(buzzerPin,HIGH);
    Serial.print("Heavy rain, LED & Buzzer on. ");
    delay(200);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(buzzerPin,LOW);
    delay(200);
  }
}