#pragma once
#include "EntradaSinReservaManager.h"
#include "EntradaConReservaManager.h"
#include "SalidaCobroManager.h"
#include "MenuGestion.h"
#include "MenuReportes.h"

class MenuPrincipal {
public:
    MenuPrincipal();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    int _cantidadOpciones;
};
