#include <Arduino.h>
//usa la librería de Arduino

template<typename T, typename P>
//template. Se usa para que la clase pueda funcionar para cualquier tipo T y P de variables

class Task {
public:
    Task(); //constructor vacío
    void attach(T (*fun)(P)){
    //este método recibe una función que retorna un valor tipo T y cuyo argumento es de tipo P y la almacena en target
        this->target = fun;
    };
    T run(P var){
    //este método ejecuta la función que se encuentra en target con el argumento var que debe ser de tipo P y retorna el valor tipo T
        return this->target(var);
    }
private:
    T (*target)(P); //contiene la función target con argumento tipo P que retorna un tipo T
};

template<typename T, typename P>
Task<T, P>::Task(){} //Task<T, P> define los tipos del template 