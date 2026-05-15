#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include "Distrito.h"
#include <string>
#include <map>
#include <functional>

class GestorArchivos {
public:
	static void guardarEstadoBinario(const Distrito& dist, const std::string& ruta);
	static void cargarEstadoBinario(Distrito& dist, const std::string& ruta);
};

#endif

