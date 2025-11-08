#pragma once
#include "AbonoManager.h" 

class AbonoMenu {
public:
    AbonoMenu();
    void mostrar(); 

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    AbonoManager _abonoManager; 
    int _cantidadOpciones;
};
