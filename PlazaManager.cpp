#include "PlazaManager.h"
#include <iostream>
#include <cstring>

using namespace std;

PlazaManager::PlazaManager(const char* rutaPlazas) : _archivoPlazas(std::string(rutaPlazas)) {}

void PlazaManager::altaPlaza() {
    Plaza reg; 

    cout << "--- ALTA NUEVA PLAZA ---" << endl;
    
    int numero, piso;
    char sector[2], tipo[21];
    
    cout << "Numero de Plaza: ";
    cin >> numero;
    cout << "Piso: ";
    cin >> piso;
    cout << "Sector (ej: A, B): ";
    cin >> sector;
    cout << "Tipo de Vehiculo (ej: Auto, Moto): ";
    cin >> tipo;

    reg.setNumero(numero);
    reg.setPiso(piso);
    reg.setSector(sector);
    reg.setTipo(tipo);
    
    int proximoID = _archivoPlazas.getCantidadRegistros() + 1;
    reg.setIdPlaza(proximoID);
    reg.setEstado('L'); 

    if (_archivoPlazas.guardar(reg)) {
        cout << "[+] Plaza ID " << proximoID << " guardada correctamente." << endl;
    } else {
        cout << "[!] Error al guardar la plaza en el archivo." << endl;
    }
}

void PlazaManager::listarPlazas() {
    cout << "--- LISTADO DE PLAZAS ---" << endl;
    
    int cantidad = _archivoPlazas.getCantidadRegistros();
    
    if (cantidad == 0) {
        cout << "No hay plazas registradas." << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Plaza reg = _archivoPlazas.leer(i);
        
        if (reg.getIdPlaza() != -1 && reg.getEstado() != 'F') { 
            reg.mostrar();
            cout << "------------------------" << endl;
        }
    }
}

void PlazaManager::modificarPlaza() {
    cout << "Funcion MODIFICAR PLAZA no implementada." << endl;
}

void PlazaManager::bajaPlaza() {
    cout << "Funcion BAJA PLAZA no implementada." << endl;
}
