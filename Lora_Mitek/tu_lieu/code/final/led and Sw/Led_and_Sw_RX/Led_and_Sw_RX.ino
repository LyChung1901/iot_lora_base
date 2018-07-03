// san tao STEM
#include <SoftwareSerial.h>

#define TX 3
#define RX 2
#define M0 13
#define M1 12
char c;
SoftwareSerial mySerial(TX, RX);
void setup() {
  mySerial.begin(9600);
  
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
  mySerial.print('H');
  delay(500);
  mySerial.print('L');
  delay(500);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
