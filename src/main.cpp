#include <Arduino.h>
#include <sensor.h>
#include "functions.h"

Sensor sensor = Sensor(String("lm35"), String("°C"));

void setup() {
  Serial.begin(115200);
  sensor.attach(readTemp);
}

void loop() {
  Serial.println(sensor.run(0));
  while(1){

  }
}

