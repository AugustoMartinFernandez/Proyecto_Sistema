#include "ClienteMenu.h"
#include <iostream>
#include <cstdlib> // Para system("cls") y system("pause")

using namespace std;

ClienteMenu::ClienteMenu() {
    _cantidadOpciones = 5; // 1.Alta, 2.Listar, 3.Buscar, 4.Modificar, 5.Baja
}

void ClienteMenu::mostrar() {
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

void ClienteMenu::mostrarOpciones() {
    cout << "--- GESTION DE CLIENTES ---" << endl;
    cout << "1 - Alta de cliente" << endl;
    cout << "2 - Listar clientes activos" << endl;
    cout << "3 - Buscar cliente por DNI" << endl;
    cout << "4 - Modificar cliente" << endl;
    cout << "5 - Baja logica de cliente" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - Volver al Menu Principal" << endl;
    cout << "---------------------------------" << endl;
}

int ClienteMenu::seleccionOpcion() { 
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

void ClienteMenu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            _clienteManager.altaCliente();
            break;
        case 2:
            _clienteManager.listarClientesActivos();
            break;
        case 3:
            _clienteManager.buscarClientePorDni();
            break;
        case 4:
            _clienteManager.modificarCliente();
            break;
        case 5:
            _clienteManager.bajaCliente();
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
    }
}
