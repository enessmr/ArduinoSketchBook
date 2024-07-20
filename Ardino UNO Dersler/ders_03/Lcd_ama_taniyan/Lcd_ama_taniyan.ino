#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println ("I2C Ekran Türü TaranıyOR!!...");
  Wire.begin();
  for (byte e = 8; e < 150; e++)
  {
    Wire.beginTransmission (e);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("İletişim YoLu BULUndu, EkrAn türü : ");
      Serial.print (e, DEC);
      Serial.print (" (0x");
      Serial.print (e, HEX);
      Serial.println (")");
    }
  }
  Serial.println ("Tamamlandı. ");
}

void loop() {
  // put your main code here, to run repeatedly:

}
