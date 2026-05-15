#pragma once
#ifndef DISTRITO_H
#define DISTRITO_H

#include <vector>
#include <memory>
#include <string>
#include "IEntidad.h"
#include "IEstrategiaEnergia.h"
#include "IteradorDistrito.h"

class CentralEmergencias;

class Distrito {
private:
    std::string nombre;
    std::vector<std::shared_ptr<IEntidad>> edificios;

    std::shared_ptr<CentralEmergencias> centralAsignada;
    std::shared_ptr<IEstrategiaEnergia> delegadoEnergia;

public:
    Distrito(std::string n);

    void setCentral(std::shared_ptr<CentralEmergencias> c);

    void agregarEdificio(std::shared_ptr<IEntidad> edificio);
    double obtenerProduccionTotal() const;
    double obtenerConsumoTotal() const;
    std::string getNombre() const;
    void mostrarReporteDistrito() const;

    void alertarEmergencia(std::string causa);
    void setDelegado(std::shared_ptr<IEstrategiaEnergia> del);
    void gestionarCrisis();

    const std::vector<std::shared_ptr<IEntidad>>& getEdificios() const;
    void limpiarEdificios();

    // Patron Iterator
    IteradorDistrito crearIterador() const;
};

#endif