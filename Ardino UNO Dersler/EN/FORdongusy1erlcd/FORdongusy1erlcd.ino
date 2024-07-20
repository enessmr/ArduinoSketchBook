#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  for (int sayac =0; sayac <= 10; sayac=sayac+2)
  { 
    lcd.print(sayac);
    delay(1000);
    lcd.clear();
    //sayac=sayac+1;
  }
  }