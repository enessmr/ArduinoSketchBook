#define echoPin 6
#define SensorPin 12
#define MotorPin 11

int MotorDurum = LOW;

void setup() {
  pinMode(SensorPin, INPUT);
  pinMode(MotorPin, OUTPUT);
}

void loop() {
  if (digitalRead(SensorPin)) {
    if (MotorDurum == LOW) {
      MotorDurum = HIGH;
    } else {
      MotorDurum = LOW;
    }
    digitalWrite(MotorPin, MotorDurum);
  }
  delay(50);
}
