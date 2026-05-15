#include "ComplejoIndustrial.h"

ComplejoIndustrial::ComplejoIndustrial(std::string n, double prod, double cons)
    : EntidadBase(n), produccionPropia(prod), consumoMaquinaria(cons) {
}

double ComplejoIndustrial::producirEnergia() {
    return activo ? produccionPropia : 0.0;
}

double ComplejoIndustrial::consumirEnergia() {
    return activo ? consumoMaquinaria : 0.0;
}

std::string ComplejoIndustrial::getDetalleEstado() const {
    bool autosuficiente = produccionPropia >= consumoMaquinaria;
    return "Tipo: [Híbrido] | Autosuficiente: " + std::string(autosuficiente ? "SI" : "NO");
}

void ComplejoIndustrial::escribirTexto(std::ostream& os) const {
    os << "INDUSTRIAL," << nombre << "," << produccionPropia << "," << consumoMaquinaria << "\n";
}

void ComplejoIndustrial::escribirBinario(std::ofstream& os) const {
    int tipo = 3;
    os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));

    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);

    os.write(reinterpret_cast<const char*>(&produccionPropia), sizeof(produccionPropia));
    os.write(reinterpret_cast<const char*>(&consumoMaquinaria), sizeof(consumoMaquinaria));

    // estado activo
    os.write(reinterpret_cast<const char*>(&activo), sizeof(activo));
}

void ComplejoIndustrial::leerBinario(std::ifstream& is) {
    size_t tam;
    is.read(reinterpret_cast<char*>(&tam), sizeof(tam));

    nombre.resize(tam);
    is.read(&nombre[0], tam);

    is.read(reinterpret_cast<char*>(&produccionPropia), sizeof(produccionPropia));
    is.read(reinterpret_cast<char*>(&consumoMaquinaria), sizeof(consumoMaquinaria));

    // estado activo
    is.read(reinterpret_cast<char*>(&activo), sizeof(activo));
}