#pragma once

#include "TicketManager.h"

class TicketMenu {
public:
    TicketMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    TicketManager _ticketManager;
    int _cantidadOpciones;
};
