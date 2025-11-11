#include "AbonoManager.h"
#include <iostream>
#include <cstring>
#include "Hora.h"
#include "utils.h"

using namespace std;

AbonoManager::AbonoManager(const char* rutaAbonos) : _archivoAbonos(std::string(rutaAbonos)) {}

void AbonoManager::altaAbono() {
    Abono reg;

    cout << "--- ALTA NUEVO ABONO ---" << endl;

    char idCliente[9], plan[21];
    float precio;
    int idTarifa;

    cout << "ID de Cliente (DNI/ID): ";
    cin >> idCliente;
    // (VALIDACIÓN PENDIENTE)

    cout << "Plan (ej: Parcial, Completo): ";
    cin >> plan;
    cout << "Precio Mensual: $";
    cin >> precio;
    cout << "ID Tarifa asociada: ";
    cin >> idTarifa;
    // (VALIDACIÓN PENDIENTE)

    cout << "Hora de inicio --" << endl;
    FechaHora hDesde = cargarFechaHora();

    cout << "Hora de fin --" << endl;
    FechaHora hHasta = cargarFechaHora();

    reg.setIdCliente(idCliente);
    reg.setPlan(plan);
    reg.setPrecioMensual(precio);
    reg.setIdTarifa(idTarifa);
    reg.setDesde(hDesde);
    reg.setHasta(hHasta);

    int proximoID = _archivoAbonos.getCantidadRegistros() + 1;
    reg.setIdAbono(proximoID);
    reg.setEstado('A');

    if (_archivoAbonos.guardar(reg)) {
        cout << "[+] Abono ID " << proximoID << " guardado correctamente." << endl;
    } else {
        cout << "[!] Error al guardar el abono en el archivo." << endl;
    }
}

void AbonoManager::listarAbonos() {
    cout << "--- LISTADO DE ABONOS ---" << endl;

    int cantidad = _archivoAbonos.getCantidadRegistros();

    if (cantidad == 0) {
        cout << "No hay abonos registrados." << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Abono reg = _archivoAbonos.leer(i);

        if (reg.getIdAbono() != -1 && reg.getEstado() != 'B') {
            reg.mostrar();
            cout << "------------------------" << endl;
        }
    }
}

void AbonoManager::modificarAbono() {
    cout << "Funcion MODIFICAR ABONO no implementada." << endl;
}

void AbonoManager::bajaAbono() {
    cout << "Funcion BAJA ABONO no implementada." << endl;
}
