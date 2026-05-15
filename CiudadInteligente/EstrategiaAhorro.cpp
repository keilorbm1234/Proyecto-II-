#include "EstrategiaAhorro.h"
#include "Distrito.h"
#include <iostream>
using namespace std;

void EstrategiaAhorro::ejecutarAccion(Distrito* contexto)
{
	//Aquí entra el delegado
	//Porque lo que hacemos es que, como el distrito no tiene capacidad
	//de administrar su energia, esta estrategia toma el control
	cout << "[DELEGADO TRABAJANDO] Aplicando protocolos de ahorro en: "
		<< contexto->getNombre() << endl;
	//Más adelante, vamos a llamar acá metodos para apagar partes del distrito
	//por ejemplo edificios residenciales, por encima de hospitales o
	//edificios de nivel prioritario
}