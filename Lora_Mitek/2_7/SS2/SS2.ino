/*   SS2 toData and make something */

#include <SoftwareSerial.h>
#define Led 4
#define UAX 12
#define TX 11
#define RX 10
#define M0 7
#define M1 8
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


  //RXData();
  int se = 0,td = 0; // se: start_end || td: to_do
  String code = "";
  while (mySerial.available() > 0)
  {
    delay(2);  //delay to allow byte to arrive in input buffer
    c = mySerial.read();
    readString += c;
  }
//  if (readString.length() > 0) {
//    Serial.println(readString);
//    readString = "";
//  }


  String F, L;

  for (int i = 0; i <= 5; i++)
  {
    F += readString[i];
    L += readString[readString.length() - 5 + i];
  }
  Serial.println(F);
  Serial.println(L);


  
  // bật cờ nhận làm việc và chờ tắt
//  if (se == 0 && td == 0 && F == "staCmd")
//  {
//    Serial.println("Start");
////    se = 1;  Serial.print("se: "); Serial.println(se);
////    td = 1;  Serial.print("td: "); Serial.println(td);
//    code = F; Serial.println(code);
//  }
//
//  // tắt cờ nhận và chờ bật
//  if (se == 1 && td == 1 && F == "endCmd")
//  {
//    Serial.println("end");
////    se = 0; Serial.print("se: "); Serial.println(se);
////    td = 0; Serial.print("td: "); Serial.println(td);
//    code.remove(0, code.length()); Serial.println(code);
//  }

}

