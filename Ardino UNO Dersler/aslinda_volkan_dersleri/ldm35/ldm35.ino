void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcValue = analogRead(A0);
  float VonPin = adcValue * 0.0048828125f; // 5/1024
  float degreeInCelsius = VonPin / 0.01f;  // celsius/10mV
  Serial.print("Temp :");
  Serial.print(degreeInCelsius);
  Serial.println("°C");
  delay(5000);
}
