#pragma once
#include "ArchivoTicket.h"
#include "VehiculoManager.h"
#include "TarifaArchivo.h"
#include "PagoArchivo.h"
#include "ArchivoPlaza.h"
#include "FechaHora.h"

class SalidaCobroManager {
private:
    ArchivoTicket _ticketArchivo;
    VehiculoArchivo _vehiculoArchivo;
    VehiculoManager _vehiculoManager;
    TarifaArchivo _tarifaArchivo;
    PagoArchivo _pagoArchivo;
    ArchivoPlaza _plazaArchivo;


public:
    void procesarSalida();
};
