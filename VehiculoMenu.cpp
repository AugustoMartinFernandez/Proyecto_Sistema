#include <iostream>
#include "VehiculoMenu.h"

using namespace std;

VehiculoMenu::VehiculoMenu(){
  _cantidadOpciones = 4; // 1..4 y 0 para salir
}

void VehiculoMenu::mostrar(){
  int opcion;
  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    if(opcion != 0) system("pause");
  }while(opcion != 0);
}

void VehiculoMenu::mostrarOpciones(){
  cout << "--- MENU VEHICULOS ---" << endl;
  cout << "1- ALTA DE VEHICULO" << endl;
  cout << "2- LISTAR VEHICULOS" << endl;
  cout << "3- MODIFICAR VEHICULO" << endl;
  cout << "4- BAJA LOGICA DE VEHICULO" << endl;
  cout << "0- SALIR" << endl;
}

int VehiculoMenu::seleccionOpcion(){
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

void VehiculoMenu::ejecutarOpcion(int opcion){
  switch(opcion){
    case 1: _vehiculoManager.altaVehiculo();      break;
    case 2: _vehiculoManager.listarVehiculos();   break;
    case 3: _vehiculoManager.modificarVehiculo(); break;
    case 4: _vehiculoManager.bajaVehiculo();      break;
    case 0: /* salir */                            break;
  }
}

