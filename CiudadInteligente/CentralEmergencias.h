#pragma once
#include <string>
#include <vector>
#include <memory>

// PRINCIPIO DE PARNAS: Ocultamos la implementación interna del Distrito
// FORWARD DECLARATION: Avisamos que la clase Distrito existe sin incluir su .h
// Esto resuelve la DEPENDENCIA MUTUA inicial.
class Distrito;

class CentralEmergencias {
private:
    std::string nombre;
    // YAGNI: No creamos una lista de "Historial de llamadas" complejo 
    // porque aún no se solicita (Solo guardamos el conteo).
    int reportesRecibidos;

public:
    CentralEmergencias(std::string n);
    void recibirAlerta(std::string mensaje);

    // Este método requerirá conocer la interfaz de Distrito
    void realizarInspeccion(std::shared_ptr<Distrito> d);
};
