#include <iostream>
#include <memory>
#include "GestorCiudad.h"
#include "GestorArchivos.h"
#include "PlantaSolar.h"
#include "EdificioResidencial.h"
#include "ComplejoIndustrial.h"
#include "EstrategiaAhorro.h"
#include "DeficitRecursoException.h"
#include "EntidadBase.h"

//INCLUDES DEL PROYECTO II SAMUEL Y KEILOR
#include "SistemaReportes.h"
#include "AdaptadorEnergia.h"
#include "AdaptadorTrafico.h"
#include "CorredorVial.h"
#include "ViaAlterna.h"
#include "AdaptadorSensorTrafico.h"
#include "SensorTraficoExterno.h"
#include "ArchivoReporteException.h"

int main() {
    try {
        std::cout << "===== INICIO DE SIMULACION DE CIUDAD INTELIGENTE =====\n\n";

        // 1. Central urbana
        auto central911 = std::make_shared<CentralEmergencias>("911-EcoCity");

        // 2. Gestor principal
        GestorCiudad motor(central911);

        // 3. Estrategia delegada
        auto estrategia = std::make_shared<EstrategiaAhorro>();

        // 4. Crear distritos
        auto distCentro = std::make_shared<Distrito>("Centro");
        auto distIndustrial = std::make_shared<Distrito>("Parque Industrial");

        distCentro->setDelegado(estrategia);
        distIndustrial->setDelegado(estrategia);

        // 5. Poblar distrito centro
        distCentro->agregarEdificio(std::make_shared<PlantaSolar>("Solar Centro", 300));
        distCentro->agregarEdificio(std::make_shared<EdificioResidencial>("Torre Norte", 120, 80));
        distCentro->agregarEdificio(std::make_shared<EdificioResidencial>("Torre Sur", 100, 60));

        // 6. Poblar distrito industrial
        distIndustrial->agregarEdificio(std::make_shared<PlantaSolar>("Solar Max", 120));
        distIndustrial->agregarEdificio(std::make_shared<ComplejoIndustrial>("Zona Franca A", 200, 150));
        distIndustrial->agregarEdificio(std::make_shared<EdificioResidencial>("Mega Torre", 500, 1000)); // provoca déficit

        // 7. Registrar distritos en el gestor
        motor.agregarDistrito(distCentro);
        motor.agregarDistrito(distIndustrial);



        // 8. Guardar estado inicial del distrito industrial
        std::cout << "\n[1] Guardando estado inicial del distrito industrial...\n";
        GestorArchivos::guardarEstadoBinario(*distIndustrial, "industrial.dat");

        // 9. Procesar turno
        std::cout << "\n[2] Procesando turno...\n";
        try {
            motor.procesarTurno();
        }
        catch (const DeficitRecursoException& error) {
            std::cerr << "FALLO CONTROLADO EN LA SIMULACION: " << error.what() << std::endl;
            std::cerr << "La central y la estrategia delegada reaccionaron correctamente.\n";
        }

        // 10. Desactivar una entidad para probar persistencia del estado
        std::cout << "\n[3] Alterando estado de una entidad antes de recargar...\n";
        const auto& edificios = distIndustrial->getEdificios();
        if (!edificios.empty()) {
            auto base = std::dynamic_pointer_cast<EntidadBase>(edificios[0]);
            if (base) {
                base->alternarEstado();
                std::cout << "Entidad alterada: " << base->getNombre() << "\n";
            }
        }

        std::cout << "\nReporte del distrito industrial DESPUES de alterar estado:\n";
        distIndustrial->mostrarReporteDistrito();

        // 11. Recargar desde archivo
        std::cout << "\n[4] Recargando estado desde archivo binario...\n";
        GestorArchivos::cargarEstadoBinario(*distIndustrial, "industrial.dat");

        std::cout << "\nReporte del distrito industrial RECARGADO desde archivo:\n";
        distIndustrial->mostrarReporteDistrito();

        // 12. SISTEMA DE REPORTES PROYECTO II

        SistemaReportes* sistema = SistemaReportes::getInstance();

        AdaptadorEnergia adaptadorEnergia(distCentro.get(), sistema);

        // 13. ESCENARIO DE TRAFICO

        SensorTraficoExterno sensor("S-01", 250, 42.5, 68.0);

        AdaptadorSensorTrafico adaptadorSensor(sensor);

        CorredorVial corredor("Corredor Principal");

        corredor.agregarComponente(std::make_unique<ViaAlterna>("Ruta Norte", 5.5, adaptadorSensor));

        AdaptadorTrafico adaptadorTrafico(&corredor, sistema);

        //MENU DE REPORTES PROYECTO II

        int opcion;

        do {

            std::cout << "\n_______SISTEMA DE REPORTES_______\n";

            std::cout << "1. Generar reporte de energia\n";

            std::cout << "2. Generar reporte de trafico\n";

            std::cout << "3. Mostrar todos los reportes\n";

            std::cout << "4. Mostrar reportes por modulo\n";

            std::cout << "5. Guardar reportes\n";

            std::cout << "6. Cargar reportes\n";

            std::cout << "7. Salir\n";

            std::cin >> opcion;

            switch (opcion) {

            case 1:

                adaptadorEnergia.generarYNotificar();
                std::cout << "Reporte de energia generado.\n";

                break;
            case 2:

                adaptadorTrafico.generarYNotificar();
                std::cout << "Reporte de trafico generado.\n";

                break;
            case 3:

                sistema->mostrarTodos();

                break;
            case 4: {

                std::string modulo;
                std::cout << "Digite el modulo: ";
                std::cin >> modulo;

                sistema->mostrarPorModulo(modulo);

                break;
            }
            case 5:
                try {
                    sistema->guardarEnArchivo();
                    std::cout << "Reportes guardados.\n";
                }
                catch (const ArchivoReporteException& error) {
                    std::cerr << "Error: " << error.what() << std::endl;
                }
                break;

            case 6:
                try {
                    sistema->cargarDesdeArchivo();
                    std::cout << "Reportes cargados.\n";
                }
                catch (const ArchivoReporteException& error) {
                    std::cerr << "Error: " << error.what() << std::endl;
                }
                break;

            case 7:

                std::cout << "Saliendo...\n";

                break;
            default:

                std::cout << "Numero incorrecto\n";
            }

        } while (opcion != 7);

        std::cout << "\n===== FIN DE LA SIMULACION =====\n";
    }
    catch (const std::exception& error) {
        std::cerr << "Error inesperado: " << error.what() << std::endl;
    }
    return 0; 
}