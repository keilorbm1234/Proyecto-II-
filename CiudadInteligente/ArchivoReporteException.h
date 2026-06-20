#pragma once
#include <stdexcept>
#include <string>
#include "CiudadException.h"

class ArchivoReporteException : public CiudadException {
public:
    ArchivoReporteException(const string& archivo) : CiudadException("Error critico. No se pudo abrir el archivo: " + archivo) {}
};

