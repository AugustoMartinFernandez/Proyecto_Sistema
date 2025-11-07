#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ManagerVehiculo.h"
using namespace std;

ManagerVehiculo::ManagerVehiculo(const string& nombreArchivo) : _repo(nombreArchivo) {}

void ManagerVehiculo::mostrarLista(const Vehiculo& v) {
    v.mostrar();
}

// Alta de vehículo con validaciones
void ManagerVehiculo::cargar() {
    Vehiculo v;
    v.cargar();

    // Validar cliente activo
    ArchivoCliente archCliente("Archivos.dat/clientes.dat");
    int posCliente = archCliente.buscarPorDni(v.getDniCliente());
    if (posCliente == -1) {
        cout << "Error: El DNI ingresado no corresponde a un cliente activo." << endl;
        return;
    }

    // Validar patente única
    int posVeh = _repo.buscarPorPatente(v.getPatente());
    if (posVeh >= 0) {
        cout << "La patente ya existe en el sistema." << endl;
        return;
    }

    // Guardar vehículo
    if (_repo.guardar(v)) cout << "Vehículo guardado correctamente." << endl;
    else cout << "Error al guardar vehículo." << endl;
}

// Listar vehículos
void ManagerVehiculo::mostrar() {
    int cant = _repo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay vehículos cargados." << endl;
        return;
    }
    _repo.listar();
}

// Buscar por patente
void ManagerVehiculo::buscar() {
    char patente[8];
    cout << "Ingrese patente: ";
    cin >> patente;

    int pos = _repo.buscarPorPatente(patente);
    if (pos >= 0) {
        Vehiculo r = _repo.leer(pos);
        r.mostrar();
    }
    else {
        cout << "Patente no encontrada." << endl;
    }
}

// Modificar vehículo
void ManagerVehiculo::actualizar() {
    char patente[8];
    cout << "Ingrese patente a modificar: ";
    cin >> patente;

    int pos = _repo.buscarPorPatente(patente);
    if (pos >= 0) {
        Vehiculo r = _repo.leer(pos);
        cout << "Datos actuales:\n";
        r.mostrar();
        cout << "Ingrese nuevos datos:\n";
        r.cargar();

        if (_repo.sobreescribir(r, pos)) cout << "Vehículo modificado correctamente." << endl;
        else cout << "Error al modificar." << endl;
    }
    else {
        cout << "Patente no encontrada." << endl;
    }
}

// Baja lógica (marcar como retirado)
void ManagerVehiculo::eliminar() {
    char patente[8];
    cout << "Ingrese patente a dar de baja: ";
    cin >> patente;

    int pos = _repo.buscarPorPatente(patente);
    if (pos >= 0) {
        Vehiculo r = _repo.leer(pos);
        r.setEstado("Retirado");
        _repo.sobreescribir(r, pos);
        cout << "Vehículo marcado como retirado." << endl;
    }
    else {
        cout << "Patente no encontrada." << endl;
    }
}
