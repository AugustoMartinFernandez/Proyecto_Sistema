#include <iostream>
using namespace std;

// Declaraciones de submenús
void menuCliente();
void menuVehiculo();

int main() {
    int opcion;
    do {
        cout << "==============================" << endl;
        cout << "   SISTEMA DE ESTACIONAMIENTO " << endl;
        cout << "==============================" << endl;
        cout << "1 - Clientes" << endl;
        cout << "2 - Vehiculos" << endl;
        cout << "3 - Plazas" << endl;
        cout << "4 - Reservas" << endl;
        cout << "5 - Tickets" << endl;
        cout << "6 - Pagos" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: menuCliente(); break;
        case 2: menuVehiculo(); break;
        case 3: cout << "Submenu Plazas (pendiente)\n"; break;
        case 4: cout << "Submenu Reservas (pendiente)\n"; break;
        case 5: cout << "Submenu Tickets (pendiente)\n"; break;
        case 6: cout << "Submenu Pagos (pendiente)\n"; break;
        case 0: cout << "Saliendo del sistema...\n"; break;
        default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}
