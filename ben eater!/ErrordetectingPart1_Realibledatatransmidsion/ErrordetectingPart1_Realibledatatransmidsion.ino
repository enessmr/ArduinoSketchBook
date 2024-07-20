#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TX_RATE 5

#define TX_CLOCK 2 
#define TX_DATA 3
#define SCL A5
#define SDA A4

const char *message = "Hello, world!";

void setup() {
  pinMode(TX_CLOCK, OUTPUT);
    pinMode(TX_DATA, OUTPUT);

    LiquidCrystal_I2C lcd(0x27, 16, 2);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print(message);

  for (int byte_idx = 0; byte_idx <strlen(message); byte_idx++) {
    char tx_byte = message[byte_idx];

    lcd.setCursor(0,1);
    lcd.print("       ");
    lcd.setCursor(byte_idx, 0);
    lcd.cursor();

    for (int bit_idx = 0; bit_idx < 8; bit_idx++) {
      bool tx_bit = tx_byte & (0x80 >> bit_idx);

      digitalWrite(TX_DATA, tx_bit);
      delay((1000 / TX_RATE) / 2);

      
      lcd.noCursor();
      lcd.setCursor(bit_idx, 1);
      lcd.print(tx_bit ? "1" : "0");
      lcd.setCursor(byte_idx, 0);
      lcd.cursor();
      
      digitalWrite(TX_CLOCK, HIGH);
      delay((1000 / TX_RATE) / 2);
      digitalWrite(TX_CLOCK, LOW);
    }
  }
  digitalWrite(TX_DATA, LOW);
}

void loop() {}
