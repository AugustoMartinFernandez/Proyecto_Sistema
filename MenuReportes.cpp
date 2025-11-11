#include "MenuReportes.h"
#include <iostream>
#include <cstdlib>

using namespace std;

MenuReportes::MenuReportes() {
    _cantidadOpciones = 4;
}

void MenuReportes::mostrar() {
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

void MenuReportes::mostrarOpciones() {
    cout << "=== REPORTES ===" << endl;
    cout << "1. Recaudaciones anual" << endl;
    cout << "2. Recaudaciones mensual" << endl;
    cout << "3. Recaudaciones diaria" << endl;
    cout << "4. Recaudacion por tipo de vehiculo" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << "---------------------------------" << endl;
}

int MenuReportes::seleccionOpcion() {
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

void MenuReportes::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
        {
            ReporteRecaudacionManager rrm;
            rrm.recaudacionAnual();
            break;
        }
        case 2:
        {
            ReporteRecaudacionManager rrm;
            rrm.recaudacionMensual();
            break;
        }
        case 3:
        {
            ReporteRecaudacionManager rrm;
            rrm.recaudacionDiaria();
            break;
        }
        case 4:
        {
            ReporteRecaudacionManager rrm;
            rrm.recaudacionPorTipoVehiculo();
            break;
        }
        case 0:
            cout << "Volviendo al menu principal..."  << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }
}
