#include "PlazaManager.h"
#include <iostream>
#include <cstring>

using namespace std;

PlazaManager::PlazaManager(const char* rutaPlazas) : _archivoPlazas(rutaPlazas) {}

void PlazaManager::altaPlaza() {
    Plaza reg; // Objeto local para cargar datos

    // 1. Pedir datos (Lógica del Manager)
    cout << "--- ALTA NUEVA PLAZA ---" << endl;
    
    // Datos que el usuario ingresa
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

    // 2. Setear datos en el objeto
    reg.setNumero(numero);
    reg.setPiso(piso);
    reg.setSector(sector);
    reg.setTipo(tipo);
    
    // 3. Lógica de Manager (Asignación de ID y Estado inicial)
    int proximoID = _archivoPlazas.contarRegistros() + 1;
    reg.setIdPlaza(proximoID);
    reg.setEstado('L'); // Estado inicial: Libre

    // 4. Grabar en Archivo
    if (_archivoPlazas.grabarRegistro(reg)) {
        cout << "[+] Plaza ID " << proximoID << " guardada correctamente." << endl;
    } else {
        cout << "[!] Error al guardar la plaza en el archivo." << endl;
    }
}

void PlazaManager::listarPlazas() {
    cout << "--- LISTADO DE PLAZAS ---" << endl;
    int cantidad = _archivoPlazas.contarRegistros();
    
    if (cantidad == 0) {
        cout << "No hay plazas registradas." << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Plaza reg = _archivoPlazas.leer(i);
        
        // Verificamos que no sea un registro de error y que no esté dado de baja
        if (reg.getIdPlaza() != -1 && reg.getEstado() != 'F') { 
            reg.mostrar();
            cout << "------------------------" << endl;
        }
    }
}

// (Stubs: Métodos vacíos para que el Menú compile)
void PlazaManager::modificarPlaza() {
    cout << "Funcion MODIFICAR PLAZA no implementada." << endl;
}

void PlazaManager::bajaPlaza() {
    cout << "Funcion BAJA PLAZA no implementada." << endl;
}
