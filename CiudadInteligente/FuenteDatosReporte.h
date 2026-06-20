#pragma once
#include<string>
using namespace std;

//ESTA INTERFAZ UTILIZA EL PATRON ADAPTER, EL CUAL DEFINE EL CONTRARON QUE DEBE CUMPLIR CUALQUIER MODULO DE LA CIUDAD 
//PARA INTEGRARSE AL SISTEMA DE REPORTES.
//TAMBIEN SE RESPETA LA LEY DE DEMETER Y PARNAS YA QUE SISTEMAREPORTES ES LA UNICA QUE CONOCE ESTA INTERFAZ. 

class FuenteDatosReporte {
public:
    virtual ~FuenteDatosReporte() = default; 
    virtual string getNombreModulo() = 0; 
    virtual string generarContenidoReporte() = 0; 
};
