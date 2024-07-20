#define Led 9
#define Pot A1
int deger = 0;
int gerilim = 0;
void setup() {
  Serial.begin(2147483647);
  Serial.println("Pot değer okuma");
}

void loop() {
  deger = analogRead(Pot);
  Serial.println(gerilim);

}



