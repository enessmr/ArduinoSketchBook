//MUCİT PİLOT 2020
//ESP8266 kullanımı ve internetten veri çekme

#include <SoftwareSerial.h>                                   //Gerekli kütüphaneleri ekliyoruz.
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

String agAdi = "Turksat_Kablonet_2.4_ENKX";                      //Kablosuz Ağ adını buraya yazıyoruz.    
String agSifresi = "bcc3KPAE";                              //Ağ şifresini buraya yazıyoruz.

int rxPin = 10;                                               //ESP8266 TX pini
int txPin = 11;                                               //ESP8266 RX pini


String ip = "184.106.153.149";                                //Thingspeak sitesinin ip adresi

#define DEBUG true                                            //çalışmanın düzgün olduğunu takip etmek için kullandım


SoftwareSerial esp(rxPin, txPin);                             //Seri haberleşme için pin ayarlarını yapıyoruz.
LiquidCrystal_I2C lcd(0x27, 16, 2);                           //(ekranın adresi, sütun sayısı, satır sayısı)


void setup() {  
  lcd.init();                                                 //LCD ekranı başlatıyoruz
  lcd.backlight();                                            //LCD'mize arka oşık veriyoruz
  Serial.begin(9600);                                         //Seri port haberleşmesini başlattık
  Serial.println("Başlatılıyor");
  //esp.begin(115200);                                        //ESP8266 ile seri haberleşmeyi başlatıyoruz.İlk çalıştırmada 115200 sonra 9600 yapıcaz
  esp.begin(9600);                                            //ESP8266 ile seri haberleşmeyi başlatıyoruz.
  esp.println("AT");                                          //AT komutu ile modül kontrolünü yapıyoruz.
  Serial.println("AT Gönderildi");
  while(!esp.find("OK")){                                     //Modül hazır olana kadar bekliyoruz.
    esp.println("AT");
    Serial.println("ESP8266 ile iletişim kurulamadı.");
  }
 //esp.println("AT+UART_DEF=9600,8,1,0,0");                   //ilk seferde sadece 1 kereliğine çalıştırıp baud rate değiştirdik.
  Serial.println("OK Komutu Alındı");
  esp.println("AT+CWMODE=1");                                 //ESP8266 modülünü client olarak ayarlıyoruz.
  while(!esp.find("OK")){                                     //Ayar yapılana kadar bekliyoruz.
    esp.println("AT+CWMODE=1");
    Serial.println("Modül Ayarı Yapılıyor....");
  }
  Serial.println("Modül Client olarak ayarlandı");
  Serial.println("Ağa Baglaniliyor...");
  esp.println("AT+CWJAP=\""+agAdi+"\",\""+agSifresi+"\"");    //Kablosuz Ağa bağlanıyoruz.
  while(!esp.find("OK"));                                     //Ağa bağlanana kadar bekliyoruz.
  Serial.println("Ağa Bağlanıldı.");
  delay(1000);

  lcd.clear();                                                 //LCD ekranı temizledik
  lcd.home();                                                  //Kursörü başa aldık
}


void loop() {
  esp.println("AT+CIPSTART=\"TCP\",\""+ip+"\",80");           //Thingspeak sitesine TCP ile bağlanıyoruz.
  if(esp.find("Error")){                                      //Bağlantı hatası kontrolü yapıyoruz.
    Serial.println("AT+CIPSTART Error");
  }
  lcd.home(); 
  lcd.print("ALTIN CANLI GR");
  lcd.setCursor(4, 1);
  lcd.print(altin());                                    
  Serial.println("Baglantı Kapatildi.");
  esp.println("AT+CIPCLOSE");                                //Bağlantıyı kapatıyoruz
  delay(1000); 

  
}

String Time()
{

  String rest = "AT+CIPSEND=90";
  rest += "\r\n";
  sendData(rest, 2000, 0); //Gönderilecek Karakter Sayısı. ( "AT+CIPSEND=90" )


  String hostt = "GET /apps/thinghttp/send_request?api_key=DOS4J9JD9IR1CADD";
  hostt += "\r\n";
  hostt += "Host:api.thingspeak.com";
  hostt += "\r\n\r\n\r\n\r\n\r\n";
  String Time = sendData(hostt, 2000, 1);  // GET mesajı isteği ( GET /apps/thinghttp/send_request?api_key=XXXXXXXXXXXXXXXX 
                                            //               Host: Host_server_name ) 
  
  
/********************** gelen verinin içinden sadece saatle ilgili bölümü alıyoruz. ****************************/
 int baslangic=Time.indexOf(':');
 Time=Time.substring(baslangic+1,baslangic+9);

  return (Time);

  
}

String altin()
{

 

  String rest = "AT+CIPSEND=90";
  rest += "\r\n";
  sendData(rest, 2000, 0); //Gönderilecek Karakter Sayısı. ( "AT+CIPSEND=90" )


  String hostt = "GET /apps/thinghttp/send_request?api_key=RHLEEPLGG17UK8TJ";
  hostt += "\r\n";
  hostt += "Host:api.thingspeak.com";
  hostt += "\r\n\r\n\r\n\r\n\r\n";
  String Altin = sendData(hostt, 2000, 1);  // GET request ( GET /apps/thinghttp/send_request?api_key=XXXXXXXXXXXXXXXX 
                                            //               Host: Host_server_name ) 
  
  
/********************** gelen verinin içinden sadece ilgili bölümü alıyoruz. ****************************/
 int baslangic=Altin.indexOf(':');
 Altin=Altin.substring(baslangic+1,baslangic+9);

  return (Altin);

  
}

String covid()
{

 

  String rest = "AT+CIPSEND=90";
  rest += "\r\n";
  sendData(rest, 3000, 0); //Gönderilecek Karakter Sayısı. ( "AT+CIPSEND=90" )


  String hostt = "GET /apps/thinghttp/send_request?api_key=GF15NKHSJR0PZOPJ";
  hostt += "\r\n";
  hostt += "Host:api.thingspeak.com";
  hostt += "\r\n\r\n\r\n\r\n\r\n";
  String Nufus = sendData(hostt, 3000, 1);  // GET request ( GET /apps/thinghttp/send_request?api_key=XXXXXXXXXXXXXXXX 
                                            //               Host: Host_server_name ) 
  
  
/********************** gelen verinin içinden sadece ilgili bölümü alıyoruz. ****************************/
 int baslangic=Nufus.indexOf(':');
 Nufus=Nufus.substring(baslangic+1,baslangic+11);

  return (Nufus);

  
}


String sendData(String komut, const int zamangecen, boolean debug)
{
  String response = "";

  esp.print(komut); // komut satırını espnin çıkışına yazdırıyoruz

  long int Zaman = millis();

  while ( (Zaman + zamangecen) > millis())
  {
    while (esp.available())
    {

      // esp'nin bağlantısından gelen veri var ise
      char c = esp.read(); //her bir karakteri okuyup c ye yazdırıyoruz.
      response += c; // her karakteri response değişkeninin sonuna ekliyor ve alacağımız teksti oluşturuyoruz
    }
  }

  if (debug)
  {
    Serial.print(response);
  }

  return response;
}
