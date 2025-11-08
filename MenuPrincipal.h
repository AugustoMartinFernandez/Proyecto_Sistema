#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

// Incluimos los sub-menús que vamos a llamar
#include "PlazaMenu.h"
#include "AbonoMenu.h"
#include "ClienteMenu.h"  
#include "MenuVehiculo.h" 
#include "TarifaMenu.h"   
#include "TicketMenu.h"
#include "PagoMenu.h"
// #include "ReservaMenu.h" // (Pendiente para cuando se cree)

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
    // NOTA: No necesitamos tener los Menús como miembros
    // si solo los vamos a llamar una vez. Los creamos en la pila.
};

#endif // MENUPRINCIPAL_H
