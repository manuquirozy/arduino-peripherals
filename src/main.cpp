#include <Arduino.h>
#include <sensor.h>

Sensor sensor = Sensor(String("lm35"), String("°C"));

float readTemp(int var){
  return (float(analogRead(0)/1023.0)*5.0);
}

void setup() {
  Serial.begin(115200);
  sensor.attach(readTemp);
}

void loop() {
  
  Serial.println(sensor.run(0));
  while(1){

  }
}

