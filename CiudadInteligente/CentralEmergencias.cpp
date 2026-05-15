#include "CentralEmergencias.h"
#include "Distrito.h" // Aquí sí incluimos el .h para poder usar sus métodos
#include <iostream>

CentralEmergencias::CentralEmergencias(std::string n) : nombre(n), reportesRecibidos(0) {}

void CentralEmergencias::recibirAlerta(std::string mensaje) {
    reportesRecibidos++;
    std::cout << "[CENTRAL " << nombre << "] ALERTA RECIBIDA: " << mensaje << std::endl;
}

void CentralEmergencias::realizarInspeccion(std::shared_ptr<Distrito> d) {
    // UPCAST EXPLÍCITO: Tratamos al distrito como un objeto base si fuera necesario
    // DOWNCAST: Si el motor nos pasara una IEntidad, usaríamos dynamic_cast.
    std::cout << "[CENTRAL] Inspeccionando distrito: " << d->getNombre() << std::endl;
}