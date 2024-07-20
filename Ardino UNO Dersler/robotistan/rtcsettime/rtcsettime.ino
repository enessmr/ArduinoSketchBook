#include <virtuabotixRTC.h>                            //Kütüphanemizi ekliyoruz.
int CLK_PIN = SCL ;                                       //6. pini clock pini olarak tanımladık
int DAT_PIN = SDA;                                       //7. pini data pini olarak tanımladık
int RST_PIN = 4;                                       //8. pini reset pini olarak tanımladık.
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);      // Kütüphanemizi pinlere atıyoruz.

void setup() {
 Serial.begin(9600);                                   //Seri haberleşmeyi başlatıyoruz.
 myRTC.setDS1302Time(59,23,12,4,4,07,2024);     //Saati saniye, dakika, saat, haftanın günü, ayın günü, ay, yıl olarak ayarlıyoruz.
}

void loop() {
 myRTC.updateTime();                                   //RTC'den zamanı okuyoruz

 Serial.print("Tarih / Saat: ");                       //Aldığımız verileri Serial Porta bastırıyoruz.
 Serial.print(myRTC.dayofmonth);
 Serial.print("/");
 Serial.print(myRTC.month);
 Serial.print("/");
 Serial.print(myRTC.year);
 Serial.print(" ");
 Serial.print(myRTC.hours);
 Serial.print(":");
 Serial.print(myRTC.minutes);
 Serial.print(":");
 Serial.println(myRTC.seconds);

 delay(1000);                                          //1sn bekleme.
}
