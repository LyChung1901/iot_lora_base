// san tao STEM
#include <SoftwareSerial.h>
#define Led 8
#define TX 3
#define RX 2
#define M0 13
#define M1 12
char c;
int count = 0;
int stay1 = 1;
int stay2 = 0;
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

int time_to_send = 0;

void sendData(const int TIME_FOR_SEND) {
  if (millis() - time_to_send > TIME_FOR_SEND) {
    time_to_send = millis();
    // TODO: boardcast data
    //    mySerial.print('O');
    //    delay(20);
    //    stay2 = 1;
    //    stay1 = 0;
    digitalWrite(Led, HIGH);
    delay(500);
    digitalWrite(Led, LOW); delay(20);
  }
}


void loop() {

  sendData(2000);

  //nhan tin hieu
  if (stay2 == 1)
  {
    if (mySerial.available() > 0)
    {
      c = mySerial.read();
      if (c == 'H')
      {
        digitalWrite(Led, HIGH);
        delay(500);
        digitalWrite(Led, LOW); delay(20);
        stay1 = 1;
        stay2 = 0;
      }
    }
    delay(20);
  }
}
