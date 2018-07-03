#include <SPI.h>
#include <LoRa.h>

int led = 3;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Lora Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Lora Error");
    while (1);
  }
  LoRa.setSpreadingFactor(10);
  LoRa.setSignalBandwidth(62.5E3);
  LoRa.crc();

  pinMode(led, OUTPUT);
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {

    // received a packet
    Serial.print("received a packet : ");

    // read packet
    while (LoRa.available()) {
      char data = LoRa.read();
      Serial.print(data);
      if (data == '1'){
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
      }
      //Serial.print((char)LoRa.read());
    }
    Serial.println(" ");
  }
}

