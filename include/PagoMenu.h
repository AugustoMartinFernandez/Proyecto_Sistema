#pragma once
#include "PagoManager.h"

class PagoMenu
{
public:
    PagoMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int  seleccionOpcion();
    void ejecutarOpcion(int opcion);

    PagoManager _pagoManager;

private:
    int _cantidadOpciones;
};
