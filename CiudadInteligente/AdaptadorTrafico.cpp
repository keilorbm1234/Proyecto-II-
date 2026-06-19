#include "AdaptadorTrafico.h"

#include <sstream>

using namespace std;

AdaptadorTrafico::AdaptadorTrafico(
    CorredorVial* c,
    IObservadorReporte* obs
)

    : corredor(c),
    observador(obs)

{
}

string AdaptadorTrafico::getNombreModulo() {

    return "Trafico";
}

string AdaptadorTrafico::generarContenidoReporte() {

    MedicionTrafico medicion =
        corredor->obtenerMedicionTotal();

    stringstream ss;

    ss << "Corredor: "
        << corredor->getNombre() << endl;

    ss << "Vehiculos detectados: "
        << medicion.getVehiculos() << endl;

    ss << "Velocidad promedio: "
        << medicion.getVelocidadPromedio()
        << " km/h" << endl;

    ss << "Nivel de congestion: "
        << medicion.getNivelCongestion()
        << "%" << endl;

    return ss.str();
}

void AdaptadorTrafico::generarYNotificar() {

    Reporte r(

        getNombreModulo(),

        generarContenidoReporte(),

        "15-06-2026"

    );

    observador->actualizar(r);
}