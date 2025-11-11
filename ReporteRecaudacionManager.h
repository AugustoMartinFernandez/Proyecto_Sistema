#pragma once
#include "PagoArchivo.h"
#include "ArchivoTicket.h"
#include "VehiculoManager.h"
#include "FechaHora.h"

class ReporteRecaudacionManager {
private:
    PagoArchivo _pagoArchivo;
    ArchivoTicket _ticketArchivo;
    VehiculoManager _vehiculoManager;

    bool esMismoDia(const FechaHora& f1, const FechaHora& f2) const;
    bool esMismoMes(const FechaHora& f1, const FechaHora& f2) const;
    bool esMismoAnio(const FechaHora& f1, const FechaHora& f2) const;

public:
    void recaudacionDiaria();
    void recaudacionMensual();
    void recaudacionAnual();
    void recaudacionPorTipoVehiculo();
};
