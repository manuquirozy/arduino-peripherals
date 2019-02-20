
class Sensor: public Peripheal, public Task<float, int> {
  //clase Sensor que hereda de Peripheal y Task con tipos flotante y entero en el template
private:
  String units;
public:
  Sensor(String name, String units, uint16_t id = random(0, 0xFFFF)): Peripheal(name, id) {
    /*constructor. Si no se le da un valor de id crea un id aleatorio. Ejecuta primero el constructor de 
    Peripheal con los parámetros dados por name y id*/
    this->units = units; //asigna el valor de units al units propio del objeto
  }
};