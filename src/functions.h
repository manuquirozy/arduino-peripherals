#ifndef function_h //si cuando se está compilando el programa function_h no está definida entonces la define
#define function_h


#include <Arduino.h>
//incluye la librería de Arduino

float readTemp(int var){
  /*función que lee el puerto análogo 0 y retorna su valor
  remplacé el 0 por la variable var
  return (float(analogRead(0)/1023.0)*5.0); */
  return (float(analogRead(var)/1023.0)*5.0);
}

bool setSpeed(uint16_t duty){
  //recibe el duty cicle que debe tener el PWM que controla la velocidad del motor
  //debería retornar true o false. no se está usando duty
  char buff[50]; //crea una variable tipo char llamada buff con 50 caracteres
  sprintf(buff, "PWM set to %2d", duty); //guarda en buff (el buffer) "PWM set to $duty$"
  Serial.print(buff); //escribe en el puerto serial lo que hay en buff
  return true; //se agregó porque no se estaba retornando nada
}

#endif