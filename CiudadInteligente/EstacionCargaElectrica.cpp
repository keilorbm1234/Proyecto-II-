#include "EstacionCargaElectrica.h"
#include <algorithm>

EstacionCargaElectrica::EstacionCargaElectrica(std::string n, int cargadores, int vehiculos, double consumoUnitario)
    : EntidadBase(n),
    cargadoresTotales(cargadores),
    vehiculosCargando(vehiculos),
    consumoPorVehiculo(consumoUnitario) {
}

double EstacionCargaElectrica::consumirEnergia() {
    if (!activo) return 0.0;
    return vehiculosCargando * consumoPorVehiculo;
}

std::string EstacionCargaElectrica::getDetalleEstado() const {
    return "Tipo: [Carga EV] | Vehiculos cargando: " + std::to_string(vehiculosCargando) +
        "/" + std::to_string(cargadoresTotales);
}

void EstacionCargaElectrica::conectarVehiculo() {
    if (vehiculosCargando < cargadoresTotales) {
        vehiculosCargando++;
    }
}

void EstacionCargaElectrica::desconectarVehiculo() {
    if (vehiculosCargando > 0) {
        vehiculosCargando--;
    }
}

void EstacionCargaElectrica::escribirTexto(std::ostream& os) const {
    os << "CARGA_EV," << nombre << "," << cargadoresTotales << ","
        << vehiculosCargando << "," << consumoPorVehiculo << "\n";
}

void EstacionCargaElectrica::escribirBinario(std::ofstream& os) const {
    int tipo = 4;
    os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));

    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);

    os.write(reinterpret_cast<const char*>(&cargadoresTotales), sizeof(cargadoresTotales));
    os.write(reinterpret_cast<const char*>(&vehiculosCargando), sizeof(vehiculosCargando));
    os.write(reinterpret_cast<const char*>(&consumoPorVehiculo), sizeof(consumoPorVehiculo));
    os.write(reinterpret_cast<const char*>(&activo), sizeof(activo));
}

void EstacionCargaElectrica::leerBinario(std::ifstream& is) {
    size_t tam;
    is.read(reinterpret_cast<char*>(&tam), sizeof(tam));

    nombre.resize(tam);
    is.read(&nombre[0], tam);

    is.read(reinterpret_cast<char*>(&cargadoresTotales), sizeof(cargadoresTotales));
    is.read(reinterpret_cast<char*>(&vehiculosCargando), sizeof(vehiculosCargando));
    is.read(reinterpret_cast<char*>(&consumoPorVehiculo), sizeof(consumoPorVehiculo));
    is.read(reinterpret_cast<char*>(&activo), sizeof(activo));
}