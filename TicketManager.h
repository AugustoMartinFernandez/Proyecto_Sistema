#pragma once

#include "ArchivoTicket.h"
#include "ArchivoPlaza.h"
#include "VehiculoArchivo.h"
#include "TarifaArchivo.h"
// #include "ArchivoReserva.h" // (Cuando exista)

class TicketManager {
private:
    ArchivoTicket _archivoTickets;
    ArchivoPlaza _archivoPlazas;
    VehiculoArchivo _archivoVehiculos;
    TarifaArchivo _archivoTarifas;

public:
    TicketManager(
        const char* rutaTickets = "tickets.dat",
        const char* rutaPlazas = "plazas.dat",
        const std::string& rutaVehiculos = "vehiculos.dat",
        const std::string& rutaTarifas = "tarifas.dat"
    );

    // Lógica de Negocio
    void registrarIngreso(); // (Alta)
    void registrarSalida();  // (Modificación)
    void listarTicketsAbiertos();
    void listarHistorialTickets(); // (Cerrados)
};
