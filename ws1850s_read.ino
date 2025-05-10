#include "MFRC522_I2C.h"

MFRC522 mfrc522(0x28, 255);

// リーダーにかざされたタグが読み取り済みかを表すフラグ
// false : 読み取り後
// true  : 読み取り前
bool rfid_scanned = false;

void setup() {
  Wire.begin();
  mfrc522.PCD_Init();
  Serial.begin(115200);
  Serial.println("--- setup end ---");
}

void loop() {
  if (hasCard() && rfid_scanned == false) {
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();
    rfid_scanned = true;
  } else if (!hasCard()) {
    // カードがリーダーから離れたらフラグを下げる
    rfid_scanned = false;
  }
}

bool hasCard() {
  // NFCリーダの使用上、リーダーにタグを置きっぱなしにするとmfrc522.PICC_ReadCardSerial()がtrueとfalseを互い違いに返す
  // したがって2回連続で読み取って、タグがリーダーから離れたかを検証する
  for (int i = 0; i < 2; i++) {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      return true;
    }
  }
  return false;
}