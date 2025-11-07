#include <iostream>
#include <cstdlib>
#include "ManagerVehiculo.h"
using namespace std;

void menuVehiculo() {
    ManagerVehiculo manager("Archivos.dat/vehiculos.dat");
    int opcion;
    do {
        cout << "==============================" << endl;
        cout << "       MENU VEHICULOS        " << endl;
        cout << "==============================" << endl;
        cout << "1 - Alta de vehiculo" << endl;
        cout << "2 - Listar vehiculos" << endl;
        cout << "3 - Buscar por patente" << endl;
        cout << "4 - Modificar vehiculo" << endl;
        cout << "5 - Marcar como retirado (baja logica)" << endl;
        cout << "0 - Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: manager.cargar(); break;
        case 2: manager.mostrar(); break;
        case 3: manager.buscar(); break;
        case 4: manager.actualizar(); break;
        case 5: manager.eliminar(); break;
        case 0: cout << "Volviendo...\n"; break;
        default: cout << "Opcion invalida\n"; break;
        }
        system("pause");
    } while (opcion != 0);
}