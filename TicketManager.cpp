#include "TicketManager.h"
#include "Ticket.h"
#include "Plaza.h"
#include "Vehiculo.h"
#include "Tarifa.h"
#include "utils.h"
#include "utilsVehiculo.h"
#include "FechaHora.h"
#include <iostream>

using namespace std;

TicketManager::TicketManager(
    const char* rutaTickets,
    const char* rutaPlazas,
    const std::string& rutaVehiculos,
    const std::string& rutaTarifas
)
    : _archivoTickets(rutaTickets),
      _archivoPlazas(std::string(rutaPlazas)),
      _archivoVehiculos(rutaVehiculos),
      _archivoTarifas(rutaTarifas) {}


void TicketManager::registrarIngreso() {
    cout << "--- REGISTRAR INGRESO ---" << endl;

    char patente[10];
    int idPlaza;

    // 1. Validar Vehículo
    Vehiculo veh = validaVehiculoBasico(_vehiculoManager, _archivoVehiculos);

    if (veh.getPatente().empty()){
        cout << "Operación cancelada o error al validar vehículo." << endl;
        return;
    }


    if (veh.getEstado() == "INACTIVO") {
        cout << "[!] Error: El vehiculo '" << patente << "' esta marcado como Retirado." << endl;
        return;
    }

    cout << "Ingrese ID Plaza: ";
    cin >> idPlaza;

    // 2. Validar Plaza
    int posPlaza = idPlaza - 1;
    Plaza plaza = _archivoPlazas.leer(posPlaza);

    if (plaza.getIdPlaza() == -1) {
        cout << "[!] Error: Plaza ID " << idPlaza << " no existe." << endl;
        return;
    }
    if (plaza.getEstado() != 'L') {
        cout << "[!] Error: La Plaza " << idPlaza << " no esta Libre (Estado: " << plaza.getEstado() << ")." << endl;
        return;
    }

    // 3. Pedir Tarifa
    int idTarifa;
    cout << "Ingrese ID Tarifa a aplicar: ";
    cin >> idTarifa;
    int posTarifa = _archivoTarifas.buscarPorId(idTarifa);
    if (posTarifa == -1) {
         cout << "[!] Error: Tarifa ID " << idTarifa << " no existe." << endl;
        return;
    }

    // 4. Crear Ticket
    Ticket ticket;
    int proximoID = _archivoTickets.getCantidadRegistros() + 1;
    ticket.setIdTicket(proximoID);
    ticket.setPatente(patente);
    ticket.setIdPlaza(idPlaza);
    ticket.setIdTarifa(idTarifa);
    ticket.setEstado("ABIERTO");
    ticket.setIngreso(FechaHora::ahora());

    cout << "Ingreso registrado a las: " << ticket.getIngreso().toString() << endl;

    // 5. Guardar Ticket
    if (!_archivoTickets.guardar(ticket)) {
        cout << "[!] Error: No se pudo guardar el ticket." << endl;
        return;
    }

    // 6. Actualizar Estado de la Plaza
    plaza.setEstado('O');
    if (!_archivoPlazas.sobreescribir(plaza, posPlaza)) {
        cout << "[!] Error CRITICO: No se pudo actualizar el estado de la plaza." << endl;
    }

    cout << "[+] Ingreso registrado. Ticket ID: " << proximoID << endl;
}


void TicketManager::registrarSalida() {
    cout << "--- REGISTRAR SALIDA (CERRAR TICKET) ---" << endl;

    int idTicket;
    cout << "Ingrese ID del Ticket a cerrar: ";
    cin >> idTicket;

    // 1. Buscar Ticket
    int posTicket = _archivoTickets.buscarPorID(idTicket);
    if (posTicket == -1) {
        cout << "[!] Error: Ticket ID " << idTicket << " no encontrado." << endl;
        return;
    }

    Ticket ticket = _archivoTickets.leer(posTicket);
    if (ticket.getEstado(), "CERRADO" == 0) {
        cout << "[!] Error: Ese ticket ya fue cerrado anteriormente." << endl;
        return;
    }

    // 2. Obtener datos de Salida (AUTOMÁTICO)
    cout << "Ticket encontrado. Patente: " << ticket.getPatente() << endl;
    FechaHora fSalida = FechaHora::ahora();
    cout << "Salida registrada a las: " << fSalida.toString() << endl;

    // 3. Buscar Tarifa
    int posTarifa = _archivoTarifas.buscarPorId(ticket.getIdTarifa());
    if (posTarifa == -1) {
        cout << "[!] Error: La Tarifa (ID " << ticket.getIdTarifa() << ") asociada al ticket no existe." << endl;
        return;
    }
    Tarifa tarifa = _archivoTarifas.leer(posTarifa);

    // 4. Calcular Importe
    float importe = tarifa.calcularImporte(ticket.getIngreso(), fSalida);

    cout << "-------------------------" << endl;
    cout << "IMPORTE A COBRAR: $" << importe << endl;
    cout << "-------------------------" << endl;

    // 5. Actualizar Ticket
    ticket.setSalida(fSalida);
    ticket.setImporte(importe);
    ticket.setEstado("CERRADO");

    if (!_archivoTickets.sobreescribir(ticket, posTicket)) {
        cout << "[!] Error: No se pudo actualizar el ticket." << endl;
        return;
    }

    // 6. Actualizar Estado de la Plaza
    int posPlaza = ticket.getIdPlaza() - 1;
    Plaza plaza = _archivoPlazas.leer(posPlaza);

    if (plaza.getIdPlaza() != -1) {
        plaza.setEstado('L'); // 'L' de Libre
        _archivoPlazas.sobreescribir(plaza, posPlaza);
    }

    cout << "[+] Salida registrada. Ticket ID: " << idTicket << " cerrado." << endl;
}


void TicketManager::listarTicketsAbiertos() {
    cout << "--- TICKETS ABIERTOS (ESTACIONADOS) ---" << endl;
    int cant = _archivoTickets.getCantidadRegistros();
    bool encontrados = false;

    for (int i = 0; i < cant; i++) {
        Ticket t = _archivoTickets.leer(i);
        if (t.getEstado() == "ABIERTO") {
            t.mostrar();
            cout << "-------------------------" << endl;
            encontrados = true;
        }
    }
    if (!encontrados) {
        cout << "No hay tickets abiertos." << endl;
    }
}

void TicketManager::listarHistorialTickets() {
    cout << "--- HISTORIAL DE TICKETS (CERRADOS) ---" << endl;
    int cant = _archivoTickets.getCantidadRegistros();
    bool encontrados = false;

    for (int i = 0; i < cant; i++) {
        Ticket t = _archivoTickets.leer(i);
        if (t.getEstado() == "CERRADO") {
            t.mostrar();
            cout << "-------------------------" << endl;
            encontrados = true;
        }
    }
    if (!encontrados) {
        cout << "No hay tickets cerrados." << endl;
    }
}
