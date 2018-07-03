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
  Serial.begin(9600);
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
    delay(2000);
  }
}

String nhap_data()
{
  String X;
  char c;
  while (Serial.available() > 0)
  {
    delay(2);
    c = Serial.read();
    X += c;
  }
    if (X != 0){
      return X;    
    }
}

void loop()
{
//  int time_for_send = 1000;
//  String data = nhap_data(); 
//  if (data != 0)
//  { sendData(time_for_send, data);
//    Serial.println(data); // print data}
//  }


  String data2 ="hello word";
  Serial.print(sizeof(data2));Serial.print("=");
  Serial.println(data2);
  delay (2000);
}
