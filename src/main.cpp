#include <Arduino.h>
#include <PinChangeInt.h>


int CLOCK = A4;
int pins[] = { A3, A2, A1, A0, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };
int nPins = 16;

void print() {
  int pin;
  unsigned int out = 0;
  for (pin = 0; pin < 16; pin++) {
    int bit  = digitalRead(pins[pin]) ? 1 : 0;
    Serial.print(bit == 1 ? "1" : "0");
    out = (out << 1) + bit;
  }
  Serial.print("  ");
  char address[15];
  sprintf(address, "%04x", out);
  Serial.println(address);
}

void setup() {
  Serial.begin(9600);
  while (!Serial);

  int pin = 0;
  for (pin = 0; pin < nPins; pin++) {
    pinMode(pins[pin], INPUT);
  }
  pinMode(CLOCK, INPUT);
  attachPinChangeInterrupt(CLOCK, print, RISING);

  Serial.println("Setup completed");
}

void loop() {
}