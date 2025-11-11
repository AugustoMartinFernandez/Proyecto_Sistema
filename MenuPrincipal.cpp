#include "MenuPrincipal.h"
#include <iostream>
#include <cstdlib>

using namespace std;

MenuPrincipal::MenuPrincipal() {
    _cantidadOpciones = 5;
}

void MenuPrincipal::mostrar() {
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

void MenuPrincipal::mostrarOpciones() {
    cout << "=== SISTEMA DE GESTION DE ESTACIONAMIENTO ===" << endl;
    cout << "1. Entrada sin reserva" << endl;
    cout << "2. Entrada con reserva" << endl;
    cout << "3. Salida y cobro" << endl;
    cout << "4. Gestion manual" << endl;
    cout << "5. Reportes" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - Salir del sistema" << endl;
    cout << "---------------------------------" << endl;
}

int MenuPrincipal::seleccionOpcion() {
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

void MenuPrincipal::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
        {
            EntradaSinReservaManager flujo;
            flujo.procesarEntrada();
            break;
        }
        case 2:
        {
            EntradaConReservaManager flujoReserva;
            flujoReserva.procesarEntrada();
            break;
        }
        case 3:
        {
            SalidaCobroManager flujoSalida;
            flujoSalida.procesarSalida();
            break;
        }
        case 4:
        {
            MenuGestion menuGestion;
            menuGestion.mostrar();
            break;
        }
        case 5:
        {
            MenuReportes menuReportes;
            menuReportes.mostrar();
            break;
        }
        case 0:
            cout << "Gracias por utilizar el sistema. Adios." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }
}
