int kled=2;
int yled=12;
int TCRT5000=11;

void setup() {
  Serial.begin(9600);
pinMode(TCRT5000,INPUT);
pinMode(yled,OUTPUT);
pinMode(kled,OUTPUT);
}

void loop() {
int bilgi_d=digitalRead(TCRT5000);
int bilgi_a=analogRead(A3);

  Serial.println(bilgi_a);

  if(bilgi_d==1){
    digitalWrite(yled,1);
    digitalWrite(kled,0);
      delay(100);
  }
  else{
    digitalWrite(yled,0);
    digitalWrite(kled,1);
      delay(100);    
  }

}
