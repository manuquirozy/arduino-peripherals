#include <Arduino.h>
#include <ArduinoJson.h>
//usa la librería de Arduino y de ArduinoJson
//Json: JavaScript notation object. Son pares de nombre/valor. Como un diccionario de Python

class Peripheal {
    private:
        String name;
        uint16_t id;
    public:
        Peripheal(); //Constructor sin parámetros
        Peripheal(String name, uint16_t id); //Constructor con name y id
        String getName(); //Método para acceder a name
        String setName(String name); // Método para cambiar el valor de name
        uint16_t getId(); //Método para acceder a id
        uint16_t setId(uint16_t id); //Método para cambiar el valor de id
        void report(Stream &uart); //Método para escribir por un puerto determinado (uart) el nombre y el id del objeto
};

Peripheal::Peripheal(){}; //Constructor sin parámetros. Es el constructor por defecto

Peripheal::Peripheal(String name, uint16_t id=random(0, 0xFFFF)) {
    /*Constructor. Asigna a los parámetros name y id en el private el valor de los argumentos. Si no hay 
    id el valor por defecto es un número entero aleatorio positivo hasta 65535*/
    this->name = name;
    this->id = id;
}

String Peripheal::getName() {
    return name; //retorna el valor de name
}

uint16_t Peripheal::getId() {
    return id; //retorna el valor de id
}

String Peripheal::setName(String name) {
    return this->name = name; //sobreescribe el valor de name y retorna el nuevo valor de name
}

uint16_t Peripheal::setId(uint16_t id) {
    return this->id = id; //sobreescribe el valor de id y retorna el nuevo valor de id
}

void Peripheal::report(Stream &uart){
    //Aqui se crean objetos de las clases de la librería ArduinoJson
    StaticJsonBuffer<200> jsonBuffer; //crea un objeto (jsonBuffer) de la clase StaticJsonBuffer de tamaño 200
    JsonObject& res = jsonBuffer.createObject(); //crea un json llamado res
    res["name"] = this->getName(); //le asigna a "name" el valor de name 
    res["id"] = this->getId(); //le asigna a "id" el valor de id
    String out; //define el string out
    res.prettyPrintTo(out); //el método prettyPrintTo() convierte res a un string y lo guarda en out
    uart.println(out); //escribe el puerto uart el string out
};