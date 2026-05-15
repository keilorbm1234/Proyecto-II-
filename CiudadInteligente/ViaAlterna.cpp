#include "ViaAlterna.h"
#include <iostream>

ViaAlterna::ViaAlterna(std::string nombre, double longitud, const AdaptadorSensorTrafico& sensor)
    : nombre(nombre),
    longitudKm(longitud),
    sensor(new AdaptadorSensorTrafico(sensor)) {
}

ViaAlterna::~ViaAlterna() {
    delete sensor;
}

ViaAlterna::ViaAlterna(const ViaAlterna& otro)
    : nombre(otro.nombre),
    longitudKm(otro.longitudKm),
    sensor(new AdaptadorSensorTrafico(*otro.sensor)) {
}

ViaAlterna& ViaAlterna::operator=(const ViaAlterna& otro) {
    if (this != &otro) {
        delete sensor;

        nombre = otro.nombre;
        longitudKm = otro.longitudKm;
        sensor = new AdaptadorSensorTrafico(*otro.sensor);
    }

    return *this;
}

std::string ViaAlterna::getNombre() const {
    return nombre;
}

MedicionTrafico ViaAlterna::obtenerMedicionTotal() const {
    return sensor->obtenerMedicion();
}

void ViaAlterna::mostrarReporte(int nivel) const {
    std::string espacios(nivel * 2, ' ');

    std::cout << espacios << "- Segmento: " << nombre << "\n";
    std::cout << espacios << "  Longitud: " << longitudKm << " km\n";
    std::cout << espacios << "  Sensor: " << sensor->getNombreSensor() << "\n";
    std::cout << espacios << "  Medicion: " << obtenerMedicionTotal() << "\n";
}
