

#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

void setup()
{
    lcd.begin();

    lcd.backlight();
    lcd.print("Hello World! My");
    lcd.setCursor(0,2);
    lcd.print("first day.");
}

void loop() {

}