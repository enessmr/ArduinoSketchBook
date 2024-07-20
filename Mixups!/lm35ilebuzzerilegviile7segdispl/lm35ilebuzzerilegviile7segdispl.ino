#define TX_RATE 5

#define TX_DATA 11

const char *message = "Hello, world!";

int x=0;
float voltaj,santigrat,fahrenhayt; //Türkiye Cumhuriyeti İstiklal Marşı   
 
const int buzzer = 10; // buzzer pin7 ve GND'ye bağlı
 
//kullanılacak notalar
int a4, ad, b3, c3, cd, d3, dd, e3, f3, fd, g3, gd, a2, ad2, b2, c2, cd2, d2, dd2, e2, f2, fd2, g2, gd2, a3;
 
void setup()   
{
  pinMode (0, OUTPUT);
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);

  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  Serial.begin(9600); 
  pinMode(buzzer, OUTPUT);

  pinMode(TX_DATA, OUTPUT);

  for (int byte_idx = 0; byte_idx <strlen(message); byte_idx++) {
    char tx_byte = message[byte_idx];

    for (int bit_idx = 0; bit_idx < 8; bit_idx++) {
      bool tx_bit = tx_byte & (0x80 >> bit_idx);

      digitalWrite(TX_DATA, tx_bit);
      delay(1000 / TX_RATE);
    }
  }
  
//////////////////////  
// c  = do
// cd = do diyez
// d  = re
// dd = re diyez
// e  = mi
// f  = fa
// fd = fa diyez
// g  = sol
// gd = sol diyez
// a  = la
// ad = la diyez
// b  = si
///////////////////////
 
//notalara karşılık gelen frekans değerleri
a4=440;
ad=466;
b3=494;
 
c3=523;
cd=554;
d3=587;
dd=622;
e3=659;
f3 = 698;
fd = 740;
g3 = 784;
gd = 830;
 
a2 = 880;
ad2 = 932;
b3 = 988;
c2 = 1046;
cd2 = 1108;
d2 = 1174;
dd2 = 1244;
e2 = 1318;
f2 = 1396;
fd2 = 1480;
g2 = 1568;
gd2 = 1660;
a3 = 1760;
 
 
}  
 
void loop() 
{
 int i;
 for(i =0; i<10; i++){
  Rakam(i);
  delay(400);
 }

  x=analogRead(A0);
  voltaj=x*(5.0/1023.0);
  santigrat=voltaj/0.01;

  Serial.print("Voltaj: ");
  Serial.print(voltaj);
  Serial.print("V | ");

  Serial.print("Sıcaklık: ");
  Serial.print(santigrat);
  Serial.print("\xC2\xB0");
  Serial.print("C | ");

  fahrenhayt=(santigrat*9.0/5.0)+32.0;
  Serial.print(fahrenhayt);
  Serial.print("\xC2\xB0");
  Serial.println("F | ");

  delay(0);  

//Korkma Sönmez Bu Şafak  
    tone(buzzer, c3);
    delay(800);
    tone(buzzer, f3);
    delay(800);
    tone(buzzer, g3);
    delay(800);
    tone(buzzer, gd);
    delay(800);
    tone(buzzer, e3);
    delay(400);
    tone(buzzer, g3);
    delay(200);        
    tone(buzzer, f3);
    delay(1600);        
    noTone(buzzer);
    delay(300);
//Larda Yüzden Al Sancak
    tone(buzzer, f3);
    delay(800);        
    tone(buzzer, ad2);
    delay(800);        
    tone(buzzer, c2);
    delay(800);        
    tone(buzzer, cd2);
    delay(800);
    tone(buzzer, a4);
    delay(400);
    tone(buzzer, c2);
    delay(200);
    tone(buzzer, ad2);
    delay(1600);        
//Sönmeden Yurdumun Üstünde Tüten En Son Ocak O Be
    tone(buzzer, c2);
    delay(200);        
    tone(buzzer, ad2);
    delay(200);        
    tone(buzzer, c2);
    delay(200);        
    tone(buzzer, g3);
    delay(400);        
    noTone(buzzer);
    delay(100);  
    tone(buzzer, g3);
    delay(400);        
    tone(buzzer, ad);
    delay(200);
    tone(buzzer, gd);
    delay(400);   
    tone(buzzer, e3);
    delay(200);
    tone(buzzer, f3);
    delay(400);   
    tone(buzzer, g3);
    delay(200);
    tone(buzzer, gd);
    delay(400);        
    tone(buzzer, ad);
    delay(200);        
    tone(buzzer, c2);
    delay(400);        
    tone(buzzer, cd2);
    delay(200);        
    tone(buzzer, dd2);
    delay(400);        
    tone(buzzer, f2);
    delay(200);        
    tone(buzzer, dd2);
    delay(400);     
//Nim Milletimin
    tone(buzzer, dd);
    delay(200);
    tone(buzzer, d3);
    delay(200);
    tone(buzzer, dd);
    delay(200);
    tone(buzzer, c2);
    delay(800);
    tone(buzzer, ad);
    delay(800);
    tone(buzzer, gd);
    delay(1600);
// Yıldızıdır Parlayacak O benim
    tone(buzzer, c3);
    delay(200);
    tone(buzzer, b3);
    delay(200);
    tone(buzzer, c3);
    delay(200);
    tone(buzzer, g3);
    delay(800);
    tone(buzzer, c3);
    delay(800);
    tone(buzzer, c2);
    delay(800);
    tone(buzzer, ad);
    delay(200);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, g3);
    delay(400);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, f3);
    delay(800);
