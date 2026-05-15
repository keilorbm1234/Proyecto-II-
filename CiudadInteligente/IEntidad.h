#pragma once
#ifndef IENTIDAD_H
#define IENTIDAD_H
#include <string>
using namespace std;

// PRINCIPIO DE SEGREGACIÓN DE INTERFAZ (ISP):
// Creamos contratos pequeños (IEntidad, IProductor) en lugar de uno gigante.
// SOLID (I): Las clases no deben ser forzadas a implementar métodos que no usan.

class IEntidad {
public:
    virtual ~IEntidad() = default;
    virtual string getNombre() const = 0;
    virtual string getDetalleEstado() const = 0;
};

#endif