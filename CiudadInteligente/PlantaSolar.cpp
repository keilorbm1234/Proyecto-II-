#include "PlantaSolar.h"

PlantaSolar::PlantaSolar(string n, double cap)
    : EntidadBase(n), capacidadMaxima(cap), eficiencia(0.85) {
}

double PlantaSolar::producirEnergia() {
    return activo ? (capacidadMaxima * eficiencia) : 0.0;
}

std::string PlantaSolar::getDetalleEstado() const {
    return "Tipo: [Productor] | Eficiencia: " + to_string((int)(eficiencia * 100)) + "%";
}

// Escritura en Texto (Reporte)
void PlantaSolar::escribirTexto(std::ostream& os) const {
    os << "SOLAR," << nombre << "," << capacidadMaxima << "," << eficiencia << "\n";
}

// Escritura en Binario (Estado)
void PlantaSolar::escribirBinario(std::ofstream& os) const {
    // 1. Identificador de tipo (2 = Planta Solar)
    int tipo = 2;
    os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));

    // 2. Nombre (Longitud + caracteres)
    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);

    // 3. Atributos numéricos específicos
    os.write(reinterpret_cast<const char*>(&capacidadMaxima), sizeof(capacidadMaxima));
    os.write(reinterpret_cast<const char*>(&eficiencia), sizeof(eficiencia));

    // 4. Estado heredado
    os.write(reinterpret_cast<const char*>(&activo), sizeof(activo));
}

void PlantaSolar::leerBinario(std::ifstream& is) {
    size_t tam;
    is.read(reinterpret_cast<char*>(&tam), sizeof(tam));
    nombre.resize(tam);
    is.read(&nombre[0], tam);

    is.read(reinterpret_cast<char*>(&capacidadMaxima), sizeof(capacidadMaxima));
    is.read(reinterpret_cast<char*>(&eficiencia), sizeof(eficiencia));

    // 4. Estado heredado
    is.read(reinterpret_cast<char*>(&activo), sizeof(activo));
}