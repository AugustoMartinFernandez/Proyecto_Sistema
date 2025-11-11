#pragma once
#include "ReservaArchivo.h"
#include "VehiculoManager.h"
#include "ArchivoPlaza.h"


class ReservaManager {
public:
    ReservaManager() = default;

    void altaReserva();
    void listarReservas();
    void modificarReserva();
    void bajaReserva();           // baja lógica (cambia estado)

private:
    void mostrarReserva(const Reserva &r);

    ReservaArchivo _repo;
    VehiculoArchivo _vehiculoArchivo;
    VehiculoManager _vehiculoManager;
    ArchivoPlaza _plazaArchivo;

};

