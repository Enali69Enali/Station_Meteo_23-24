#include <LoRa.h> 
#include <SPI.h>

struct LoRa_param_s {
  int  txPower = 15; // 2 to 17 dB limited to 15 because the UCA antenna = +2dB
  long frequency_id = 2; // 863.2 to 868.1 Mhz
  long frequency_offset = 0;
  int  spreadingFactor = 12; // 7 to 12
  long signalBandwidth_id = 1; // 125, 250, 500 kHz tester 62.5
  int  codingRateDenominator = 8 ; // 5 to 8
  long preambleLength = 12; // 6 to 65535, 12 default
  int  syncWord = 0x12F2; // 1 to 8 bytes ; Note Sync Word values containing 0x00 byte(s) are forbidden
  //uint8_t OCP; // Over Current Protection control (mA)
} LoRa_param_1;

long frequency_values[] = {863.2E6, 863.5E6, 863.8E6, 864.1E6, 864.4E6, 864.7E6, 865.2E6, 865.5E6, 865.8E6, 866.1E6, 866.4E6, 867.7E6, 867.0E6, 868.0E6, 868.1E6}; // Hz
long signalBandwidth_values[] = {62500, 125000, 250000, 500000}; // Hz

void LoRa_start(struct LoRa_param_s  LR) {
  Serial.print("-------------------------------------\n");
  Serial.print("LoRa Frequency: ");
  Serial.println(frequency_values[LR.frequency_id]);
  
  if (!LoRa.begin(frequency_values[LR.frequency_id])) {
    Serial.println("LoRa init failed. Check your connections.");
  }
  Serial.print("LoRa Spreading Factor: "); 
  Serial.println(LR.spreadingFactor);
  LoRa.setSpreadingFactor(LR.spreadingFactor);

  Serial.print("LoRa Signal Bandwidth: "); 
  Serial.println(signalBandwidth_values[LR.signalBandwidth_id]);
  LoRa.setSignalBandwidth(signalBandwidth_values[LR.signalBandwidth_id]);
  
  Serial.print("LoRa codingRateDenominator: "); 
  Serial.println(LR.codingRateDenominator);
  LoRa.setCodingRate4(LR.codingRateDenominator);
  
  Serial.print("LoRa preambleLength: ");
  Serial.println(LR.preambleLength);
  LoRa.setPreambleLength(LR.preambleLength); 
  
  Serial.print("LoRa txPower: ");
  Serial.println(LR.txPower);
  LoRa.setTxPower(LR.txPower);
  
  Serial.println("LoRa enable CRC \n");
  
  LoRa.enableCrc(); 
  Serial.println("emetteur");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  //delay(1000);
  
  LoRa_start(LoRa_param_1);
  Serial.println("Emetteur");
}

void loop() {
  // put your main code here, to run repeatedly:
  String stringOne = "A"; //"Hello Sunshine"; 
  Serial.println("SEND "+stringOne);
  LoRa.beginPacket(); 
  LoRa.print(stringOne); 
  LoRa.endPacket();
  delay(1000);
}
