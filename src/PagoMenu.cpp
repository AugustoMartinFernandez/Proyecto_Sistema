#include <iostream>
#include "PagoMenu.h"

using namespace std;

PagoMenu::PagoMenu(){
  _cantidadOpciones = 4;
}

void PagoMenu::mostrar(){
  int opcion;
  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    if(opcion != 0) system("pause");
  }while(opcion != 0);
}

void PagoMenu::mostrarOpciones(){
  cout << "--- MENU PAGOS ---" << endl;
  cout << "1- ALTA DE PAGO" << endl;
  cout << "2- LISTAR PAGOS" << endl;
  cout << "3- MODIFICAR PAGO" << endl;
  cout << "4- BAJA LOGICA DE PAGO" << endl;
  cout << "0- SALIR" << endl;
}

int PagoMenu::seleccionOpcion(){
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

void PagoMenu::ejecutarOpcion(int opcion){
  switch(opcion){
    case 1:
      _pagoManager.altaPago();
      break;
    case 2:
      _pagoManager.listarPagos();
      break;
    case 3:
      _pagoManager.modificarPago();
      break;
    case 4:
      _pagoManager.bajaPago();
      break;
    case 0:
      cout << "Saliendo del menu de pagos..." << endl;
      break;
  }
}
