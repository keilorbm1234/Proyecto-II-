#pragma once
#include <iostream>
#include <string>

class MedicionTrafico {
private:
    int vehiculos;
    double velocidadPromedio;
    double nivelCongestion;

public:
    MedicionTrafico(int vehiculos = 0, double velocidad = 0, double congestion = 0)
        : vehiculos(vehiculos),
        velocidadPromedio(velocidad),
        nivelCongestion(congestion) {
    }

    int getVehiculos() const {
        return vehiculos;
    }

    double getVelocidadPromedio() const {
        return velocidadPromedio;
    }

    double getNivelCongestion() const {
        return nivelCongestion;
    }

    // Sobrecarga del operador +
    MedicionTrafico operator+(const MedicionTrafico& otra) const {
        int totalVehiculos = vehiculos + otra.vehiculos;

        if (totalVehiculos == 0) {
            return MedicionTrafico();
        }

        double velocidadPonderada =
            ((velocidadPromedio * vehiculos) + (otra.velocidadPromedio * otra.vehiculos))
            / totalVehiculos;

        double congestionPromedio =
            (nivelCongestion + otra.nivelCongestion) / 2.0;

        return MedicionTrafico(totalVehiculos, velocidadPonderada, congestionPromedio);
    }

    // Sobrecarga del operador >
    bool operator>(const MedicionTrafico& otra) const {
        return nivelCongestion > otra.nivelCongestion;
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const MedicionTrafico& m) {
        os << "Vehiculos: " << m.vehiculos
            << ", Velocidad promedio: " << m.velocidadPromedio << " km/h"
            << ", Congestion: " << m.nivelCongestion << "%";
        return os;
    }
};
