#include "FabricaCarretera.h"

std::unique_ptr<ViaAlterna> FabricaCarreteraUrbana::crearSegmento(
    std::string nombre,
    double longitud,
    const SensorTraficoExterno& sensor
) const {
    AdaptadorSensorTrafico adaptador(sensor);
    return std::make_unique<ViaAlterna>(
        "Urbano - " + nombre,
        longitud,
        adaptador
    );
}

std::unique_ptr<CorredorVial> FabricaCarreteraUrbana::crearCorredor(std::string nombre) const {
    return std::make_unique<CorredorVial>("Corredor Urbano - " + nombre);
}

std::unique_ptr<ViaAlterna> FabricaCarreteraNacional::crearSegmento(
    std::string nombre,
    double longitud,
    const SensorTraficoExterno& sensor
) const {
    AdaptadorSensorTrafico adaptador(sensor);
    return std::make_unique<ViaAlterna>(
        "Nacional - " + nombre,
        longitud,
        adaptador
    );
}

std::unique_ptr<CorredorVial> FabricaCarreteraNacional::crearCorredor(std::string nombre) const {
    return std::make_unique<CorredorVial>("Corredor Nacional - " + nombre);
}
