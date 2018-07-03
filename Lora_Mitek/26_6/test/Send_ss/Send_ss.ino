/*      SS1 sendData X/1s and Data = Z        */
#include <SoftwareSerial.h>
#define Led 8
#define TX 3
#define RX 2
#define M0 13
#define M1 12

SoftwareSerial mySerial(TX, RX);
void setup() 
  {
    mySerial.begin(9600);
    //set up M0, M1, Led to module output
    pinMode(M0, OUTPUT);
    pinMode(M1, OUTPUT);
    pinMode(Led, OUTPUT);
  
    // set M0, M1 to level 0
  
    digitalWrite(M0, LOW);
    digitalWrite(M1, LOW);
  }

int time_to_send = 0;

void sendData(const int TIME_FOR_SEND, String string_send) 
{
  if (millis() - time_to_send > TIME_FOR_SEND) 
  {
    time_to_send = millis();
    // TODO: boardcast data
    mySerial.print(string_send);
    delay(20);
//    digitalWrite(Led, HIGH);
//    delay(500);
//    digitalWrite(Led, LOW);
//    delay(500);
  }
}

void loop() 
{
  String X="Hello";
  const int Y=4000; 
  sendData(Y,X);
}
