#include "TicketMenu.h"
#include <iostream>
#include <cstdlib>

using namespace std;

TicketMenu::TicketMenu() {
    _cantidadOpciones = 4;
}

void TicketMenu::mostrar() {
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

void TicketMenu::mostrarOpciones() {
    cout << "--- GESTION DE TICKETS ---" << endl;
    cout << "1. Registrar Ingreso (Abrir Ticket)" << endl;
    cout << "2. Registrar Salida (Cerrar Ticket)" << endl;
    cout << "3. Listar Tickets Abiertos" << endl;
    cout << "4. Listar Historial de Tickets (Cerrados)" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - Volver al Menu Principal" << endl;
    cout << "---------------------------------" << endl;
}

int TicketMenu::seleccionOpcion() {
    int opcion;
    mostrarOpciones();
    cout << "Opcion: ";
    cin >> opcion;
    
    while (opcion < 0 || opcion > _cantidadOpciones) {
        cout << "[!] Opcion incorrecta. Vuelva a ingresar." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    return opcion;
}

void TicketMenu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            _ticketManager.registrarIngreso();
            break;
        case 2:
            _ticketManager.registrarSalida();
            break;
        case 3:
            _ticketManager.listarTicketsAbiertos();
            break;
        case 4:
            _ticketManager.listarHistorialTickets();
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
    }
}
