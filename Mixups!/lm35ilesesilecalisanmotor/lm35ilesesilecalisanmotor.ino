#define echoPin 6
#define SensorPin 5
#define MotorPin 7

int MotorDurum = LOW;

#define TX_RATE 5

#define TX_DATA 11

const char *message = "Hello, world!";

int x=0;
float voltaj,santigrat,fahrenhayt;

void setup() {
  // put your setup code here, to run once:
  pinMode(SensorPin, INPUT);
  pinMode(MotorPin, OUTPUT);
  
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  Serial.begin(9600);

  pinMode(TX_DATA, OUTPUT);

  for (int byte_idx = 0; byte_idx <strlen(message); byte_idx++) {
    char tx_byte = message[byte_idx];

    for (int bit_idx = 0; bit_idx < 8; bit_idx++) {
      bool tx_bit = tx_byte & (0x80 >> bit_idx);

      digitalWrite(TX_DATA, tx_bit);
      delay(1000 / TX_RATE);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    if (digitalRead(SensorPin)) {
    if (MotorDurum == LOW) {
      MotorDurum = HIGH;
    } else {
      MotorDurum = LOW;
    }
    digitalWrite(MotorPin, MotorDurum);
  }
  delay(50);
  
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
