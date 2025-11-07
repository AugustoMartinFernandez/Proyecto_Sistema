#include "MenuPrincipal.h"
#include <iostream>
#include <cstdlib>

using namespace std;

MenuPrincipal::MenuPrincipal() {
    _cantidadOpciones = 8; 
}

void MenuPrincipal::mostrar() {
    int opcion;
    do {
        system("cls || clear");
        opcion = seleccionOpciones();
        system("cls || clear");
        ejecutarOpcion(opcion);
        
        if (opcion != 0) {
            system("pause");
        }
    } while (opcion != 0);
}

void MenuPrincipal::mostrarOpciones() {
    cout << "=== SISTEMA DE GESTION DE ESTACIONAMIENTO ===" << endl;
    cout << "1. Gestion de Plazas" << endl;
    cout << "2. Gestion de Abonos" << endl;
    cout << "3. Gestion de Clientes" << endl;
    cout << "4. Gestion de Vehiculos" << endl;
    cout << "5. Gestion de Tarifas" << endl;
    cout << "6. Gestion de Reservas" << endl;
    cout << "7. Gestion de Tickets" << endl;
    cout << "8. Gestion de Pagos" << endl;
    // ... Aquí irían Informes y Configuración
    cout << "---------------------------------" << endl;
    cout << "0 - Salir del Sistema" << endl;
    cout << "---------------------------------" << endl;
}

int MenuPrincipal::seleccionOpciones() {
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
            // Creamos el sub-menú y lo mostramos
            PlazaMenu menuPlazas;
            menuPlazas.mostrar(); // Entra al bucle de PlazaMenu
            break; // Cuando sale (opcion 0), vuelve aquí
        }
        case 2:
        {
            // AbonoMenu menuAbonos;
            // menuAbonos.mostrar();
            cout << "Modulo ABONOS no implementado." << endl;
            break;
        }
        case 3:
            cout << "Modulo CLIENTES no implementado." << endl;
            break;
        // ... (Resto de los casos)
        case 0:
            cout << "Gracias por utilizar el sistema. Adios." << endl;
            break;
    }
}
