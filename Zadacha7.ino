#include <Arduino.h>
#include <ArduinoRSA.h>

const unsigned long M = 10; 

void setup() {
  Serial.begin(9600);
  while (!Serial);

  RSAKeyPair keyPair = RSA::generateKeyPair(128); // 128 - длина ключа в битах

  Serial.print("Открытый ключ: [");
  Serial.print(keyPair.publicKey.e);
  Serial.print(", ");
  Serial.print(keyPair.publicKey.n);
  Serial.println("]");

  unsigned long encrypted = RSA::encrypt(M, keyPair.publicKey);
  Serial.print("Зашифрованное число: ");
  Serial.println(encrypted);

  unsigned long decrypted = RSA::decrypt(encrypted, keyPair.privateKey);
  Serial.print("Дешифрованное число: ");
  Serial.println(decrypted);
}

void loop() {
}
