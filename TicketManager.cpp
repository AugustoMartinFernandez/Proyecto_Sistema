#include "TicketManager.h"
#include "Ticket.h"
#include "Plaza.h"
#include "Vehiculo.h"
#include "Tarifa.h"
#include "utils.h" // Para cargarHora()
#include <iostream>
#include <cstring>

using namespace std;

TicketManager::TicketManager(const char* rutaTickets, const char* rutaPlazas, const std::string& rutaVehiculos, const std::string& rutaTarifas)
    : _archivoTickets(rutaTickets), 
      _archivoPlazas(rutaPlazas), 
      _archivoVehiculos(rutaVehiculos), 
      _archivoTarifas(rutaTarifas) {}


void TicketManager::registrarIngreso() {
    cout << "--- REGISTRAR INGRESO ---" << endl;
    
    char patente[10];
    int idPlaza;

    cout << "Ingrese Patente: ";
    cin >> patente;

    // 1. Validar Vehículo
    int posVehiculo = _archivoVehiculos.buscarPorPatente(patente);
    if (posVehiculo == -1) {
        cout << "[!] Error: Patente no encontrada. Debe dar de alta el vehiculo primero." << endl;
        return;
    }
    Vehiculo veh = _archivoVehiculos.leer(posVehiculo);
    if (strcmp(veh.getEstado(), "Retirado") == 0) {
        cout << "[!] Error: El vehiculo '" << patente << "' esta marcado como Retirado." << endl;
        return;
    }

    cout << "Ingrese ID Plaza: ";
    cin >> idPlaza;

    // 2. Validar Plaza
    // (Asumimos que idPlaza = 1 es la pos 0, idPlaza = 2 es la pos 1...)
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
    Tarifa tarifa = _archivoTarifas.leer(_archivoTarifas.buscarPorId(idTarifa));
    if (tarifa.getIdTarifa() == -1) {
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
    ticket.setEstado("Abierto");

    // Pedimos Fecha y Hora de Ingreso
    cout << "Fecha Ingreso (dd mm aaaa): ";
    int d, m, a;
    cin >> d >> m >> a;
    ticket.setIngresoFecha(Fecha(d, m, a));
    cout << "Hora Ingreso:" << endl;
    ticket.setIngresoHora(cargarHora());

    // 5. Guardar Ticket
    if (!_archivoTickets.guardar(ticket)) {
        cout << "[!] Error: No se pudo guardar el ticket." << endl;
        return;
    }

    // 6. Actualizar Estado de la Plaza
    plaza.setEstado('O'); // 'O' de Ocupada
    if (!_archivoPlazas.modificarRegistro(plaza, posPlaza)) {
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
    if (strcmp(ticket.getEstado(), "Cerrado") == 0) {
        cout << "[!] Error: Ese ticket ya fue cerrado anteriormente." << endl;
        return;
    }

    // 2. Pedir datos de Salida
    cout << "Ticket encontrado. Patente: " << ticket.getPatente() << endl;
    cout << "Fecha Salida (dd mm aaaa): ";
    int d, m, a;
    cin >> d >> m >> a;
    Fecha fSalida(d, m, a);
    cout << "Hora Salida:" << endl;
    Hora hSalida = cargarHora();

    // 3. Buscar Tarifa
    Tarifa tarifa = _archivoTarifas.leer(_archivoTarifas.buscarPorId(ticket.getIdTarifa()));
    if (tarifa.getIdTarifa() == -1) {
        cout << "[!] Error: La Tarifa (ID " << ticket.getIdTarifa() << ") asociada al ticket no existe." << endl;
        return;
    }

    // 4. Calcular Importe
    // (Esta función la implementamos en Tarifa.cpp)
    float importe = tarifa.calcularImporte(ticket.getIngresoHora(), hSalida); 
    // (NOTA: Este cálculo es simple, no usa la Fecha. La implementación de calcularImporte debemos modificarla)
    
    cout << "-------------------------" << endl;
    cout << "IMPORTE A COBRAR: $" << importe << endl;
    cout << "-------------------------" << endl;

    // 5. Actualizar Ticket
    ticket.setSalidaFecha(fSalida);
    ticket.setSalidaHora(hSalida);
    ticket.setImporte(importe);
    ticket.setEstado("Cerrado");

    if (!_archivoTickets.sobreescribir(ticket, posTicket)) {
        cout << "[!] Error: No se pudo actualizar el ticket." << endl;
        return;
    }

    // 6. Actualizar Estado de la Plaza
    int posPlaza = ticket.getIdPlaza() - 1; // Asumimos ID 1 = pos 0
    Plaza plaza = _archivoPlazas.leer(posPlaza);
    if (plaza.getIdPlaza() != -1) {
        plaza.setEstado('L'); // 'L' de Libre
        _archivoPlazas.modificarRegistro(plaza, posPlaza);
    }

    cout << "[+] Salida registrada. Ticket ID: " << idTicket << " cerrado." << endl;
}


void TicketManager::listarTicketsAbiertos() {
    cout << "--- TICKETS ABIERTOS (ESTACIONADOS) ---" << endl;
    int cant = _archivoTickets.getCantidadRegistros();
    bool encontrados = false;
    
    for (int i = 0; i < cant; i++) {
        Ticket t = _archivoTickets.leer(i);
        if (strcmp(t.getEstado(), "Abierto") == 0) {
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
        if (strcmp(t.getEstado(), "Cerrado") == 0) {
            t.mostrar();
            cout << "-------------------------" << endl;
            encontrados = true;
        }
    }
    if (!encontrados) {
        cout << "No hay tickets cerrados." << endl;
    }
}
