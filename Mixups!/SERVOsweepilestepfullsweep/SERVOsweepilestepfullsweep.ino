/*

  FullStepSweep.ino

  Uses the X113647Stepper library, and demonstrates continuous full-step cw/ccw rotation
  with a delay between each change in direction
  (the delay is longer when switching from ccw to cw).

  For info and circuit diagrams see https://github.com/tardate/X113647Stepper

 */

#include <Servo.h>
#include <X113647Stepper.h>

int pos = 0;
static const int STEPS_PER_REVOLUTION = 32 * 64;

static const int PIN_IN1_BLUE         = 4;
static const int PIN_IN2_PINK         = 5;
static const int PIN_IN3_YELLOW       = 6;
static const int PIN_IN4_ORANGE       = 7;
// servo naming
Servo myServo;

// initialize the stepper library
tardate::X113647Stepper myStepper(
  STEPS_PER_REVOLUTION,
  PIN_IN1_BLUE, PIN_IN2_PINK, PIN_IN3_YELLOW, PIN_IN4_ORANGE
);

void setup() {
  // Servo is attached to pin 3, PWM
  myServo.attach(3);

  // set the speed in rpm:
  myStepper.setSpeed(4);
}

void loop() {
  // servo write 180
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

  // step one revolution in one direction:
  myStepper.step(STEPS_PER_REVOLUTION);
  delay(200);

  // step one revolution in the other direction:
  myStepper.step(-STEPS_PER_REVOLUTION);
  delay(1000);
}
