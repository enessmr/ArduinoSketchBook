void setup() {
  pinMode(7,INPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // Ses seviyesini dijital olarak oku (dijital pin)
  if (digitalRead(7)==HIGH) // Gürültü miktarını eşik değeri ile kıyasla
  {
    Serial.print("Gürültü eşik değer üstünde...");
  }
  else 
  {
    Serial.print("Gürültü eşik değer altında...");
  }
  
  // Ses seviyesini analog olarak oku (analog pin)
  // Bu kısım 3 pinli sensörlerde silinmelidir. 
  int deger = analogRead(A0);  // Gürültü miktarını 0-1024 arasında oku
  Serial.println(deger);  
  
  delay(2000);  // Bir sonraki okuma için 2 saniye bekle
}
