#pragma once

#include "ClienteManager.h"

class ClienteMenu {
public:
    ClienteMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    ClienteManager _clienteManager;
    int _cantidadOpciones;
};
