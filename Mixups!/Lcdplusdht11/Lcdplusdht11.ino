#include <LiquidCrystal_I2C.h>
#include <DHT.h>

int dhtPin = 2;

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(dhtPin, DHT11);

void setup() {
  lcd.init();
  dht.begin();
  Serial.begin(9600);
  lcd.backlight();  
}

void loop() {
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();

  lcd.setCursor(0,0);
  Serial.println("Nem: ");
  Serial.println(nem);
  lcd.print("Nem: ");
  lcd.print(nem);

  lcd.setCursor(0,1);
  Serial.println("Sıcaklık");
  Serial.println(sicaklik);
  lcd.print("Sicaklik");
  lcd.print(sicaklik);
  delay(500);
  lcd.clear();
  }
