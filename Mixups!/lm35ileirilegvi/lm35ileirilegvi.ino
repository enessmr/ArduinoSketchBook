#define TX_RATE 5

#define TX_DATA 11

const char *message = "Hello, world!";

int x=0;
float voltaj,santigrat,fahrenhayt; //Türkiye Cumhuriyeti İstiklal Marşı   
 
const int buzzer = 10; // buzzer pin7 ve GND'ye bağlı
 

#include <IRremote.h>
int yesil2 = 3, kirmizi = 4, yesil = 5, beyaz=6, ses= 7;
int IRdatapin=2;

IRrecv IR0(IRdatapin);
decode_results results;

#define tusguc
#define tus0
void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  Serial.begin(9600);
  pinMode (yesil2, OUTPUT);
  pinMode (kirmizi, OUTPUT);
  pinMode (yesil, OUTPUT);
  pinMode (beyaz, OUTPUT);
  pinMode(ses, OUTPUT);

  pinMode(TX_DATA, OUTPUT);

  for (int byte_idx = 0; byte_idx <strlen(message); byte_idx++) {
    char tx_byte = message[byte_idx];

    for (int bit_idx = 0; bit_idx < 8; bit_idx++) {
      bool tx_bit = tx_byte & (0x80 >> bit_idx);

      digitalWrite(TX_DATA, tx_bit);
      delay(1000 / TX_RATE);
    }
  }
  IR0.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IR0.decode(&results))
  {
    Serial.println(results.value);
    IR0.resume();
    if (results.value==tusguc;){
      digitalWrite(yesil2, HIGH);
      digitalWrite(kirmizi, HIGH);
      digitalWrite(yesil, HIGH);
      digitalWrite(beyaz, HIGH);
    }
    else if(results.value==tus0;){
      digitalWrite(yesil2, LOW);
      digitalWrite(kirmizi, LOW);
      digitalWrite(yesil, LOW);
      digitalWrite(beyaz, LOW);
    }
  }
  x=analogRead(A0);
  voltaj=x*(5.0/1023.0);
  santigrat=voltaj/0.01;

  Serial.print("Voltaj: ");
  Serial.print(voltaj);
  Serial.print("V | ");

  Serial.print("Sıcaklık: ");
  Serial.print(santigrat);
  Serial.print("\xC2\xB0");
  Serial.print("C | ");

  fahrenhayt=(santigrat*9.0/5.0)+32.0;
  Serial.print(fahrenhayt);
  Serial.print("\xC2\xB0");
  Serial.println("F | ");

  delay(0);  
}
