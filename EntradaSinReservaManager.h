#pragma once
#include "Vehiculo.h"
#include "VehiculoArchivo.h"
#include "VehiculoManager.h"
#include "ClienteManager.h"
#include "ArchivoPlaza.h"
#include "Reserva.h"
#include "ReservaArchivo.h"
#include "TicketManager.h"

class EntradaSinReservaManager {
public:
    void procesarEntrada();

private:
    VehiculoArchivo _vehiculoArchivo;
    VehiculoManager _vehiculoManager;
    ClienteArchivo  _clienteArchivo;
    ClienteManager  _clienteManager;
    ArchivoPlaza    _plazaArchivo;
    TicketManager   _ticketManager;
    ReservaArchivo   _reservaArchivo;

    void mostrarResumenTicket(const Ticket& ticket, const Vehiculo& vehiculo, const Cliente& cliente, const Plaza& plaza);
};
