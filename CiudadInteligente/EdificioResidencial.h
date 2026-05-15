#pragma once

#ifndef EDIFICIORESIDENCIAL_H
#define EDIFICIORESIDENCIAL_H

#include "EntidadBase.h"
#include "IConsumidor.h"
#include <fstream>
#include <iostream>

// PRINCIPIO DE SUSTITUCIÓN DE LISKOV (LSP):
// EdificioResidencial PUEDE sustituir a IEntidad en cualquier parte del código
// sin que el programa falle. Es un subtipo real.

class EdificioResidencial : public EntidadBase, public IConsumidor {
private:
    double consumoBase;
    int habitantes;

public:
    EdificioResidencial(std::string n, double base, int hab);
    double consumirEnergia() override;
    std::string getDetalleEstado() const override;
    void escribirTexto(std::ostream& os) const override;
    void escribirBinario(std::ofstream& os) const override;
    void leerBinario(std::ifstream& is) override;
};

#endif
