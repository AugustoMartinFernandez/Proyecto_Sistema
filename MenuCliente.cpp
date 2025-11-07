#include <iostream>
#include <stdlib.h>
#include "ManagerCliente.h"
using namespace std;

void menuCliente() {
    ManagerCliente manager("Archivos.dat/clientes.dat");
    int opcion;
    do {
        system("cls");
        cout << "==============================" << endl;
        cout << "        MENU CLIENTES         " << endl;
        cout << "==============================" << endl;
        cout << "1 - Alta de cliente" << endl;
        cout << "2 - Listar clientes activos" << endl;
        cout << "3 - Buscar cliente por DNI" << endl;
        cout << "4 - Modificar cliente" << endl;
        cout << "5 - Baja logica" << endl;
        cout << "0 - Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            manager.cargar();     
            system("pause");
            break;
        case 2:
            manager.mostrar();    
            system("pause");
            break;
        case 3:
            manager.buscar();     
            system("pause");
            break;
        case 4:
            manager.actualizar();  
            system("pause");
            break;
        case 5:
            manager.eliminar();    
            system("pause");
            break;
        case 0:
            cout << "Volviendo al menu principal...\n";
            system("pause");
            break;
        default:
            cout << "Opcion invalida.\n";
            system("pause");
            break;
        }
    } while (opcion != 0);
}