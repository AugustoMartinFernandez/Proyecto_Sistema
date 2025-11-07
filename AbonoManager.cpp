#include "AbonoManager.h"
#include <iostream>
#include <cstring>

using namespace std;

AbonoManager::AbonoManager(const char* rutaAbonos) : _archivoAbonos(rutaAbonos) {}

void AbonoManager::altaAbono() {
    Abono reg; // Objeto local para cargar datos
    
    cout << "--- ALTA NUEVO ABONO ---" << endl;

    // 1. Pedir datos (Lógica del Manager)
    char idCliente[9], plan[21];
    float precio;
    int idTarifa;
    Hora hDesde, hHasta;

    cout << "ID de Cliente (DNI/ID): ";
    cin >> idCliente;
    // AQUÍ DEBERÍA IR UNA VALIDACIÓN: Buscar si el cliente existe.
    
    cout << "Plan (ej: Parcial, Completo): ";
    cin >> plan;
    cout << "Precio Mensual: $";
    cin >> precio;
    cout << "ID Tarifa asociada: ";
    cin >> idTarifa;
    // AQUÍ DEBERÍA IR UNA VALIDACIÓN: Buscar si la Tarifa existe.

    cout << "Hora de inicio (HH MM): ";
    cin >> hDesde.hora >> hDesde.minutos;
    cout << "Hora de fin (HH MM): ";
    cin >> hHasta.hora >> hHasta.minutos;

    // 2. Setear datos en el objeto
    reg.setIdCliente(idCliente);
    reg.setPlan(plan);
    reg.setPrecioMensual(precio);
    reg.setIdTarifa(idTarifa);
    reg.setDesdeHora(hDesde);
    reg.setHastaHora(hHasta);
    
    // 3. Lógica de Manager (Asignación de ID y Estado inicial)
    int proximoID = _archivoAbonos.contarRegistros() + 1;
    reg.setIdAbono(proximoID);
    reg.setEstado('A'); // Estado inicial: Activo

    // 4. Grabar en Archivo
    if (_archivoAbonos.grabarRegistro(reg)) {
        cout << "[+] Abono ID " << proximoID << " guardado correctamente." << endl;
    } else {
        cout << "[!] Error al guardar el abono en el archivo." << endl;
    }
}

void AbonoManager::listarAbonos() {
    cout << "--- LISTADO DE ABONOS ---" << endl;
    int cantidad = _archivoAbonos.contarRegistros();
    
    if (cantidad == 0) {
        cout << "No hay abonos registrados." << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Abono reg = _archivoAbonos.leerRegistro(i);
        
        // Verificamos que no sea un registro de error y que no esté dado de baja
        if (reg.getIdAbono() != -1 && reg.getEstado() != 'B') { 
            reg.mostrar();
            cout << "------------------------" << endl;
        }
    }
}

// (Stubs: Métodos vacíos para que el Menú compile)
void AbonoManager::modificarAbono() {
    cout << "Funcion MODIFICAR ABONO no implementada." << endl;
}

void AbonoManager::bajaAbono() {
    cout << "Funcion BAJA ABONO no implementada." << endl;
}
