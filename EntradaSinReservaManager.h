#pragma once
#include "ArchivoVehiculo.h"
#include "VehiculoManager.h"
#include "ClienteManager.h"
#include "PlazaManager.h"
#include "TicketManager.h"

class EntradaSinReservaManager {
public:
    void procesarEntrada();

private:
    VehiculoArchivo _vehiculoArchivo;
    VehiculoManager _vehiculoManager;
    ClienteManager  _clienteManager;
    PlazaManager    _plazaManager;
    TicketManager   _ticketManager;

    void mostrarResumenTicket(const Ticket& ticket, const Vehiculo& vehiculo, const Cliente& cliente, const Plaza& plaza);
};
