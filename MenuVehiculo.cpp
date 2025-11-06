#include <iostream>
#include <cstdlib>
#include "Vehiculo.h"
#include "ArchivoCliente.h"
#include "ArchivoVehiculo.h"
using namespace std;

void menuVehiculo(){
	ArchivoVehiculo arch;
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
    cout << "Opcion: "; cin >> opcion; 
    cin.ignore();

    switch (opcion) {
    case 1: {
        Vehiculo v;
        v.cargar();

        ArchivoCliente archCliente("Archivos.dat/clientes.dat");
        int posCliente = archCliente.buscarPorDni(v.getDniCliente());
        if (posCliente == -1) {
            cout << "Error: El DNI ingresado no corresponde a un cliente activo." << endl;
            system("pause");
            break;
        }
        // Validar que la patente no este repetida
        int posVeh = arch.buscarPorPatente(v.getPatente());
        if (posVeh >= 0) {
            cout << "La patente ya existe en el sistema." << endl;
        }
        else {
            if (arch.guardar(v)) {
                cout << "Vehiculo guardado correctamente." << endl;
            }
            else {
                cout << "Error al guardar vehiculo" << endl;
            }
        }
        system("pause");
        break;
    }
    case 2: {
        int cant = arch.getCantidadRegistros();
        if (cant == 0) {
            cout << "No hay vehiculos cargados." << endl;
        }
        else {
            arch.listar();
        }
        system("pause");
        break;
    }
    case 3: {
        char patente[8];
        cout << "Ingrese patente: ";
        cin >> patente;
        int pos = arch.buscarPorPatente(patente);
        if (pos >= 0) {
            Vehiculo r = arch.leer(pos);
            r.mostrar();
        }
        else {
            cout << "Patente no encontrada." << endl;
        }
        system("pause");
        break;
    }
    case 4:{
        char patente[8];
        cout << "Ingrese patente a modificar: ";
        cin >> patente;
        int pos = arch.buscarPorPatente(patente);
        if (pos >= 0) {
            Vehiculo r = arch.leer(pos);
            cout << "Datos actuales:\n"; r.mostrar();
            cout << "Ingrese nuevos datos:\n"; r.cargar();
            if (arch.sobreescribir(r, pos)) {
                cout << "Vehiculo modificado correctamente" << endl;
            }
            else {
                cout << "Error al modificar." << endl;
            }
        }
        else {
            cout << "Patente no encontrada." << endl;
        }
        system("pause");
        break;
    }
    case 5: {
        char patente[8];
        cout << "Ingrese patente a dar de baja";
        cin >> patente;
        int pos = arch.buscarPorPatente(patente);
        if (pos >=0) {
            Vehiculo r = arch.leer(pos);
            r.setEstado("Retirado");
            arch.sobreescribir(r, pos);
            cout << "Vehiculo marcado como retirado" << endl;
        }
        else {
            cout << "Patente no encontrada" << endl;
        }
        system("pause");
        break;
    }
    case 0:
        break;
    default:
        cout << "Opcion invalida" << endl;
        system("pause");
    }

} while (opcion!= 0);
}