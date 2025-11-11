#pragma once
#include "VehiculoManager.h"
#include "VehiculoArchivo.h"
#include "ReservaArchivo.h"
#include "TarifaArchivo.h"
#include "ArchivoTicket.h"
#include "ClienteManager.h"
#include "ArchivoPlaza.h"
#include "FechaHora.h"

class EntradaConReservaManager
{
private:
    VehiculoManager _vehiculoManager;
    VehiculoArchivo _vehiculoArchivo;
    ReservaArchivo _reservaArchivo;
    TarifaArchivo _tarifaArchivo;
    ArchivoTicket _ticketArchivo;
    ClienteManager _clienteManager;
    ArchivoPlaza _plazaArchivo;

    void mostrarResumenTicket(
        const Ticket& ticket,
        const Vehiculo& vehiculo,
        const Cliente& cliente,
        const Plaza& plaza
    );

public:
    void procesarEntrada();
};
