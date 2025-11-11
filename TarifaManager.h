#pragma once
#include <string>
#include "Hora.h"
#include "TarifaArchivo.h"
#include "VehiculoManager.h"


class TarifaManager
{
private:
    TarifaArchivo _archivo;
    VehiculoManager _vehiculoManager;
public:
    void altaTarifa();
    void bajaTarifa();
    void modificarTarifa();
    void listarTarifas();
};
