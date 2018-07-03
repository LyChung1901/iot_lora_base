
#include <SoftwareSerial.h>
#define Led 8
#define TX 3
#define RX 2
#define M0 13
#define M1 12
char c;
SoftwareSerial mySerial(TX, RX);
void setup() {
  mySerial.begin(9600);
  pinMode(Led,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  //set up M0, M1 to module output
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);

  // set M0, M1 to level 0

  digitalWrite(M0, LOW);
  digitalWrite(M1, LOW);
}

void loop() {
  if (mySerial.available() > 0) {
    // doc gia tri tu monitor va gui den lora
        c = mySerial.read();
    if (c == 'H')
      digitalWrite(Led, HIGH); 
    else
      digitalWrite(Led, LOW);   
  }
  delay(20);
}
