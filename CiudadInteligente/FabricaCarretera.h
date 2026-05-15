#pragma once
#include <memory>
#include "ViaAlterna.h"
#include "CorredorVial.h"

class FabricaCarretera {
public:
    virtual ~FabricaCarretera() = default;

    virtual std::unique_ptr<ViaAlterna> crearSegmento(
        std::string nombre,
        double longitud,
        const SensorTraficoExterno& sensor
    ) const = 0;

    virtual std::unique_ptr<CorredorVial> crearCorredor(std::string nombre) const = 0;
};

class FabricaCarreteraUrbana : public FabricaCarretera {
public:
    std::unique_ptr<ViaAlterna> crearSegmento(
        std::string nombre,
        double longitud,
        const SensorTraficoExterno& sensor
    ) const override;

    std::unique_ptr<CorredorVial> crearCorredor(std::string nombre) const override;
};

class FabricaCarreteraNacional : public FabricaCarretera {
public:
    std::unique_ptr<ViaAlterna> crearSegmento(
        std::string nombre,
        double longitud,
        const SensorTraficoExterno& sensor
    ) const override;

    std::unique_ptr<CorredorVial> crearCorredor(std::string nombre) const override;
};
