#include "GestorArchivos.h"
#include "EntidadBase.h"
#include "EdificioResidencial.h"
#include "PlantaSolar.h"
#include "ComplejoIndustrial.h"
#include "EstacionCargaElectrica.h"
#include <fstream>
#include <iostream>
#include <map>
#include <functional>

namespace {
    std::map<int, std::function<std::shared_ptr<EntidadBase>()>> fabrica = {
        { 1, []() { return std::make_shared<EdificioResidencial>("", 0, 0); } },
        { 2, []() { return std::make_shared<PlantaSolar>("", 0); } },
        { 3, []() { return std::make_shared<ComplejoIndustrial>("", 0, 0); } },
        { 4, []() { return std::make_shared<EstacionCargaElectrica>("", 0, 0, 0.0); } }
    };
}

void GestorArchivos::guardarEstadoBinario(const Distrito& dist, const std::string& ruta) {
    std::ofstream archivo(ruta, std::ios::binary);
    if (!archivo) return;

    const auto& edificios = dist.getEdificios();
    size_t total = edificios.size();
    archivo.write(reinterpret_cast<const char*>(&total), sizeof(total));

    for (const auto& e : edificios) {
        auto base = std::dynamic_pointer_cast<EntidadBase>(e);
        if (base) {
            base->escribirBinario(archivo);
        }
    }
}

void GestorArchivos::cargarEstadoBinario(Distrito& dist, const std::string& ruta) {
    std::ifstream archivo(ruta, std::ios::binary);
    if (!archivo) return;

    dist.limpiarEdificios();

    size_t total = 0;
    archivo.read(reinterpret_cast<char*>(&total), sizeof(total));

    for (size_t i = 0; i < total; ++i) {
        int tipo = 0;
        archivo.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));

        if (!archivo) break;

        if (fabrica.count(tipo)) {
            auto nuevaEntidad = fabrica[tipo]();
            nuevaEntidad->leerBinario(archivo);
            dist.agregarEdificio(nuevaEntidad);
        }
        else {
            std::cerr << "Tipo desconocido: " << tipo << ". No se puede reconstruir el objeto.\n";
            break;
        }
    }
}