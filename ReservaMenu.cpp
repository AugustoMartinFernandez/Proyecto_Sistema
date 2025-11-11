#include <iostream>
#include "ReservaMenu.h"

using namespace std;

ReservaMenu::ReservaMenu(){
  _cantidadOpciones = 4;   // 1..4 y 0 para salir
}

void ReservaMenu::mostrar(){
  int opcion;
  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    if(opcion != 0) system("pause");
  }while(opcion != 0);
}

void ReservaMenu::mostrarOpciones(){
  cout << "--- MENU RESERVAS ---" << endl;
  cout << "1- ALTA DE RESERVA" << endl;
  cout << "2- LISTAR RESERVAS" << endl;
  cout << "3- MODIFICAR RESERVA" << endl;
  cout << "4- BAJA LOGICA DE RESERVA" << endl;
  cout << "0- SALIR" << endl;
}

int ReservaMenu::seleccionOpcion(){
  int opcion;
  mostrarOpciones();
  cout << "---------------" << endl;
  cout << "Opcion: ";
  cin >> opcion;

  while(opcion < 0 || opcion > _cantidadOpciones){
    cout << "Opcion incorrecta..." << endl;
    cout << "Opcion: ";
    cin >> opcion;
  }
  return opcion;
}

void ReservaMenu::ejecutarOpcion(int opcion){
  switch(opcion){
    case 1: _reservaManager.altaReserva(); break;
    case 2: _reservaManager.listarReservas(); break;
    case 3: _reservaManager.modificarReserva(); break;
    case 4: _reservaManager.bajaReserva(); break;
    case 0: cout << "Volviendo al menu principal..." << endl; break;
  }
}
