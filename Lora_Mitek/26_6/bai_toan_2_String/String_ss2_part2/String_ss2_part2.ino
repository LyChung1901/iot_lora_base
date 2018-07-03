/*   SS2 toData and make something */

#include <SoftwareSerial.h>
#define Led 4
#define UAX 12
#define TX 11
#define RX 10
#define M0 7
#define M1 8

String readString1;
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
  char c;
  if (mySerial.available() > 0)
  {
    c = mySerial.read();
    delay(20);
    Serial.println(c);
  }
}

int check_pass(String file, String pass)  // kiem tra pass co dung hay hk
{
  int n = pass.length();
  String temp;
  for (int i = 0; i < n; i++)
  {
    temp += file[i];
  }
  if (temp == pass)
    return 1;
  else return 0;
}

void RxData(String pass)    // nhap pass de nhan tin hieu
{
  char c;
  while (mySerial.available() > 0)
  {
    delay(2);  //delay to allow byte to arrive in input buffer
    c = mySerial.read(); // doc cac ky tu tren myserial
    readString1 += c; 
  }
   int n = pass.length();
  if (check_pass(readString1, pass) == 1)  // check pass
  {
    for (int i = 0; i < n; i++)
    {
      readString1[i] = 0;  // loai bo pass
    }
    if (readString1.length() > 0) {
      Serial.println(readString1);  // print data
      readString1 = "";
    }
  }
}

void loop() {
  RxData("abc");  
}

