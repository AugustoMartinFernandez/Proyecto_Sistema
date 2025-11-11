#pragma once
#include "ReporteRecaudacionManager.h"

class MenuReportes {
public:
    MenuReportes();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    int _cantidadOpciones;
};
