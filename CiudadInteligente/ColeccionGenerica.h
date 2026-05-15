#pragma once
#ifndef COLECCIONGENERICA_H
#define COLECCIONGENERICA_H

#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
class ColeccionGenerica {
private:
    std::vector<std::shared_ptr<T>> elementos;

public:
    void agregar(const std::shared_ptr<T>& elemento) {
        elementos.push_back(elemento);
    }

    std::shared_ptr<T> obtener(size_t indice) const {
        if (indice >= elementos.size()) {
            throw std::out_of_range("Indice fuera de rango en ColeccionGenerica");
        }
        return elementos[indice];
    }

    const std::vector<std::shared_ptr<T>>& obtenerTodos() const {
        return elementos;
    }

    bool estaVacia() const {
        return elementos.empty();
    }

    size_t cantidad() const {
        return elementos.size();
    }

    void limpiar() {
        elementos.clear();
    }
};

#endif