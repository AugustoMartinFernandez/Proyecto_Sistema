#include "PlazaMenu.h"
#include <iostream>
#include <cstdlib> // Para system("cls") y system("pause")

using namespace std;

PlazaMenu::PlazaMenu() {
    _cantidadOpciones = 4; // 1.Alta, 2.Listar, 3.Modificar, 4.Baja
}

void PlazaMenu::mostrar() {
    int opcion;
    
    do {
        system("cls || clear"); // Limpia la pantalla (para Windows || Linux)
        opcion = seleccionOpcion();
        system("cls || clear");
        ejecutarOpcion(opcion);
        
        if (opcion != 0) {
            system("pause"); // Espera que el usuario presione una tecla
        }
    } while (opcion != 0);
}

void PlazaMenu::mostrarOpciones() {
    cout << "--- GESTION DE PLAZAS ---" << endl;
    cout << "1 - Alta de Plaza" << endl;
    cout << "2 - Listar Plazas" << endl;
    cout << "3 - Modificar Plaza" << endl;
    cout << "4 - Baja (Fuera de Servicio) de Plaza" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - Volver al Menu Principal" << endl;
    cout << "---------------------------------" << endl;
}

int PlazaMenu::seleccionOpcion() {
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

void PlazaMenu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            // El Menú le delega la tarea al Manager
            _plazaManager.altaPlaza();
            break;
        case 2:
            _plazaManager.listarPlazas();
            break;
        case 3:
            _plazaManager.modificarPlaza();
            break;
        case 4:
            _plazaManager.bajaPlaza();
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
    }
}
