#define enA 11
#define in1 10
#define in2 9
#define enB 5
#define in3 7
#define in4 6

// Motorun hızını tutan değişken. 0 ile 255 arasında değer alabilir.
int hiz = 0; 

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
}
void loop() {
  // A motorunu bir yöne hızlandır.
  for (hiz = 0; hiz <= 255; hiz++)
  {
     analogWrite(enA, hiz);
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     delay(10);
  }

  // A motorunu bir yavaşlatarak durdur.
  for (hiz = 255; hiz >= 0; hiz--)
  {
     analogWrite(enA, hiz);
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     delay(10);
  }
}
