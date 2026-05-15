#pragma once
#include <string>
#include "MedicionTrafico.h"

class ComponenteVial {
public:
    virtual ~ComponenteVial() = default;

    virtual std::string getNombre() const = 0;
    virtual MedicionTrafico obtenerMedicionTotal() const = 0;
    virtual void mostrarReporte(int nivel = 0) const = 0;
};