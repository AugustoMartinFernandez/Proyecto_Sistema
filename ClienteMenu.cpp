#include <iostream>
#include "ClienteMenu.h"

using namespace std;

ClienteMenu::ClienteMenu()
{
    _cantidadOpciones = 4;
}

void ClienteMenu::mostrar()
{
    int opcion;
    do
    {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
        if(opcion != 0) system("pause");
    }
    while(opcion != 0);
}

void ClienteMenu::mostrarOpciones()
{
    cout << "--- MENU CLIENTES ---" << endl;
    cout << "1- ALTA DE CLIENTE" << endl;
    cout << "2- LISTAR CLIENTES" << endl;
    cout << "3- MODIFICAR CLIENTE" << endl;
    cout << "4- BAJA LOGICA DE CLIENTE" << endl;
    cout << "0- SALIR" << endl;
}

int ClienteMenu::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    cout << "---------------" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "Opcion incorrecta..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    return opcion;
}

void ClienteMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
        _clienteManager.altaCliente();
        break;
    case 2:
        _clienteManager.listarClientes();
        break;
    case 3:
        _clienteManager.modificarCliente();
        break;
    case 4:
        _clienteManager.bajaCliente();
        break;
    case 0: /* salir */
        break;
    }
}
