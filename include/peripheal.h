#include <Arduino.h>

class Peripheal {
    private:
        String name;
        uint16_t id;
    public:
        Peripheal();
        Peripheal(String name, uint16_t id);
        String getName();
        String setName(String name);
        uint16_t getId();
        uint16_t setId(uint16_t id);

};

Peripheal::Peripheal(String name, uint16_t id=random(0, 0xFFFF)) {
    this->name = name;
    this->id = id;
}

String Peripheal::getName() {
    return name;
}

uint16_t Peripheal::getId() {
    return id;
}

String Peripheal::setName(String name) {
    this->name = name;
}

uint16_t Peripheal::setId(uint16_t id) {
    this->id = id;
}