#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int sensor = A3;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int periyot=20;
double alfa=0.75;
double yenileme=0.0;

void setup(void) {
  lcd.backlight();
  pinMode(sensor,INPUT);
  lcd.init();
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop(void) {
  static double oncekideger=0;
  static double oncekiyenileme=0;

  int ritim=analogRead(sensor);


  double deger=alfa*oncekideger+(0-alfa)*ritim;
  yenileme=deger-oncekideger;
  lcd.setCursor(4,0);
  lcd.print("nabiziniz");
  lcd.setCursor(0,1);
  lcd.print("");
  lcd.setCursor(7,1);
  lcd.print(ritim/10);
  oncekideger=deger;
  oncekiyenileme=yenileme;
  delay(periyot*10);
}
