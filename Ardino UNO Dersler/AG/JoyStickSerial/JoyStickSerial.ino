
int x_pin = A1;
int y_pin = A2;
int sw_pin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  int x_data = analogRead(A1);
  int y_data = analogRead(A2);
  int sw_data = digitalRead(2);

  Serial.println("x_data:");
  Serial.print(x_data);
  Serial.print("\t");
  Serial.println("y_data:");
  Serial.print(y_data);
  Serial.print("\t");
  Serial.println("sw_data:");
  Serial.print(sw_data);
  Serial.print("\t");
  delay(3000);
}