#include <Arduino.h>
#include "peripheal.h"

Peripheal sensor = Peripheal(String("temp"));

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensor.getName();
}