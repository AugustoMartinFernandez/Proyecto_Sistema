#include "AbonoMenu.h"
#include <iostream>
#include <cstdlib> 

using namespace std;

AbonoMenu::AbonoMenu() {
    _cantidadOpciones = 4; // 1.Alta, 2.Listar, 3.Modificar, 4.Baja
}

void AbonoMenu::mostrar() {
    int opcion;
    
    do {
        system("cls || clear"); // Limpia la pantalla
        opcion = seleccionOpcion();
        system("cls || clear");
        ejecutarOpcion(opcion);
        
        if (opcion != 0) {
            system("pause"); // Espera que el usuario presione una tecla
        }
    } while (opcion != 0);
}

void AbonoMenu::mostrarOpciones() {
    cout << "--- GESTION DE ABONOS ---" << endl;
    cout << "1 - Alta de Abono" << endl;
    cout << "2 - Listar Abonos" << endl;
    cout << "3 - Modificar Abono" << endl;
    cout << "4 - Baja de Abono" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - Volver al Menu Principal" << endl;
    cout << "---------------------------------" << endl;
}

int AbonoMenu::seleccionOpcion() {
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

void AbonoMenu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            // El Menú le delega la tarea al Manager
            _abonoManager.altaAbono();
            break;
        case 2:
            _abonoManager.listarAbonos();
            break;
        case 3:
            _abonoManager.modificarAbono();
            break;
        case 4:
            _abonoManager.bajaAbono();
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
    }
}
