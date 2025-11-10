#include <iostream>
#include <string>
#include "EntradaSinReservaManager.h"
#include "utils.h"

using namespace std;

void EntradaSinReservaManager::procesarEntrada() {
    cout << "=== ENTRADA SIN RESERVA ===" << endl;
    /*

    ///Buscar vehículo por patente
    cout << "Ingrese patente del vehículo: ";
    string patente = cargarCadena();
    int posVehiculo = _vehiculoArchivo.buscarPorPatente(patente);
    Vehiculo vehiculo;

    if (posVehiculo == -1) {
        cout << "Vehículo no encontrado. ¿Desea registrarlo? (S/N): ";
        char opc;
        cin >> opc;
        if (opc == 's' || opc == 'S') {
            //Dentro del manager chequea por DNI
            vehiculo = _vehiculoManager.altaVehiculo(patente);
            if (_vehiculoArchivo.buscarPorPatente(patente) == -1) {
                cout << "Error al registrar el vehículo." << endl;
                return;
            }
        } else {
            cout << "Operación cancelada." << endl;
            return;
        }
    } else {
        vehiculo = _vehiculoArchivo.leer(posVehiculo);
        cout << "Vehículo encontrado (Patente: " << vehiculo.getPatente() << ")" << endl;
    ///TODO PREGUNTAR A LOS CHICOS SI QUIEREN PREGUNTARLE EL DNI AL USUARIO PARA MODIFICARLO
    ///Fijarse que no tenga reservas
    }

    ///Buscar plaza libre compatible
    Plaza plaza = _plazaManager.buscarPlazaLibre(vehiculo.getTipoVehiculo());
    if (plaza.getIdPlaza() == -1) {
        cout << "No hay plazas disponibles para este tipo de vehículo." << endl;
        return;
    }

    cout << "Plaza sugerida: #" << plaza.getIdPlaza()
         << " - Piso " << plaza.getPiso()
         << " - Estado: " << plaza.getEstado() << endl;

    cout << "¿Confirmar asignación de plaza? (S/N): ";
    char confirmar;
    cin >> confirmar;
    if (!(confirmar == 's' || confirmar == 'S')) {
        cout << "Operación cancelada." << endl;
        return;
    }

    // --- 4. Crear ticket de entrada ---
    Hora horaIngreso = cargarHora();
    Ticket ticket(
        _ticketManager.getNuevoID(),
        vehiculo.getIdVehiculo(),
        plaza.getIdPlaza(),
        horaIngreso,
        Hora(), // hora salida vacía
        "ABIERTO"
    );

    if (!_ticketManager.guardar(ticket)) {
        cout << "Error al registrar el ticket de entrada." << endl;
        return;
    }

    // --- 5. Marcar plaza como ocupada ---
    plaza.setEstado("OCUPADA");
    _plazaManager.actualizar(plaza);

    // --- 6. Mostrar resumen ---
    mostrarResumenTicket(ticket, vehiculo, cliente, plaza);
}

void EntradaSinReservaManager::mostrarResumenTicket(
    const Ticket& ticket, const Vehiculo& vehiculo,
    const Cliente& cliente, const Plaza& plaza
) {
    cout << endl;
    cout << "=== TICKET DE ENTRADA GENERADO ===" << endl;
    cout << "Ticket ID: " << ticket.getIdTicket() << endl;
    cout << "Vehículo: " << vehiculo.getPatente()
         << " (" << vehiculo.getTipoVehiculo() << ")" << endl;
    cout << "Cliente: " << cliente.getApellido() << ", " << cliente.getNombre() << endl;
    cout << "Plaza asignada: #" << plaza.getIdPlaza()
         << " - Piso " << plaza.getPiso() << endl;
    cout << "Hora de ingreso: " << ticket.getHoraIngreso().toString() << endl;
    cout << "Estado: " << ticket.getEstado() << endl;
    cout << "---------------------------------" << endl;
    */
}
