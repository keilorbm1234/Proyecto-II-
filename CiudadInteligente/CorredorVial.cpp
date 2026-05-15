#include "CorredorVial.h"
#include <iostream>

CorredorVial::CorredorVial(std::string nombre)
    : nombre(nombre) {
}

CorredorVial::~CorredorVial() = default;

CorredorVial::CorredorVial(CorredorVial&& otro) noexcept
    : nombre(std::move(otro.nombre)),
    componentes(std::move(otro.componentes)) {
}

CorredorVial& CorredorVial::operator=(CorredorVial&& otro) noexcept {
    if (this != &otro) {
        nombre = std::move(otro.nombre);
        componentes = std::move(otro.componentes);
    }

    return *this;
}

void CorredorVial::agregarComponente(std::unique_ptr<ComponenteVial> componente) {
    componentes.push_back(std::move(componente));
}

std::string CorredorVial::getNombre() const {
    return nombre;
}

MedicionTrafico CorredorVial::obtenerMedicionTotal() const {
    MedicionTrafico total;

    for (const auto& componente : componentes) {
        total = total + componente->obtenerMedicionTotal();
    }

    return total;
}

void CorredorVial::mostrarReporte(int nivel) const {
    std::string espacios(nivel * 2, ' ');

    std::cout << espacios << "+ Corredor vial: " << nombre << "\n";

    for (const auto& componente : componentes) {
        componente->mostrarReporte(nivel + 1);
    }

    std::cout << espacios << "  Total corredor: " << obtenerMedicionTotal() << "\n";
}
