#pragma once
#include <vector>
#include <memory>
#include "Distrito.h"
#include "CentralEmergencias.h"

// PRINCIPIO ABIERTO/CERRADO (OCP):
// El Motor está CERRADO a la modificación (no lo tocaremos para agregar nuevos edificios)
// pero ABIERTO a la extensión (podemos crear infinitas clases que hereden de IEntidad).

class GestorCiudad {
private:
    std::vector<std::shared_ptr<Distrito>> distritos;
    std::shared_ptr<CentralEmergencias> centralUrbana; // La central del motor
    int turnoActual;

public:
    GestorCiudad(std::shared_ptr<CentralEmergencias> central);
    void agregarDistrito(std::shared_ptr<Distrito> d);
    void procesarTurno();
};
