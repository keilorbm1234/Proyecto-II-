#pragma once
#include "FuenteDatosReporte.h"
#include "Distrito.h"
#include "IObservadorReporte.h"
#include "Reporte.h"
#include <iostream>

//SE UTILIZA EL PATRON ADAPTER PARA CONVERTIR LOS DATOS DE UN DISTRITO AL FORMATO DE UN REPORTE QUE ENTIENDE EL SISTEMA DE REPORTES. 
//COMO EL GESTORCIUDAD NO UTILIZA GETTERS DE LOS DISTRITOS, SE DEPENDE DE DISTRITO PARA NO VIOLAR LA LEY DE DEMETER
//MEDIANTE EL ACCESO INCORRECTO E INDEBIDO A DATOS DE DISTRITOS MEDIANTE GESTORCIUDAD. 
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


