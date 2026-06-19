#pragma once

#include "FuenteDatosReporte.h"
#include "CorredorVial.h"
#include "IObservadorReporte.h"
#include "Reporte.h"

#include <sstream>

// DAPTER: Convierte los datos de CorredorVial para que SistemaReportes los entienda.

// OBSERVER:Actua como sujeto y notifica al observador sin conocer a SistemaReportes.

//LEY DE DEMETER: corredorvial y no intermedios

//SOLID (OCP):Abierto a extension, cerrado a modificación, deja meter nuevos módulos sin modificar SistemaReportes.


class AdaptadorTrafico : public FuenteDatosReporte {

private:

    CorredorVial* corredor;

    IObservadorReporte* observador;

public:

    AdaptadorTrafico(
        CorredorVial* c,
        IObservadorReporte* obs
    );

    string getNombreModulo() override;

    string generarContenidoReporte() override;

    void generarYNotificar();
};