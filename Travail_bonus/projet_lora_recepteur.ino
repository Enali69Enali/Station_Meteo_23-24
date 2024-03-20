#include <SPI.h>
#include <LoRa.h>

#define ss 4 //18 avec module LoRa
#define rst 14
#define dio0 26

void setup() {
  Serial.begin(9600);
  delay(100);
  while (!Serial);

  Serial.println("LoRa Receiver");

  SPI.begin();
  LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");
    
    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
