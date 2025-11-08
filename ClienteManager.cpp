#include "ClienteManager.h"
#include "Cliente.h"   // Para crear un objeto Cliente
#include "Vehiculo.h"  // Para leer y modificar vehículos
#include <iostream>
#include <cstring>

using namespace std;

// Constructor: Inicializa las clases de archivo
ClienteManager::ClienteManager(const std::string& rutaClientes, const std::string& rutaVehiculos)
    : _archivoClientes(rutaClientes), _archivoVehiculos(rutaVehiculos) {}

// Lógica movida desde 'case 1'
void ClienteManager::altaCliente() {
    Cliente cliente;
    cliente.cargar(); // La clase Cliente sabe cómo cargarse

    int posExistente = _archivoClientes.buscarPorDni(cliente.getDni());
    
    if (posExistente >= 0) {
        cout << "[!] El cliente con DNI " << cliente.getDni() << " ya existe en el sistema." << endl;
    } else {
        if (_archivoClientes.guardar(cliente)) {
            cout << "[+] Cliente guardado correctamente." << endl;
        } else {
            cout << "[!] Error al guardar el cliente." << endl;
        }
    }
}

// Lógica movida desde 'case 2'
void ClienteManager::listarClientesActivos() {
    int cant = _archivoClientes.getCantidadRegistros();
    
    if (cant == 0) {
        cout << "No hay clientes cargados." << endl;
        return;
    }
    
    bool hayActivos = false;
    for (int i = 0; i < cant; i++) {
        Cliente reg = _archivoClientes.leer(i);
        if (reg.getEstado()) { // Solo muestra si estado es true
            reg.mostrar();
            cout << "------------------------" << endl;
            hayActivos = true;
        }
    }

    if (!hayActivos) {
        cout << "No hay clientes activos." << endl;
    }
}

// Lógica movida desde 'case 3'
void ClienteManager::buscarClientePorDni() {
    char dni[10];
    cout << "Ingrese DNI a buscar: ";
    cin >> dni;

    int pos = _archivoClientes.buscarPorDni(dni);
    
    if (pos >= 0) {
        Cliente reg = _archivoClientes.leer(pos);
        reg.mostrar();
    } else {
        cout << "[!] Cliente con DNI " << dni << " no encontrado o inactivo." << endl;
    }
}

// Lógica movida desde 'case 4'
void ClienteManager::modificarCliente() {
    char dni[10];
    cout << "Ingrese DNI a modificar: ";
    cin >> dni;

    int pos = _archivoClientes.buscarPorDni(dni);
    
    if (pos >= 0) {
        Cliente reg = _archivoClientes.leer(pos);
        cout << "Datos actuales:" << endl;
        reg.mostrar();
        cout << "------------------------" << endl;
        
        cout << "Ingrese los nuevos datos:" << endl;
        reg.cargar(); // El cliente se carga a sí mismo con nuevos datos

        if (_archivoClientes.sobreescribir(reg, pos)) {
            cout << "[+] Cliente modificado correctamente." << endl;
        } else {
            cout << "[!] Error al modificar el cliente." << endl;
        }
    } else {
        cout << "[!] Cliente con DNI " << dni << " no encontrado o inactivo." << endl;
    }
}

// Lógica movida desde 'case 5'
void ClienteManager::bajaCliente() {
    char dni[10];
    cout << "Ingrese DNI a dar de baja: ";
    cin >> dni;

    int pos = _archivoClientes.buscarPorDni(dni);
    
    if (pos >= 0) {
        Cliente reg = _archivoClientes.leer(pos);
        
        char conf;
        cout << "Cliente encontrado: " << reg.getNombre() << " " << reg.getApellido() << endl;
        cout << "Confirma la baja? (S/N): ";
        cin >> conf;
        
        if (conf != 'S' && conf != 's') {
            cout << "Operacion cancelada." << endl;
            return;
        }

        // 1. Dar de baja al Cliente
        reg.setEstado(false); // Baja lógica
        if (!_archivoClientes.sobreescribir(reg, pos)) {
            cout << "[!] Error al dar de baja al cliente." << endl;
            return;
        }
        cout << "[+] Cliente dado de baja correctamente." << endl;

        // 2. Dar de baja en cascada a sus Vehículos
        int cantVeh = _archivoVehiculos.getCantidadRegistros();
        int vehBajos = 0;
        for (int i = 0; i < cantVeh; i++) {
            Vehiculo v = _archivoVehiculos.leer(i);
            // Si el DNI coincide y el vehículo está activo ("Retirado" es inactivo)
            if (strcmp(v.getDniCliente(), dni) == 0 && strcmp(v.getEstado(), "Retirado") != 0) {
                v.setEstado("Retirado"); // Baja lógica de vehículo
                _archivoVehiculos.sobreescribir(v, i);
                vehBajos++;
            }
        }
        
        if (vehBajos > 0) {
            cout << "[+] " << vehBajos << " vehiculo(s) asociados fueron marcados como 'Retirado'." << endl;
        }

    } else {
        cout << "[!] Cliente con DNI " << dni << " no encontrado o inactivo." << endl;
    }
}
