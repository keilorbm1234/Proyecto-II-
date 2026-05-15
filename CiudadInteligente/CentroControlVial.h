#pragma once
#include "ComponenteVial.h"
#include <iostream>

class CentroControlVial {
private:
    CentroControlVial() = default;

public:
    CentroControlVial(const CentroControlVial&) = delete;
    CentroControlVial& operator=(const CentroControlVial&) = delete;

    static CentroControlVial& getInstancia() {
        static CentroControlVial instancia;
        return instancia;
    }

    void evaluarCongestion(const ComponenteVial& via) {
        MedicionTrafico medicion = via.obtenerMedicionTotal();

        std::cout << "\n[Centro de Control Vial]\n";
        std::cout << "Evaluando: " << via.getNombre() << "\n";
        std::cout << medicion << "\n";

        if (medicion.getNivelCongestion() >= 75) {
            std::cout << "Estado: Congestion critica. Activar rutas alternas.\n";
        }
        else if (medicion.getNivelCongestion() >= 45) {
            std::cout << "Estado: Congestion moderada. Ajustar semaforos inteligentes.\n";
        }
        else {
            std::cout << "Estado: Flujo normal.\n";
        }
    }
};