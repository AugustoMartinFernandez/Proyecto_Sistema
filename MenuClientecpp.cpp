#include <iostream>
#include <stdlib.h>
#include "ArchivoCliente.h"
#include "ArchivoVehiculo.h"
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
                if (arch.guardar(cliente)) cout << "Cliente guardado correctamente.\n";
                else cout << "Error al guardar el cliente.\n";
            }
            system("pause");
            break;
        }
        case 2: {
            int cant = arch.getCantidadRegistros();
            if (cant == -1) {
                cout << "No se pudo abrir el archivo de clientes." << endl;
            }
            else if (cant == 0) {
                cout << "No hay clientes cargados." << endl;
            }
            else {
                bool hayActivos = false;
                for (int i = 0; i < cant; i++) {
                    Cliente reg = arch.leer(i);
                    if (reg.getEstado()) {
                        reg.mostrar();
                        hayActivos = true;
                    }
                }
                if (!hayActivos) {
                    cout << "No hay clientes activos." << endl;
                }
            }
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
            else cout << "Cliente con DNI " << dni << " no encontrado.\n";
            system("pause");
            break;
        }
        case 4: {
			int cant = arch.getCantidadRegistros();
            if(cant == 0){
				cout << "No hay clientes cargados." << endl;
                system("pause");
				break;
            }
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
                if (arch.sobreescribir(Cdni, pos)) cout << "Cliente modificado correctamente.\n";
                else cout << "Error al modificar el cliente.\n";
            }
            else cout << "Cliente con DNI " << dni << " no encontrado.\n";
            system("pause");
            break;
        }
        case 5: {
			int cant = arch.getCantidadRegistros();
            if (cant == 0) {
				cout << "No hay clientes cargados." << endl;
				system("pause");
				break;
            }
            char dni[10];
            cout << "Ingrese DNI a dar de baja: ";
            cin >> dni;
            int pos = arch.buscarPorDni(dni);
            if (pos >= 0) {
                Cliente baja = arch.leer(pos);
                baja.setEstado(false);
                arch.sobreescribir(baja, pos);
                cout << "Cliente dado de baja correctamente.\n";

                ArchivoVehiculo archVehiculo("Archivos.dat/vehiculos.dat");
                int cantVeh = archVehiculo.getCantidadRegistros();
                for (int i = 0; i < cantVeh; i++) {
                    Vehiculo v = archVehiculo.leer(i);
                    if (strcmp(v.getDniCliente(), dni) == 0 && strcmp(v.getEstado(), "Retirado") != 0) {
                        v.setEstado("Retirado");
                        archVehiculo.sobreescribir(v, i);
                    }
                }
                cout << "Todos los vehiculos del cliente fueron marcados como retirados" << endl;
            }
            else {
                cout << "Cliente con DNI " << dni << " no encontrado.\n";
            }
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
