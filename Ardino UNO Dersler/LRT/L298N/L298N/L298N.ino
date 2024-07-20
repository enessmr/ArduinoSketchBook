#define in1 10
#define in2 9
#define in3 7
#define in4 6

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void loop() {
  // A motorunu bir yöne döndür.
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(3000); 
  // A motorunu durdur.
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(3000);
  // A motorunu diğer yöne döndür.
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(3000); 
  // A motorunu durdur.
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(3000);
  
  // B motorunu bir yöne döndür.
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(3000); 
  // B motorunu durdur.
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(3000);
  // B motorunu diğer yöne döndür.
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(3000); 
  // B motorunu durdur.
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(3000);
}
