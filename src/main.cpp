#include <Arduino.h>

const int CS  = 2;
const int SCLK = 3;
const int MOSI = 4;
const int CLK = 8;

void setup() {
  Serial.begin(9600);

  pinMode(CS, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(CLK, OUTPUT);
  Serial.println("Enter 3 bits, example: 101");
}

void loop() {
  if (Serial.available()) {

    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() == 3) {

      digitalWrite(CS, input[0] == '1' ? HIGH : LOW);
      digitalWrite(SCLK, input[1] == '1' ? HIGH : LOW);
      digitalWrite(MOSI, input[2] == '1' ? HIGH : LOW);

      Serial.print("CS = ");
      Serial.println(input[0]);

      Serial.print("SCLK = ");
      Serial.println(input[1]);

      Serial.print("MOSI = ");
      Serial.println(input[2]);

    }
    if (input.length() == 1)
    {
      
    }
     else {
      Serial.println("Please enter 1,3,4 bits only.");
    }
  }
}