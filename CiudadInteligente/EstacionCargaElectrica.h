#pragma once
#ifndef ESTACIONCARGAELECTRICA_H
#define ESTACIONCARGAELECTRICA_H

#include "EntidadBase.h"
#include "IConsumidor.h"
#include <fstream>
#include <iostream>

class EstacionCargaElectrica : public EntidadBase, public IConsumidor {
private:
    int cargadoresTotales;
    int vehiculosCargando;
    double consumoPorVehiculo;

public:
    EstacionCargaElectrica(std::string n, int cargadores, int vehiculos, double consumoUnitario);

    double consumirEnergia() override;
    std::string getDetalleEstado() const override;

    void conectarVehiculo();
    void desconectarVehiculo();

    void escribirTexto(std::ostream& os) const override;
    void escribirBinario(std::ofstream& os) const override;
    void leerBinario(std::ifstream& is) override;
};

#endif