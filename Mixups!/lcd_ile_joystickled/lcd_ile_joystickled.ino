#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo; 

int pos = 0; 
int sensorValue = 0;
int xPin = A1; 
int yPin = A2; 
int ledK=2; int ledM=3; int ledY=4; int ledS=5;
int xPozisyon = 0;
int yPozisyon = 0;

void setup() {
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(ledK,OUTPUT); pinMode(ledM,OUTPUT); 
  pinMode(ledY,OUTPUT); pinMode(ledS,OUTPUT);
  lcd.backlight();
  Serial.begin(9600);
  lcd.init();
  myservo.attach(9);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   AUTOMATIC "); 
  lcd.setCursor(0,1);
  lcd.print("   CAR WIPER ");
  delay(5000);
}

void loop() 
{
xPozisyon = analogRead(xPin);
yPozisyon = analogRead(yPin);
if(xPozisyon<10){digitalWrite(ledK,HIGH);}else{digitalWrite(ledK,LOW);}
if(xPozisyon>1000){digitalWrite(ledM,HIGH);}else{digitalWrite(ledM,LOW);} 
if(yPozisyon<10){digitalWrite(ledY,HIGH);}else{digitalWrite(ledY,LOW);}
if(yPozisyon>1000){digitalWrite(ledS,HIGH);}else{digitalWrite(ledS,LOW);}

sensorValue = analogRead(A0);
Serial.println(sensorValue);
if(sensorValue>800){
  myservo.write(180);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    NO RAIN ");
  delay(1000);
  }
if(sensorValue<=800 && sensorValue>600){
  lcd.print("AMOUNT: LOW ");
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING");
  lcd.setCursor(0,1);
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                    
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(2000);
}

if(sensorValue<=600 && sensorValue>460){
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING   ");
  lcd.setCursor(0,1);
  lcd.print("AMOUNT: MEDIUM ");
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                   
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(1000);
}

if(sensorValue<460){
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING   ");
  lcd.setCursor(0,1);
  lcd.print("AMOUNT: HIGH    ");
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                    
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(100);
}

}