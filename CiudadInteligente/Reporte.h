#pragma once
#include <string>
using namespace std;

class Reporte {
private:
    string modulo;
    string contenido; 
    string fechaHora;
public: 
    //Esta clase contiene el Big 3 rule (destructor, constructor copia y operador de asignación)
    Reporte(string m, string c, string fH); 
    Reporte(const Reporte& otro); 
    Reporte& operator=(const Reporte& otro); 
    ~Reporte(); 
    string getModulo() const; 
    string getContenido() const;
    string getFechaHora() const;
    void mostrar() const; 
};

