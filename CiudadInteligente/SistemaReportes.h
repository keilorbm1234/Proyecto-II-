#pragma once
#include "IObservadorReporte.h"
#include "Reporte.h"
#include <vector>
#include <string>

//ESTA CLASE SE ENCARGA DE ADMINISTRAR REPORTES, USA EL PATRON OBSERVER E IMPLEMENTA PERSISTENCIA DE ARCHIVOS DE TEXTO
//EL USO DE SINGLETON EN ESTA CLASE GARANTIZA QUE SOLO EXISTA UNA INSTANCIA DE SISTEMAREPORTES EN TODO EL PROGRAMA. 
//EL PATRON OBSERVER SE PUEDE IDENTIFICAR MEDIANTE LAS NOTIFICACIONES RECIBIDAS DE LOS ADAPTADORES MEDIANTE EL METODO "ACTUALIZAR()" SIN CONOCER LA CLASE QUE GENERÓ DICHAS NOTIFICACIONES.
//ASIMISMO, ESTA CLASE RESPETA OCP, ESTA CLASE ESTÁ CERRADA A SU EXTENSIÓN.

class SistemaReportes : public IObservadorReporte {
private:
    static SistemaReportes* instancia; 
    vector<Reporte> reportes; 
    string nombreArchivo; 
    SistemaReportes(); 
    
public: 
    SistemaReportes(const SistemaReportes& otro) = delete; 
    SistemaReportes& operator=(const SistemaReportes& otro) = delete; 
    static SistemaReportes* getInstance(); 
    void actualizar(Reporte r) override; 
    void agregarReporte(Reporte r); 
    void mostrarTodos(); 
    void mostrarPorModulo(string modulo); 
    void guardarEnArchivo(); 
    void cargarDesdeArchivo(); 
};

