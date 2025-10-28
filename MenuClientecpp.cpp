#include <iostream>
#include <stdlib.h>
#include "ArchivoCliente.h"
using namespace std;

void menuCliente() {
    ArchivoCliente arch;
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
        case 1: {
            Cliente cliente;
            cliente.cargar();
            int posExistente = arch.buscarPorDni(cliente.getDni());
            if (posExistente >= 0) {
                cout << "El cliente con DNI " << cliente.getDni() << " ya existe en el sistema." << endl;
            }
            else {
                if (arch.guardar(cliente)) cout << "Cliente guardado.\n";
                else cout << "Error al guardar.\n";
            }
            system("pause");
            break;
        }
        case 2: {
            arch.listar();
            system("pause");
            break;
        }
        case 3: {
            int cant = arch.getCantidadRegistros();
            if (cant == 0) {
                cout << "No hay clientes cargados." << endl;
                system("pause");
                break;
            }
            char dni[10];
            cout << "Ingrese DNI: ";
            cin >> dni;
            int pos = arch.buscarPorDni(dni);
            if (pos >= 0) {
                Cliente registros = arch.leer(pos);
                registros.mostrar();
            }
            else cout << "No encontrado.\n";
            system("pause");
            break;
        }
        case 4: {
            char dni[10];
            cout << "Ingrese DNI a modificar: ";
            cin >> dni;
            int pos = arch.buscarPorDni(dni);
            if (pos >= 0) {
                Cliente Cdni = arch.leer(pos);
                cout << "Datos actuales:\n";
                Cdni.mostrar();
                cout << "Ingrese nuevos datos:\n";
                Cdni.cargar();
                if (arch.sobreescribir(Cdni, pos)) cout << "Cliente modificado.\n";
                else cout << "Error al modificar.\n";
            }
            else cout << "No encontrado.\n";
            system("pause");
            break;
        }
        case 5: {
            char dni[10];
            cout << "Ingrese DNI a dar de baja: ";
            cin >> dni;
            int pos = arch.buscarPorDni(dni);
            if (pos >= 0) {
                Cliente baja = arch.leer(pos);
                baja.setEstado(false);
                arch.sobreescribir(baja, pos);
                cout << "Cliente dado de baja.\n";
            }
            else cout << "No encontrado.\n";
            system("pause");
            break;
        }
        case 0: cout << "Volviendo al menu principal...\n"; 
            system("pause");
            break;
        default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 0);
}
