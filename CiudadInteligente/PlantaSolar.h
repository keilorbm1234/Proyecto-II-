#pragma once
#include "EntidadBase.h"
#include "IProductor.h"
#include <fstream>
#include <iostream>
using namespace std;

// PRINCIPIO DE SUSTITUCIÓN DE LISKOV (LSP):
// PlantaSolar PUEDE sustituir a IEntidad en cualquier parte del código
// sin que el programa falle. Es un subtipo real.

class PlantaSolar : public EntidadBase, public IProductor {
private:
    double capacidadMaxima;
    double eficiencia;
public:
    PlantaSolar(string n, double cap);
    double producirEnergia() override;
    string getDetalleEstado() const override;

    // NUEVO: Implementación de Persistencia
    void escribirTexto(std::ostream& os) const override;
    void escribirBinario(std::ofstream& os) const override;
    void leerBinario(std::ifstream& is) override;
};

