#pragma once
#include <stdexcept>
#include <string>
#include "CiudadException.h"

//Esta es la excepción específica para déficit de energia
//Cuando producimos menos de lo que consumimos
//YAGNI: Solo creamos lo necesario, un .h, sin .cpp porque
//no hay nada que desarrollar
class DeficitRecursoException : public CiudadException
{
public:
	DeficitRecursoException(const string& distrito, double faltante)
		: CiudadException("ERROR CRITICO: Deficit en: " + distrito +
			". Faltan " + to_string(faltante) + " kw.") {
	}
};
