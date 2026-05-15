#pragma once
#include <string>

class SensorTraficoExterno {
private:
    std::string codigoSensor;
    int conteoVehiculos;
    double velocidadMedia;
    double ocupacionVia;

public:
    SensorTraficoExterno(std::string codigo, int vehiculos, double velocidad, double ocupacion)
        : codigoSensor(codigo),
        conteoVehiculos(vehiculos),
        velocidadMedia(velocidad),
        ocupacionVia(ocupacion) {
    }

    std::string obtenerCodigoSensor() const {
        return codigoSensor;
    }

    int leerConteoVehicular() const {
        return conteoVehiculos;
    }

    double leerVelocidadMedia() const {
        return velocidadMedia;
    }

    double leerOcupacionVia() const {
        return ocupacionVia;
    }
};