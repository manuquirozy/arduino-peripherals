#include <Arduino.h>
#include <peripheal.h>
#include <task.h>
#include <sensor.h>
#include <actuator.h>
#include "functions.h"
//header. Incluye las librerías, las clases y los archivos extra que necesita.

Sensor sensor = Sensor(String("lm35"), String("°C"));
//crea un objeto sensor de la clase Sensor con name=lm35 y units=°C. El id será aleatorio
Actuator actuator = Actuator(String("AX500"), String("Speed Controller"));
//crea un objeto actuator de la clase Actuator con name=AX500 y type=Speed Controller. EL id será aleatorio

void setup() {
  Serial.begin(115200); //inicializa el puerto serial con un baud rate de 115200 baudios
  sensor.attach(readTemp); //le adjunta a sensor la función readTemp
  actuator.attach(setSpeed); //le adjunta a actuator la función setSpeed
}

void loop() {
  Serial.println(sensor.run(0)); //escribe por el puerto serial el resultado de ejecutar la función readTemp con un argumento 0
  actuator.report(Serial); //escribe por el puerto serial name, id, "Actuator" y type del objeto actuator
  while(1){
    //este ciclo se repite infinitamente. Se hace para que solo se ejecute una vez lo del loop
  }
}

