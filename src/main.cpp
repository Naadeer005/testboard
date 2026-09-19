#include <Arduino.h>

const int CS   = 2;
const int SCLK = 3;
const int key  = 4;
const int CLK  = 8;

void setup() {
  Serial.begin(9600);

  pinMode(CS, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(key, OUTPUT);
  pinMode(CLK, OUTPUT);
  
  Serial.println("Enter 1, 3, or 4 bits:");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    int len = input.length();

    // กรณีป้อน 3 หรือ 4 ตัวอักษร
    if (len == 3 || len == 4) {
      digitalWrite(CS,   input[0] == '1' ? HIGH : LOW);
      digitalWrite(SCLK, input[1] == '1' ? HIGH : LOW);
      digitalWrite(key,  input[2] == '1' ? HIGH : LOW);

      Serial.print("CS = ");   Serial.println(input[0]);
      Serial.print("SCLK = "); Serial.println(input[1]);
      Serial.print("key = ");  Serial.println(input[2]);
    }

    // กรณีป้อน 1 หรือ 4 ตัวอักษร (ยิง Pulse ไปที่ CLK)
    if (len == 1 || len == 4) {
      digitalWrite(CLK, HIGH);
      delay(250);
      digitalWrite(CLK, LOW);
      Serial.println("CLK Triggered");
    }

    // กรณีป้อนความยาวอื่นๆ
    if (len != 1 && len != 3 && len != 4) {
      Serial.println("Please enter 1, 3, or 4 bits only.");
    }
  }
}