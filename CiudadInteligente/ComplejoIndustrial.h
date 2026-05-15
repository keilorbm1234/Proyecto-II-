#pragma once
#include "EntidadBase.h"
#include "IProductor.h"
#include "IConsumidor.h"
#include <fstream>
#include <iostream>

class ComplejoIndustrial : public EntidadBase, public IProductor, public IConsumidor {
private:
    double produccionPropia;
    double consumoMaquinaria;

public:
    ComplejoIndustrial(std::string n, double prod, double cons);
    double producirEnergia() override;
    double consumirEnergia() override;
    std::string getDetalleEstado() const override;

    void escribirTexto(std::ostream& os) const override;
    void escribirBinario(std::ofstream& os) const override;
    void leerBinario(std::ifstream& is) override;
};