//Dir O Benim Milletimindir Ancak
    tone(buzzer, f2);
    delay(800);
    tone(buzzer, dd2);
    delay(200);
    tone(buzzer, cd2);
    delay(400);
    tone(buzzer, c2);
    delay(200);
    tone(buzzer, ad);
    delay(400);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, g3);
    delay(400);
    tone(buzzer, f3);
    delay(200);
    tone(buzzer, c2);
    delay(400);
    tone(buzzer, c3);
    delay(800);
    tone(buzzer, f3);
    delay(1600);
 
/////////////ikinci kıt'a
 
//Çatma Kurban Olayım
    tone(buzzer, c3);
    delay(800);
    tone(buzzer, f3);
    delay(800);
    tone(buzzer, g3);
    delay(800);
    tone(buzzer, gd);
    delay(800);
    tone(buzzer, e3);
    delay(400);
    tone(buzzer, g3);
    delay(200);        
    tone(buzzer, f3);
    delay(1600);        
    noTone(buzzer);
    delay(300);
//Çehreni Ey Nazlı Hilal
    tone(buzzer, f3);
    delay(800);        
    tone(buzzer, ad2);
    delay(800);        
    tone(buzzer, c2);
    delay(800);        
    tone(buzzer, cd2);
    delay(400);
    tone(buzzer, ad2);
    delay(400);
    tone(buzzer, a2);
    delay(400);
    tone(buzzer, c2);
    delay(400);
    tone(buzzer, ad2);
    delay(800);        
//Kahraman Irkıma Bir Gül Ne Bu Şiddet Bu Celal Sana
    tone(buzzer, c2);
    delay(200);        
    tone(buzzer, ad2);
    delay(200);        
    tone(buzzer, c2);
    delay(200);        
    tone(buzzer, g3);
    delay(400);        
    noTone(buzzer);
    delay(100);  
    tone(buzzer, g3);
    delay(400);        
    tone(buzzer, ad);
    delay(200);
    tone(buzzer, gd);
    delay(400);   
    tone(buzzer, e3);
    delay(200);
    tone(buzzer, f3);
    delay(400);   
    tone(buzzer, g3);
    delay(200);
    tone(buzzer, gd);
    delay(400);        
    tone(buzzer, ad);
    delay(200);        
    tone(buzzer, c2);
    delay(400);        
    tone(buzzer, cd2);
    delay(200);        
    tone(buzzer, dd2);
    delay(400);        
    tone(buzzer, f2);
    delay(200);        
    tone(buzzer, dd2);
    delay(400);     
//Olmaz Dökülen
    tone(buzzer, dd);
    delay(200);
    tone(buzzer, d3);
    delay(200);
    tone(buzzer, dd);
    delay(200);
    tone(buzzer, c2);
    delay(800);
    tone(buzzer, ad);
    delay(800);
    tone(buzzer, gd);
    delay(1600);
//Kanlarımız Sonra Helal Hakkıdır
    tone(buzzer, c3);
    delay(200);
    tone(buzzer, b3);
    delay(200);
    tone(buzzer, c3);
    delay(200);
    tone(buzzer, g3);
    delay(800);
    tone(buzzer, c3);
    delay(800);
    tone(buzzer, c2);
    delay(800);
    tone(buzzer, ad);
    delay(200);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, g3);
    delay(400);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, f3);
    delay(800);
//Hakk'a Tapan Milletimin İstiklal
    tone(buzzer, f2);
    delay(800);
    tone(buzzer, dd2);
    delay(200);
    tone(buzzer, cd2);
    delay(400);
    tone(buzzer, c2);
    delay(200);
    tone(buzzer, ad);
    delay(400);
    tone(buzzer, gd);
    delay(200);
    tone(buzzer, g3);
    delay(400);
    tone(buzzer, f3);
    delay(200);
    tone(buzzer, c2);
    delay(400);
    tone(buzzer, c3);
    delay(800);
    tone(buzzer, f3);
    delay(1600);
    
 
 
 
    noTone(buzzer);
    delay(300);
}

void Rakam(int rakam)
{
  switch(rakam)
  {
    case 0:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    break;

    case 1:
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    break;

    case 2:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    break;

    case 3:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    break;

    case 4:
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;
    
    case 5:
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;

    case 6:
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;

    case 7:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    break;

    case 8:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;

    case 9:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;
  }
}