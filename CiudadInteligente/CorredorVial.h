#pragma once
#include "ComponenteVial.h"
#include <vector>
#include <memory>

class CorredorVial : public ComponenteVial {
private:
    std::string nombre;
    std::vector<std::unique_ptr<ComponenteVial>> componentes;

public:
    CorredorVial(std::string nombre);

    // Big Five Rule
    ~CorredorVial();
    CorredorVial(const CorredorVial& otro) = delete;
    CorredorVial& operator=(const CorredorVial& otro) = delete;
    CorredorVial(CorredorVial&& otro) noexcept;
    CorredorVial& operator=(CorredorVial&& otro) noexcept;

    void agregarComponente(std::unique_ptr<ComponenteVial> componente);

    std::string getNombre() const override;
    MedicionTrafico obtenerMedicionTotal() const override;
    void mostrarReporte(int nivel = 0) const override;
};

