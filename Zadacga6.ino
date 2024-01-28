#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()) {
      String key = LoRa.readStringUntil('s');
      int num1 = extractNumber(key, 'k', '*');
      int num2 = extractNumber(key, '*', 's');
      
      Serial.print("Number 1: ");
      Serial.print(num1);
      Serial.print(", Number 2: ");
      Serial.println(num2);
    }
  }
}

int extractNumber(String str, char startChar, char endChar) {
  int startPos = str.indexOf(startChar) + 1;
  int endPos = str.indexOf(endChar, startPos);
  return str.substring(startPos, endPos).toInt();
}
