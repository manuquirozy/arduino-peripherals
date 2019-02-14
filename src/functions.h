#ifndef function_h
#define function_h

#include <Arduino.h>

float readTemp(int var){
  return (float(analogRead(0)/1023.0)*5.0);
}

#endif