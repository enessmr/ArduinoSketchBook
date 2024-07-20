#include <IRremote.h>

const int RECV_PIN = 2; // Pin connected to the IR receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // Print the HEX code of the received signal
    irrecv.resume(); // Receive the next value
  }
}
