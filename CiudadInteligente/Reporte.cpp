#include "Reporte.h"
#include <iostream>

Reporte::Reporte(string m, string c, string fH) : modulo(m), contenido(c), fechaHora(fH) {}

Reporte::Reporte(const Reporte& otro) : modulo(otro.modulo), contenido(otro.contenido), fechaHora(otro.fechaHora) {}

Reporte& Reporte::operator=(const Reporte& otro) {
    if (this != &otro) {
        modulo = otro.modulo; 
        contenido = otro.contenido;  
        fechaHora = otro.fechaHora; 
    }
   
    return *this; 
}

Reporte::~Reporte() {}

string Reporte::getModulo() const {
    return modulo; 
}

string Reporte::getContenido() const {
    return contenido;
}

string Reporte::getFechaHora() const {
    return fechaHora; 
}

void Reporte::mostrar() const {
    cout << "Modulo: " << modulo << " | Contenido: " << contenido << " | Fecha y hora: " << fechaHora << endl;
}