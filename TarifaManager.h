#pragma once
#include "TarifaArchivo.h"

class TarifaManager
{
private:
    TarifaArchivo _archivo;
public:
    void altaTarifa();
    void bajaTarifa();
    void modificarTarifa();
    void listarTarifas();
};
