#pragma once

#include "VehiculoManager.h"

class VehiculoMenu {
public:
    VehiculoMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionOpcion(); 
    void ejecutarOpcion(int opcion);

private:
    VehiculoManager _vehiculoManager;
    int _cantidadOpciones;
};
