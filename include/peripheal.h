#include <Arduino.h>

class Peripheal {
    private:
        String name;
        uint16_t id;
    public:
        Peripheal(String name, uint16_t id);
        String getName();
        uint16_t getId();

};

Peripheal::Peripheal(String name, uint16_t id=random(0, 0xFFFF)) {
    this->name = name;
    this->id = id;
}

String Peripheal::getName(){
    return name;
}

uint16_t Peripheal::getId(){
    return id;
}

