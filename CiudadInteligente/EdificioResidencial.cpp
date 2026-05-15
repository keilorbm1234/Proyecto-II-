#include "EdificioResidencial.h"

EdificioResidencial::EdificioResidencial(std::string n, double base, int hab)
    : EntidadBase(n), consumoBase(base), habitantes(hab) {
}

double EdificioResidencial::consumirEnergia() {
    if (!activo) return 0.0;
    return consumoBase + (habitantes * 0.5);
}

std::string EdificioResidencial::getDetalleEstado() const {
    return "Tipo: [Consumidor] | Habitantes: " + std::to_string(habitantes);
}

void EdificioResidencial::escribirTexto(std::ostream& os) const {
    // Formato CSV simple para texto
    os << "RESIDENCIAL," << nombre << "," << consumoBase << "," << habitantes << "\n";
}

void EdificioResidencial::escribirBinario(std::ofstream& os) const {
    int tipo = 1;
    os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));

    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);

    os.write(reinterpret_cast<const char*>(&consumoBase), sizeof(consumoBase));
    os.write(reinterpret_cast<const char*>(&habitantes), sizeof(habitantes));
    os.write(reinterpret_cast<const char*>(&activo), sizeof(activo));
}

void EdificioResidencial::leerBinario(std::ifstream& is) {
    size_t tam;
    is.read(reinterpret_cast<char*>(&tam), sizeof(tam));

    nombre.resize(tam);
    is.read(&nombre[0], tam);

    is.read(reinterpret_cast<char*>(&consumoBase), sizeof(consumoBase));
    is.read(reinterpret_cast<char*>(&habitantes), sizeof(habitantes));
    is.read(reinterpret_cast<char*>(&activo), sizeof(activo));
}