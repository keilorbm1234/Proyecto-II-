#pragma once
#include<string>
using namespace std;

class FuenteDatosReporte {
public:
    ~FuenteDatosReporte() = default; 
    virtual string getNombreModulo() = 0; 
    virtual string generarContenidoReporte() = 0; 
};
