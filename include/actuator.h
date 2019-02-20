
class Actuator: public Peripheal, public Task<bool, uint16_t > { 
//uint16_t es una variable entera de 16 bits sin signo
//Clase Actuator. Hereda de Peripheal y Task. Task usa variables booleanas y enteras de 16 bits en el template
private:
  String type;
public:
  Actuator(String name, String type, uint16_t id = random(0, 0xFFFF)): Peripheal(name, id) {
    //0xFFFF es el valor máximo en hexadecimal de un entero de 16 bits (65535)
    //La clase recibe 3 parámetros: name, type, id. name y id son heredados de Peripheal.
    //El id tiene un valor aleatorio por defecto
    /*Primero ejecuta el constructor de Peripheal con name y id (no ejecuta el constructor por defecto
    porque se especifica que se debe ejecutar el que recibe name y id como parámetros). Luego ejecuta 
    el resto del constructor de Actuator*/
      this->type = type; //guarda el valor de type del argumento en la variable type privada
    //Almacena el valor de type
  }
  String getType(); //método para acceder al valor de Type
  void report(Stream &uart); /*retorna un string con las características del actuador y lo imprime al puerto
  uart indicado en el argumento de report*/
};

String Actuator::getType(){
  return this->type; //retorna el valor de Type
};

void Actuator::report(Stream &uart){
    StaticJsonBuffer<200> jsonBuffer; //crea un objeto (jsonBuffer) de tipo StaticJsonBuffer con un tamaño de 200
    JsonObject& res = jsonBuffer.createObject(); //crea un objeto json llamado res
    res["name"] = this->getName(); //le asigna a "name" el valor de name
    res["id"] = this->getId(); //le asigna a "id" el valor de id
    res["type"] = "Actuator"; //le asigna a type el valor de Actuator
    res["act_type"] = this->getType(); //le asigna a act_type el valor de type
    String out; //crea un string con nombre out
    res.prettyPrintTo(out);//el método prettyPrintTo() convierte res a un string y lo guarda en out
    uart.println(out); //escribe en el puerto uart el string out
}