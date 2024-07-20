#include <DHT.h>

int dhtPin = 4;

DHT dht(dhtPin, DHT11);

void setup() {
  dht.begin();
  Serial.begin(9600);  
}

void loop() {
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();

  Serial.println("Nem: ");
  Serial.println(nem);

  Serial.println("Sıcaklık");
  Serial.println(sicaklik);
  delay(500);
  }
