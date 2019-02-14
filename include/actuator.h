
class Actuator: public Peripheal, public Task<bool, uint16_t> {
private:
  String type;
public:
  Actuator(String name, String type, uint16_t id = random(0, 0xFFFF)): Peripheal(name, id) {
      this->type = type;
  }
};