

#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

void setup()
{
    lcd.begin();

    lcd.backlight();
    lcd.print("Counter: ");
}

void loop()
{

  for(int i=0;i<10000000;i++)
  {

    lcd.setCursor(9,0);
    lcd.print(i);


  }


  
}