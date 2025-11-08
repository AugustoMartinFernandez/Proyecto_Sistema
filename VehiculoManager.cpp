#include "VehiculoManager.h"
#include "Vehiculo.h" // Para crear un objeto Vehiculo
#include "Cliente.h"  // Para validar
#include <iostream>
#include <cstring>

using namespace std;

VehiculoManager::VehiculoManager(const std::string& rutaVehiculos, const std::string& rutaClientes)
    : _archivoVehiculos(rutaVehiculos), _archivoClientes(rutaClientes) {}

void VehiculoManager::altaVehiculo() {
    Vehiculo v;
    v.cargar(); 

    // 1. Validar que el DNI del cliente exista
    int posCliente = _archivoClientes.buscarPorDni(v.getDniCliente());
    if (posCliente == -1) {
        cout << "[!] Error: El DNI " << v.getDniCliente() << " no corresponde a un cliente activo." << endl;
        return; 
    }
    
    // 2. Validar que la patente no esté repetida
    int posVeh = _archivoVehiculos.buscarPorPatente(v.getPatente());
    if (posVeh >= 0) {
        cout << "[!] Error: La patente " << v.getPatente() << " ya existe en el sistema." << endl;
    } else {
        // Si ambas validaciones son correctas, guardamos
        if (_archivoVehiculos.guardar(v)) {
            cout << "[+] Vehiculo guardado correctamente." << endl;
        } else {
            cout << "[!] Error al guardar el vehiculo." << endl;
        }
    }
}


void VehiculoManager::listarVehiculos() {
    int cant = _archivoVehiculos.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay vehiculos cargados." << endl;
        return;
    }
    
    // Usamos el método listar() de ArchivoVehiculo, que ya filtra por estado "Retirado"
    _archivoVehiculos.listar();
}


void VehiculoManager::buscarVehiculoPorPatente() {
    char patente[10];
    cout << "Ingrese patente a buscar: ";
    cin >> patente;

    int pos = _archivoVehiculos.buscarPorPatente(patente);
    
    if (pos >= 0) {
        Vehiculo reg = _archivoVehiculos.leer(pos);
        reg.mostrar();
    } else {
        cout << "[!] Patente no encontrada." << endl;
    }
}


void VehiculoManager::modificarVehiculo() {
    char patente[10];
    cout << "Ingrese patente a modificar: ";
    cin >> patente;

    int pos = _archivoVehiculos.buscarPorPatente(patente);
    
    if (pos >= 0) {
        Vehiculo reg = _archivoVehiculos.leer(pos);
        cout << "Datos actuales:" << endl;
        reg.mostrar();
        cout << "------------------------" << endl;
        
        cout << "Ingrese los nuevos datos:" << endl;
        reg.cargar(); 

        if (_archivoVehiculos.sobreescribir(reg, pos)) {
            cout << "[+] Vehiculo modificado correctamente." << endl;
        } else {
            cout << "[!] Error al modificar el vehiculo." << endl;
        }
    } else {
        cout << "[!] Patente no encontrada." << endl;
    }
}


void VehiculoManager::bajaVehiculo() {
    char patente[10];
    cout << "Ingrese patente a marcar como 'Retirado': ";
    cin >> patente;

    int pos = _archivoVehiculos.buscarPorPatente(patente);
    
    if (pos >= 0) {
        Vehiculo reg = _archivoVehiculos.leer(pos);
        
        char conf;
        cout << "Vehiculo encontrado: " << reg.getPatente() << endl;
        cout << "Confirmar la baja (Marcar como 'Retirado')? (S/N): ";
        cin >> conf;
        
        if (conf != 'S' && conf != 's') {
            cout << "Operacion cancelada." << endl;
            return;
        }

        reg.setEstado("Retirado"); // Baja lógica
        if (_archivoVehiculos.sobreescribir(reg, pos)) {
            cout << "[+] Vehiculo marcado como 'Retirado' correctamente." << endl;
        } else {
            cout << "[!] Error al actualizar el estado del vehiculo." << endl;
        }
    } else {
        cout << "[!] Patente no encontrada." << endl;
    }
}
