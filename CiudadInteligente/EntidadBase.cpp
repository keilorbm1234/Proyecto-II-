#include "EntidadBase.h"

EntidadBase::EntidadBase(string n) : nombre(n), activo(true) {}

string EntidadBase::getNombre() const { return nombre; }

void EntidadBase::alternarEstado() { activo = !activo; }

bool EntidadBase::isActivo() const { return activo; }
