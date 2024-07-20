#include <IRremote.h>

// Define the IR receiver pin
const int IR_PIN = 2;

// Define the IR receiver object
IRrecv irrecv(IR_PIN);

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // Check if the IR receiver has received a signal
  if (irrecv.decode()) {
    // Print the HEX value of the button press
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
    
    // Reset the IR receiver for the next signal
    irrecv.resume();
  }
}
