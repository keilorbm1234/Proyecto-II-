#include "SistemaReportes.h"
#include "ArchivoReporteException.h"
#include <iostream>
#include <fstream>
#include <sstream>

SistemaReportes* SistemaReportes::instancia = nullptr; 

SistemaReportes::SistemaReportes() {
    nombreArchivo = "reportes.txt"; 
}

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
    ofstream archivo(nombreArchivo);

    if (!archivo) {
        throw ArchivoReporteException(nombreArchivo);
    }
    
    for (const auto& reporte : reportes) {
        archivo << reporte.getModulo() << endl;
        archivo << reporte.getContenido() << endl;
        archivo << reporte.getFechaHora() << endl;
    }
    archivo.close();
}

void SistemaReportes::cargarDesdeArchivo() {
    ifstream archivo(nombreArchivo); 

    if (!archivo) {
        throw ArchivoReporteException(nombreArchivo);
    }

    string modulo, contenido, fechaHora;
    while (getline(archivo, modulo)){
        getline(archivo, contenido); 
        getline(archivo, fechaHora); 
        Reporte r(modulo, contenido, fechaHora); 
        reportes.push_back(r);
    }
    archivo.close(); 
}

