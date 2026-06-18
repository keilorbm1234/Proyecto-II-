#pragma once
#include "Reporte.h"

//INTERFAZ QUE UTILIZA EL PATRON OBSERVER, EL CUAL PERMITE QUE LOS ADAPTADORES AVISEN A SISTEMAREPORTES QUE GENERARON UN NUEVO REPORTE

class IObservadorReporte {
public: 
    virtual void actualizar(Reporte r) = 0; 
    virtual ~IObservadorReporte() = default; 
};
