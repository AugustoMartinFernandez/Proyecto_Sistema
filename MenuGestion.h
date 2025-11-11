#pragma once
#include "PlazaMenu.h"
#include "AbonoMenu.h"
#include "ClienteMenu.h"
#include "VehiculoMenu.h"
#include "TarifaMenu.h"
#include "TicketMenu.h"
#include "PagoMenu.h"
#include "ReservaMenu.h"


class MenuGestion {
public:
    MenuGestion();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    int _cantidadOpciones;
};

