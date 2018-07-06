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

//for SS1

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
  if (X != 0) {
    return X;
  }
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

void TXData( int x, String string_send, String code)
{
  for (int i = 0; i < code.length(); i++)
    string_send += code[i];
  mySerial.println(x + string_send);
  delay(10);
}

void sendData_crop(String input_data, int PACK_SIZE, String code)
{
  // label for this node
  String data;
  int count = 0;
  TXData(NULL, "staCmd", code);

  int index = 0;
    while (count < input_data.length())
    {
      data = input_data.substring(count, min(count + PACK_SIZE, input_data.length()));
      TXData(index, data, code);
      count = count + PACK_SIZE;
      index++;
      delay(500);
    }
  TXData( NULL, "endCmd", code);
}

// for ss2
String readString1;
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

void receiveData(String pass)    // nhap pass de nhan tin hieu
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

void loop()
{
  //SS1

//  int time_for_send = 1000;
//  String data = "0endCmd";
////  String data = nhap_data(); // nhap data từ màng hình
//  if (data != 0)
//  { sendData(time_for_send, data);
//    Serial.println(data); // print data}
//  }


  String data1 = "Hello world, my name is LoRa";
  if (data1 != 0)
  {
    Serial.println(data1);
    sendData_crop(data1, 5, "_code");  // data / max_bit/ code
  }
  mySerial.println();
  delay (2000);
  //  SS2
  receiveData("abc");  // nếu data bắt đầu bằng abc thi thực hiện lệnh bên trong data
}
