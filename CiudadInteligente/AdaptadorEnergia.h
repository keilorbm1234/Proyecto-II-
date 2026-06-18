#pragma once
#include "FuenteDatosReporte.h"
#include "Distrito.h"
#include "IObservadorReporte.h"
#include "Reporte.h"
#include <iostream>

class AdaptadorEnergia : public FuenteDatosReporte {
private:
    Distrito* distrito; 
    IObservadorReporte* observador;
public:
    AdaptadorEnergia(Distrito* dis, IObservadorReporte* obs); 
    string getNombreModulo() override; 
    string generarContenidoReporte() override; 
    void generarYNotificar();
};


