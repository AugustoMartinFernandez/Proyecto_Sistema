#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ManagerCliente.h"
#include "ArchivoVehiculo.h"
#include "Cliente.h"
#include "ArchivoCliente.h"
using namespace std;

ManagerCliente::ManagerCliente(const string& nombreArchivo) : _repo(nombreArchivo) {}

void ManagerCliente::mostrarLista(const Cliente& cliente) {
    cliente.mostrar();
}

// Alta de cliente con validacin de DNI
void ManagerCliente::cargar() {
    Cliente cliente;
    cliente.cargar();

    int posExistente = _repo.buscarPorDni(cliente.getDni());
    if (posExistente >= 0) {
        cout << "El cliente con DNI " << cliente.getDni() << " ya existe en el sistema." << endl;
        return;
    }

    if (_repo.guardar(cliente)) cout << "Cliente guardado correctamente.\n";
    else cout << "Error al guardar el cliente.\n";
}

// Listar clientes activos
void ManagerCliente::mostrar() {
    int cant = _repo.getCantidadRegistros();
    if (cant <= 0) {
        cout << "No hay clientes cargados." << endl;
        return;
    }

    bool hayActivos = false;
    for (int i = 0; i < cant; i++) {
        Cliente reg = _repo.leer(i);
        if (reg.getEstado()) {
            reg.mostrar();
            hayActivos = true;
        }
    }
    if (!hayActivos) cout << "No hay clientes activos." << endl;
}

// Buscar cliente por DNI
void ManagerCliente::buscar() {
    int cant = _repo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes cargados." << endl;
        return;
    }

    char dni[10];
    cout << "Ingrese DNI: ";
    cin >> dni;

    int pos = _repo.buscarPorDni(dni);
    if (pos >= 0) {
        Cliente reg = _repo.leer(pos);
        reg.mostrar();
    }
    else {
        cout << "Cliente con DNI " << dni << " no encontrado.\n";
    }
}

// Modificar cliente
void ManagerCliente::actualizar() {
    int cant = _repo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes cargados." << endl;
        return;
    }

    char dni[10];
    cout << "Ingrese DNI a modificar: ";
    cin >> dni;

    int pos = _repo.buscarPorDni(dni);
    if (pos >= 0) {
        Cliente reg = _repo.leer(pos);
        cout << "Datos actuales:\n";
        reg.mostrar();
        cout << "Ingrese nuevos datos:\n";
        reg.cargar();

        if (_repo.sobreescribir(reg, pos)) cout << "Cliente modificado correctamente.\n";
        else cout << "Error al modificar el cliente.\n";
    }
    else {
        cout << "Cliente con DNI " << dni << " no encontrado.\n";
    }
}

// Baja lógica de cliente y vehículos asociados
void ManagerCliente::eliminar() {
    int cant = _repo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay clientes cargados." << endl;
        return;
    }

    char dni[10];
    cout << "Ingrese DNI a dar de baja: ";
    cin >> dni;

    int pos = _repo.buscarPorDni(dni);
    if (pos >= 0) {
        Cliente baja = _repo.leer(pos);
        baja.setEstado(false);
        _repo.sobreescribir(baja, pos);
        cout << "Cliente dado de baja correctamente.\n";

        // También dar de baja sus vehículos
        ArchivoVehiculo archVehiculo("Archivos.dat/vehiculos.dat");
        int cantVeh = archVehiculo.getCantidadRegistros();
        for (int i = 0; i < cantVeh; i++) {
            Vehiculo v = archVehiculo.leer(i);
            if (strcmp(v.getDniCliente(), dni) == 0 && strcmp(v.getEstado(), "Retirado") != 0) {
                v.setEstado("Retirado");
                archVehiculo.sobreescribir(v, i);
            }
        }
        cout << "Todos los vehículos del cliente fueron marcados como retirados.\n";
    }
    else {
        cout << "Cliente con DNI " << dni << " no encontrado.\n";
    }
}

