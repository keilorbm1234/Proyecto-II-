#include "GestorCiudad.h"
#include "CiudadException.h"
#include "DeficitRecursoException.h"
#include <iostream>

GestorCiudad::GestorCiudad(std::shared_ptr<CentralEmergencias> central)
    : centralUrbana(central), turnoActual(0) {
}

void GestorCiudad::agregarDistrito(std::shared_ptr<Distrito> d) {
    distritos.push_back(d);
    // PRINCIPIO DE INVERSIÓN DE CONTROL: El motor vincula al distrito con la central
    d->setCentral(centralUrbana);
}

void GestorCiudad::procesarTurno() {
    turnoActual++;
    double ciudadProd = 0;
    double ciudadCons = 0;

    std::cout << "\n========== TURNO SIMULADO: " << turnoActual << " ==========\n";

    for (auto& dist : distritos) {
        dist->mostrarReporteDistrito();

        double prodDistrito = dist->obtenerProduccionTotal();
        double consDistrito = dist->obtenerConsumoTotal();

        ciudadProd += prodDistrito;
        ciudadCons += consDistrito;

        // Si el distrito entra en déficit, se activa la gestión local y se reporta
        if (consDistrito > prodDistrito) {
            dist->gestionarCrisis();
            dist->alertarEmergencia("Déficit energético crítico");

            // DOWNCAST / UPCAST: La central inspecciona el distrito
            // Aquí se pasa el shared_ptr de Distrito (se trata como tal)
            if (centralUrbana) {
                centralUrbana->realizarInspeccion(dist);
            }

            // IMPORTANTE: lanzar por valor, no con new
            throw DeficitRecursoException(dist->getNombre(), consDistrito - prodDistrito);
        }
    }

    std::cout << "--------------------------------------------\n";
    std::cout << "REPORTE CIUDAD GLOBAL:\n";
    std::cout << "Energía Generada: " << ciudadProd << " kW\n";
    std::cout << "Energía Demandada: " << ciudadCons << " kW\n";
    std::cout << "Balance: " << (ciudadProd - ciudadCons) << " kW\n";
    std::cout << "============================================\n";
}