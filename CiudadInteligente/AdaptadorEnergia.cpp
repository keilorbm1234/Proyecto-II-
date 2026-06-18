#include "AdaptadorEnergia.h"
#include <sstream>
#include <string>
using namespace std; 

AdaptadorEnergia::AdaptadorEnergia(Distrito* dis, IObservadorReporte* obs) : distrito(dis), observador(obs) {}

string AdaptadorEnergia::getNombreModulo() {
    return "Energia"; 
}

string AdaptadorEnergia::generarContenidoReporte() {
    stringstream ss; 
    ss << "Distrito: " << distrito->getNombre() << endl;
    ss << "Consumo Total: " << distrito->obtenerConsumoTotal() << " kwh." << endl;
    ss << "Produccion Total: " << distrito->obtenerProduccionTotal() << " kwh." << endl;
    return ss.str(); 
}

void AdaptadorEnergia::generarYNotificar() {
    Reporte r(getNombreModulo(), generarContenidoReporte(), "15-06-2026");
    observador->actualizar(r); 
}
