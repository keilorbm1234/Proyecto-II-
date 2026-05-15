#pragma once
#ifndef ITERADORDISTRITO_H
#define ITERADORDISTRITO_H

#include <vector>
#include <memory>
#include <stdexcept>
#include "IEntidad.h"

class IteradorDistrito {
private:
    std::vector<std::shared_ptr<IEntidad>>::const_iterator actual;
    std::vector<std::shared_ptr<IEntidad>>::const_iterator fin;

public:
    IteradorDistrito(
        std::vector<std::shared_ptr<IEntidad>>::const_iterator inicio,
        std::vector<std::shared_ptr<IEntidad>>::const_iterator fin
    ) : actual(inicio), fin(fin) {
    }

    bool tieneSiguiente() const {
        return actual != fin;
    }

    std::shared_ptr<IEntidad> siguiente() {
        if (!tieneSiguiente()) {
            throw std::out_of_range("No hay mas elementos en el iterador del distrito.");
        }
        return *(actual++);
    }
};

#endif