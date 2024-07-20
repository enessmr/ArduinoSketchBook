#include <Wire.h>
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();

  lcd.backlight();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("LEZZETLI");
  lcd.setCursor(4,2);
  lcd.print("TARIFLER");
}