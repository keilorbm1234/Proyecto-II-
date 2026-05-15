#pragma once
#ifndef ANALIZADORGENERICO_H
#define ANALIZADORGENERICO_H

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "IEntidad.h"

template <typename T>
void mostrarColeccion(const std::vector<std::shared_ptr<T>>& elementos, const std::string& titulo) {
    std::cout << "\n===== " << titulo << " =====\n";
    if (elementos.empty()) {
        std::cout << "No hay elementos registrados.\n";
        return;
    }

    for (const auto& e : elementos) {
        std::cout << "- " << e->getNombre() << " [" << e->getDetalleEstado() << "]\n";
    }
}

template <typename Interfaz>
double sumarPorInterfaz(const std::vector<std::shared_ptr<IEntidad>>& elementos,
    double (Interfaz::* metodo)()) {
    double total = 0.0;

    for (const auto& e : elementos) {
        Interfaz* ptr = dynamic_cast<Interfaz*>(e.get());
        if (ptr) {
            total += (ptr->*metodo)();
        }
    }

    return total;
}

#endif