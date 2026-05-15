#pragma once
#include <stdexcept>
#include <string>
using namespace std;

//PRINCIPIO DE PARNAS: Encapsulamos los tipos de errores
class CiudadException : public runtime_error
{
public:
	CiudadException(const string& mensaje) : runtime_error(mensaje) {}
};

