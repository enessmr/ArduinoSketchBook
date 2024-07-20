// L298N Bağlantısı   
const int motorA1  = 5;  // L298N'in IN4 Girişi
const int motorA2  = 6;  // L298N'in IN3 Girişi
const int motorB1  = 9;  // L298N'in IN1 Girişi
const int motorB2  = 10; // L298N'in IN2 Girişi
// Bluetooth cihazından gelecek komutu tutan değişken
int komut;
int hiz = 200;
void ileri() {  
  analogWrite(motorA1, hiz); analogWrite(motorA2, 0);
  analogWrite(motorB1, hiz); analogWrite(motorB2, 0);   
}
void geri() {
  analogWrite(motorA1, 0 ); analogWrite(motorA2, hiz);  
  analogWrite(motorB1, 0);  analogWrite(motorB2, hiz);  
}
void saga() {
  analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
  analogWrite(motorB1, hiz); analogWrite(motorB2, 50);
  }
void sola() {
  analogWrite(motorA1, hiz); analogWrite(motorA2, 50); 
  analogWrite(motorB1, 0); analogWrite(motorB2, 0);  
}
void dur() {
   analogWrite(motorA1, 0); analogWrite(motorA2, 0); 
   analogWrite(motorB1, 0); analogWrite(motorB2, 0);  
}
void setup() {
  // Pin yönlerini ayarla  
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);  
    
  // 9600 baud hızında bir seri iletisim baslatalim
  Serial.begin(9600);
}
void loop() {
   if (Serial.available() > 0){     
      komut = Serial.read();
if (komut == 'F') {
        ileri();
        delay(300);
        dur();
      } else
      if (komut == 'B') {
        geri();
        delay(300);
        dur();
      } else
      if (komut == 'R') {
        saga();
        delay(300);
        dur();
      } else
      if (komut == 'L') {
        sola();
        delay(300);
        dur();
      } else  
      if (komut == 'S') {
        dur();
     }
      delay(10);       
   }
}
