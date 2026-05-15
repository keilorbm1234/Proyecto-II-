#pragma once
#include <string>
using namespace std;

//Esta clase, va a tener una interfaz delegada

//Forward declaration: para evitar dependencias múltiples
class Distrito;

//PATRON DELEGATE: Esta interfaz define el contrato para quien quiera
//ayudar al Distrito a recuperar o gestionar su energia
class IEstrategiaEnergia
{
public:
	virtual ~IEstrategiaEnergia() = default;
	virtual void ejecutarAccion(Distrito* contexto) = 0;
	virtual string getTipoEstrategia() const = 0;
};