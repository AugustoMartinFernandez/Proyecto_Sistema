#pragma once
#include "TarifaManager.h"

class TarifaMenu
{
public:
    TarifaMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int  seleccionOpcion();
    void ejecutarOpcion(int opcion);

    TarifaManager _tarifaManager;

private:
    int _cantidadOpciones;
};
