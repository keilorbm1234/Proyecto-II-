#pragma once
#include "SensorTraficoExterno.h"
#include "MedicionTrafico.h"

class AdaptadorSensorTrafico {
private:
    SensorTraficoExterno sensorExterno;

public:
    AdaptadorSensorTrafico(const SensorTraficoExterno& sensor)
        : sensorExterno(sensor) {
    }

    MedicionTrafico obtenerMedicion() const {
        return MedicionTrafico(
            sensorExterno.leerConteoVehicular(),
            sensorExterno.leerVelocidadMedia(),
            sensorExterno.leerOcupacionVia()
        );
    }

    std::string getNombreSensor() const {
        return sensorExterno.obtenerCodigoSensor();
    }
};