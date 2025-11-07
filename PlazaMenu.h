#ifndef PLAZAMENU_H
#define PLAZAMENU_H

#include "PlazaManager.h" // El Menú usa el Manager

class PlazaMenu {
public:
    PlazaMenu();
    void mostrar(); // Método principal que inicia el bucle

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

private:
    PlazaManager _plazaManager; // El Menú TIENE UN Manager
    int _cantidadOpciones;
};

#endif // PLAZAMENU_H
