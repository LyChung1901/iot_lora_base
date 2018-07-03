#include <SPI.h>
#include <LoRa.h>

int btn = 3;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setSpreadingFactor(10);
  LoRa.setSignalBandwidth(62.5E3);
  LoRa.crc();

  pinMode(btn, INPUT);
  Serial.println("Push the button switch for send packet");
}

void loop() {
  int data = digitalRead(btn);
  if (data == HIGH){
    Serial.println("Send packet");
    // send packet
    LoRa.beginPacket();
    LoRa.print("switch,");
    LoRa.endPacket();
  }
  delay(500);
}
