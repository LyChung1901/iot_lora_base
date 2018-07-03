/*   SS2 toData and make something */

#include <SoftwareSerial.h>
#define Led 8
#define TX 3
#define RX 2
#define M0 13
#define M1 12
char c;
String readString;
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


void toData( )
{
  if (mySerial.available() > 0)
  {
    c = mySerial.read();
    delay(20);
    Serial.println(c);
  }
}

void loop() {
  //toData();
  while (mySerial.available()>0) 
  {
    delay(2);  //delay to allow byte to arrive in input buffer
     c = mySerial.read();
    readString += c;
  }

  if (readString.length() >0) {
    Serial.println(readString);

    readString="";
  } 
}

