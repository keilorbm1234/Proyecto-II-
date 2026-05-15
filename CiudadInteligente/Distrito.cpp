#include "Distrito.h"
#include "IProductor.h"
#include "IConsumidor.h"
#include "CentralEmergencias.h"
#include <iostream>

Distrito::Distrito(std::string n) : nombre(n), centralAsignada(nullptr) {}

void Distrito::setCentral(std::shared_ptr<CentralEmergencias> c) {
    this->centralAsignada = c;
}

void Distrito::alertarEmergencia(std::string causa) {
    if (centralAsignada) {
        centralAsignada->recibirAlerta("Emergencia en " + nombre + ": " + causa);
    }
}

void Distrito::agregarEdificio(std::shared_ptr<IEntidad> edificio) {
    edificios.push_back(edificio);
}

double Distrito::obtenerProduccionTotal() const {
    double total = 0;
    auto it = crearIterador();

    while (it.tieneSiguiente()) {
        auto e = it.siguiente();
        auto p = dynamic_cast<IProductor*>(e.get());
        if (p) {
            total += p->producirEnergia();
        }
    }

    return total;
}

double Distrito::obtenerConsumoTotal() const {
    double total = 0;
    auto it = crearIterador();

    while (it.tieneSiguiente()) {
        auto e = it.siguiente();
        auto c = dynamic_cast<IConsumidor*>(e.get());
        if (c) {
            total += c->consumirEnergia();
        }
    }

    return total;
}

std::string Distrito::getNombre() const {
    return nombre;
}

void Distrito::mostrarReporteDistrito() const {
    std::cout << "Distrito: " << nombre << " (" << edificios.size() << " edificios)\n";

    auto it = crearIterador();
    while (it.tieneSiguiente()) {
        auto e = it.siguiente();
        std::cout << "  - " << e->getNombre() << " [" << e->getDetalleEstado() << "]\n";
    }
}

void Distrito::setDelegado(std::shared_ptr<IEstrategiaEnergia> del) {
    delegadoEnergia = del;
}

void Distrito::gestionarCrisis() {
    if (delegadoEnergia) {
        delegadoEnergia->ejecutarAccion(this);
    }
}

const std::vector<std::shared_ptr<IEntidad>>& Distrito::getEdificios() const {
    return edificios;
}

void Distrito::limpiarEdificios() {
    edificios.clear();
}

IteradorDistrito Distrito::crearIterador() const {
    return IteradorDistrito(edificios.begin(), edificios.end());
}