#pragma once
#include "ReservaManager.h"

class ReservaMenu
{
public:
    ReservaMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int  seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    ReservaManager _reservaManager;
    int _cantidadOpciones;
};
