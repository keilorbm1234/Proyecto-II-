#pragma once
#include "ComponenteVial.h"
#include "AdaptadorSensorTrafico.h"
#include <memory>

class ViaAlterna : public ComponenteVial {
private:
    std::string nombre;
    double longitudKm;
    AdaptadorSensorTrafico* sensor;

public:
    ViaAlterna(std::string nombre, double longitud, const AdaptadorSensorTrafico& sensor);

    // Big Three Rule
    ~ViaAlterna();
    ViaAlterna(const ViaAlterna& otro);
    ViaAlterna& operator=(const ViaAlterna& otro);

    std::string getNombre() const override;
    MedicionTrafico obtenerMedicionTotal() const override;
    void mostrarReporte(int nivel = 0) const override;
};