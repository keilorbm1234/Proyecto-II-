#include "SistemaReportes.h"
#include <iostream>
#include <fstream>
#include <sstream>

SistemaReportes* SistemaReportes::instancia = nullptr; 

SistemaReportes* SistemaReportes:: getInstance() {
    if (instancia == nullptr) {
        instancia = new SistemaReportes(); 
    }
    return instancia; 
}

void SistemaReportes::actualizar(Reporte r) {
    reportes.push_back(r);
}

void SistemaReportes::agregarReporte(Reporte r) {
    reportes.push_back(r);
}

void SistemaReportes::mostrarTodos() {
    for (const auto& reporte : reportes) {
        reporte.mostrar(); 
    }
}

void SistemaReportes::mostrarPorModulo(string modulo) {
    for (const auto& reporte : reportes) {
        if (reporte.getModulo() == modulo) {
            reporte.mostrar(); 
        }
    }
}

void SistemaReportes::guardarEnArchivo() {

}