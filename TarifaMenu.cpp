#include <iostream>
#include "TarifaMenu.h"

using namespace std;

TarifaMenu::TarifaMenu(){
  _cantidadOpciones = 4;
}

void TarifaMenu::mostrar(){
  int opcion;
  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    if(opcion != 0) system("pause");
  }while(opcion != 0);
}

void TarifaMenu::mostrarOpciones(){
  cout << "--- MENU TARIFAS ---" << endl;
  cout << "1- ALTA DE TARIFA" << endl;
  cout << "2- LISTAR TARIFAS" << endl;
  cout << "3- MODIFICAR TARIFA" << endl;
  cout << "4- BAJA LOGICA TARIFA" << endl;
  cout << "0- Salir" << endl;
}

int TarifaMenu::seleccionOpcion(){
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

void TarifaMenu::ejecutarOpcion(int opcion){
  switch(opcion){
    case 1: _tarifaManager.altaTarifa();       break;
    case 2: _tarifaManager.listarTarifas();    break;
    case 3: _tarifaManager.modificarTarifa();  break;
    case 4: _tarifaManager.bajaTarifa();       break;
    // case 0: salir
  }
}
