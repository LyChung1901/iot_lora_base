/*      SS1 sendData X/1s and Data = Z        */
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

int time_to_send = 0;

void sendData( String string_send, String code)
{
  for (int i = 0; i < code.length(); i++)
    string_send += code[i];

  mySerial.print(string_send);
  delay(100);
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
  if (X != 0) {
    return X;
  }
}

void loop()
{
  int count, index = 0;
  int PACK_SIZE = 5;
  String data,dat_next;
  String input_data = "crop data from position 0 to min";
while (count <= input_data.length())
              {
                data = input_data.substring(count, min(count + PACK_SIZE, input_data.length()));
                mySerial.print(index);
                sendData( data, "_code");
                count = count + PACK_SIZE;
                index++;
                delay(100);
              }
                 sendData( "\nendCmd" , "_code"); 
Serial.println("");
  delay (2000);
}
