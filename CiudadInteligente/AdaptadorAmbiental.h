#pragma once

#include "FuenteDatosReporte.h"

//PATRON ADAPTER:

//permite adaptar la interfaz de un modulo ambiental al formato que entiende el sistema de reportes, sin modificar el sistema de reportes ni el modulo ambiental

//SOLID (OCP):
//Abierto a extension, cerrado a modificación, deja meter nuevos módulos de reporte sin modificar el sistema de reportes

class AdaptadorAmbiental : public FuenteDatosReporte {

public:

    string getNombreModulo() override;

    string generarContenidoReporte() override;
};