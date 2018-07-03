/*   SS2 toData and make something */

#include <SoftwareSerial.h>
#define Led 8
#define TX 3
#define RX 2
#define M0 13
#define M1 12
char c;
int count = 0;
SoftwareSerial mySerial(TX, RX);
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(Led, OUTPUT);

  //set up M0, M1 to module output
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);

  // set M0, M1 to level 0

  digitalWrite(M0, LOW);
  digitalWrite(M1, LOW);
}


void toData(char x  )
{
  if (mySerial.available() > 0)
  {
    c = mySerial.read();
    if (c == x)
    {
      count++;
      if (count == 5)
      {
        digitalWrite(Led, HIGH);
        delay(500);
        digitalWrite(Led, LOW);
        delay(500);
        count=0;
      }
    }
    delay(20);
  }
}

void loop() {
  toData('H');
}

