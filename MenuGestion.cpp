#include "MenuGestion.h"
#include <iostream>
#include <cstdlib>

using namespace std;

MenuGestion::MenuGestion() {
    _cantidadOpciones = 8;
}

void MenuGestion::mostrar() {
    int opcion;
    do {
        system("cls || clear");
        opcion = seleccionOpcion();
        system("cls || clear");
        ejecutarOpcion(opcion);

        if (opcion != 0) {
            system("pause");
        }
    } while (opcion != 0);
}

void MenuGestion::mostrarOpciones() {
    cout << "=== GESTION MANUAL ===" << endl;
    cout << "1. Gestion de Plazas" << endl;
    cout << "2. Gestion de Abonos" << endl;
    cout << "3. Gestion de Clientes" << endl;
    cout << "4. Gestion de Vehiculos" << endl;
    cout << "5. Gestion de Tarifas" << endl;
    cout << "6. Gestion de Reservas" << endl;
    cout << "7. Gestion de Tickets" << endl;
    cout << "8. Gestion de Pagos" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << "---------------------------------" << endl;
}

int MenuGestion::seleccionOpcion() {
    int opcion;
    mostrarOpciones();
    cout << "Seleccione un modulo: ";
    cin >> opcion;
    while (opcion < 0 || opcion > _cantidadOpciones) {
        cout << "[!] Opcion incorrecta. Vuelva a ingresar." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    return opcion;
}

void MenuGestion::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
        {
            PlazaMenu menuPlazas;
            menuPlazas.mostrar();
            break;
        }
        case 2:
        {
            AbonoMenu menuAbonos;
            menuAbonos.mostrar();
            break;
        }
        case 3:
        {
            ClienteMenu menuClientes;
            menuClientes.mostrar();
            break;
        }
        case 4:
        {
            VehiculoMenu menuVehiculos;
            menuVehiculos.mostrar();
            break;
        }
        case 5:
        {
            TarifaMenu menuTarifas;
            menuTarifas.mostrar();
            break;
        }
        case 6:
        {
            ReservaMenu menuReservas;
            menuReservas.mostrar();
            break;
        }
        case 7:
        {
            TicketMenu menuTickets;
            menuTickets.mostrar();
            break;
        }
        case 8:
        {
            PagoMenu menuPagos;
            menuPagos.mostrar();
            break;
        }
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }
}
