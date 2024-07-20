#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200
#define MAX_SPEED 190 // sets speed of DC motors

#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 3
#define MOTOR2_PIN1 4
#define MOTOR2_PIN2 5
#define MOTOR_SPEED_PIN 6

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo;

boolean goesForward = false;
int distance = 100;
int speedSet = 0;

void setup() {
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  pinMode(MOTOR_SPEED_PIN, OUTPUT);

  myservo.attach(10);
  myservo.write(115);
  delay(2000);
  for (int i = 0; i < 4; i++) {
    distance = readPing();
    delay(100);
  }
}

void loop() {
  int distanceR = 0;
  int distanceL = 0;
  delay(40);

  if (distance <= 15) {
    moveStop();
    delay(100);
    moveBackward();
    delay(300);
    moveStop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if (distanceR >= distanceL) {
      turnRight();
    } else {
      turnLeft();
    }
    moveStop();
  } else {
    moveForward();
  }
  distance = readPing();
}

int lookRight() {
  myservo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  return distance;
}

int lookLeft() {
  myservo.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  return distance;
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);
  analogWrite(MOTOR_SPEED_PIN, 0);
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    digitalWrite(MOTOR1_PIN1, HIGH);
    digitalWrite(MOTOR1_PIN2, LOW);
    digitalWrite(MOTOR2_PIN1, HIGH);
    digitalWrite(MOTOR2_PIN2, LOW);
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
      analogWrite(MOTOR_SPEED_PIN, speedSet);
      delay(5);
    }
  }
}

void moveBackward() {
  goesForward = false;
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    analogWrite(MOTOR_SPEED_PIN, speedSet);
    delay(5);
  }
}

void turnRight() {
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
  delay(300);
  moveForward();
}

void turnLeft() {
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
  delay(300);
  moveForward();
}
