#include "MFRC522_I2C.h"

MFRC522 mfrc522(0x28,0);

void setup() {
  Wire.begin();
  mfrc522.PCD_Init();
  Serial.begin(115200);
  Serial.println("--- setup end ---");
}

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    delay(200);
    return;
  }
  for (byte i=0; i<mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i]<0x10?" 0":" ");
    Serial.print(mfrc522.uid.uidByte[i],HEX);
  }
  Serial.println();
  delay(500);
}