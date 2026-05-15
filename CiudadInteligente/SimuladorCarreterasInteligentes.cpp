#include "SimuladorCarreterasInteligentes.h"
#include "FabricaCarretera.h"
#include "CentroControlVial.h"
#include <iostream>

void simularModuloCarreterasInteligentes() {
    std::cout << "\n===== MODULO EXTRA: CARRETERAS INTELIGENTES =====\n";

    FabricaCarreteraUrbana fabricaUrbana;
    FabricaCarreteraNacional fabricaNacional;

    SensorTraficoExterno sensor1("SEN-URB-001", 120, 35.5, 60);
    SensorTraficoExterno sensor2("SEN-URB-002", 180, 25.2, 82);
    SensorTraficoExterno sensor3("SEN-NAC-001", 90, 75.0, 30);

    auto corredorCentral = fabricaUrbana.crearCorredor("Circunvalacion Central");

    corredorCentral->agregarComponente(
        fabricaUrbana.crearSegmento("Rotonda Norte - Hospital", 2.5, sensor1)
    );

    corredorCentral->agregarComponente(
        fabricaUrbana.crearSegmento("Hospital - Centro Financiero", 3.1, sensor2)
    );

    auto corredorNacional = fabricaNacional.crearCorredor("Ruta Interurbana");

    corredorNacional->agregarComponente(
        fabricaNacional.crearSegmento("Salida Este - Peaje", 12.8, sensor3)
    );

    corredorCentral->agregarComponente(std::move(corredorNacional));

    corredorCentral->mostrarReporte();

    CentroControlVial::getInstancia().evaluarCongestion(*corredorCentral);

    std::cout << "===== FIN MODULO CARRETERAS INTELIGENTES =====\n";
}