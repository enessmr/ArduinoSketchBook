#include <IRremote.h>

IRrecv irrecv(2);
decode_results results;

#define BUTON1 4294967295
#define BUTON2 4294967295
#define BUTON3 4294967295
#define BUTON4 4294967295
#define BUTON5 4294967295
#define BUTON6 4294967295
#define BUTON7 4294967295
#define BUTON8 4294967295
#define BUTON9 4294967295
#define YILDIZ 4294967295
#define BUTON0 4294967295
#define YUKARI 4294967295
#define SOL 4294967295
#define OK 4294967295
#define SAG 4294967295
#define ASAGI 4294967295

const int GREEN_LED_PIN = 3;  // Yeşil LED pini
const int RED_LED_PIN = 4;    // Kırmızı LED pini

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if (results.value == BUTON0) {  // Doğru buton kodunu buraya girin
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
    } else {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
    }
    irrecv.resume();
  }
}
