
#define buzzerPin 8

int maximumRange = 50;
int minimiumRange = 0;
int trigPin = 7; /* Sensorun trig pini Arduinonun 6 numaralı ayağına bağlandı */
int echoPin = 6;  /* Sensorun echo pini Arduinonun 7 numaralı ayağına bağlandı */

long sure;
long uzaklik;

void setup(){
  pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin,INPUT);
  pinMode(buzzerPin, OUTPUT); /* echo pini giriş olarak ayarlandı */
  Serial.begin(9600); /* Seri haberlesme baslatildi */
}
void loop()
{
  int olcum = mesafe(maximumRange, minimiumRange);
  melodi(olcum*10);

  digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */
  delayMicroseconds(0);
  digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
  delayMicroseconds(0);
  digitalWrite(trigPin, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ 
  sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
  uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */            
  if(uzaklik > 200)
    uzaklik = 200;
  Serial.print("Uzaklik ");  
  Serial.print(uzaklik); /* hesaplanan uzaklık bilgisayara aktarılıyor */
  Serial.println(" CM olarak olculmustur.");  
  delay(50); 
}

int mesafe(int maxrange, int minrange)
{
  long duration, distance;

  digitalWrite(trigPin,LOW);
  delay(0);
  digitalWrite(trigPin, HIGH);
  delay(0);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(0);

  if(distance >= maxrange || distance <= minrange)
  return 0;
  return distance;
}


int melodi(int dly)
{
  tone(buzzerPin, 300);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}