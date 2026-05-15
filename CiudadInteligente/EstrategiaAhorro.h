#pragma once
#include "IEstrategiaEnergia.h"
using namespace std;

class EstrategiaAhorro : public IEstrategiaEnergia
{
public:
	void ejecutarAccion(Distrito* contexto) override;
	string getTipoEstrategia() const override { 
		return "Ejecutando plan de ahorro de energía"; }
};

