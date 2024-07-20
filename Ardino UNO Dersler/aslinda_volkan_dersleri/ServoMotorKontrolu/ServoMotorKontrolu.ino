

#include <Servo.h>

int potpin = A1;
Servo servo;
int val = 0;

void setup() {
  servo.attach(3);
}

void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 179);
  servo.write(val);
  delay(15);
  
}
