#include <Arduino.h>
#include "peripheal.h"

Peripheal sensor = Peripheal();

void setup() {
  Serial.begin(115200);
  sensor.setName(String("lm35"));
  sensor.setId(10);
}

void loop() {
  sensor.getName();
  sensor.getId();
  while(1){
    ;;
  }
}

