int ledler[] = {2,3,4,5,6,7,8,9,10};

void setup() {
  // put your setup code here, to run once:
    for(int i=0; i<6; i++){

    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    for(int i=0; i<10; i++){
    digitalWrite(ledler[i], HIGH);
    delay(200);
    digitalWrite(ledler[i], LOW);
  }

  for(int j=10; j>-1; j--){
    digitalWrite(ledler[j], HIGH);
    delay(200);
    digitalWrite(ledler[j], LOW);
  }
}
