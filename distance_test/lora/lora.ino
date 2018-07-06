#include <SoftwareSerial.h>
#define Led 4
#define UAX 12
#define TX 11
#define RX 10
#define M0 7
#define M1 8

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

void sendData(const int TIME_FOR_SEND) 
{
  if (millis() - time_to_send > TIME_FOR_SEND) 
  {
    time_to_send = millis();
    // TODO: boardcast data
    mySerial.print('H');
    delay(20);
    digitalWrite(Led, HIGH);
    delay(500);
    digitalWrite(Led, LOW);
    delay(500);
  }
}

//for SS2
char c;
void RXData(char x  )
{
  if (mySerial.available() > 0)
  {
    c = mySerial.read();
    if (c == x)
    {
        digitalWrite(Led, HIGH);
        delay(500);
        digitalWrite(Led, LOW);
        delay(500);
    }
    delay(20);
  }
}
void loop() 
{
  sendData(2000);
  RXData('H');
}
