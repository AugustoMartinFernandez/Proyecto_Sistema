#include <iostream>
#include <string>
#include "EntradaConReservaManager.h"
#include "utils.h"
#include "utilsVehiculo.h"

using namespace std;

void EntradaConReservaManager::procesarEntrada()
{
    cout << "=== ENTRADA CON RESERVA ===" << endl;

    ///Buscar vehículo por patente
    Vehiculo vehiculo = validaVehiculoBasico(_vehiculoManager, _vehiculoArchivo);

    if (vehiculo.getPatente().empty()) {
        cout << "Operación cancelada o error al validar vehículo." << endl;
        return;
    }

    ///Buscar reserva activa para patente
    FechaHora ahora = FechaHora::ahora();
    Reserva reserva;
    bool tieneReserva = _reservaArchivo.existeReservaActivaParaPatente(vehiculo.getPatente(), ahora, &reserva);

    if (!tieneReserva) {
        cout << "No hay una RESERVA ACTIVA para esta patente en este momento." << endl;
        return;
    }

    cout << "Reserva encontrada: ID #" << reserva.getIdReserva() << endl;
    cout << "Ventana: " << reserva.getDesde().toString() << " -> " << reserva.getHasta().toString() << endl;

    ///Buscar si tiene ticket abierto
    Ticket ticketExistente;
    bool tieneTicketAbierto = _ticketArchivo.existeTicketAbiertoPorPatente(vehiculo.getPatente(), &ticketExistente);

    if (tieneTicketAbierto) {
        cout << "El vehículo ya tiene un TICKET ABIERTO (ID: " << ticketExistente.getIdTicket() << ")." << endl;
        cout << "Operación cancelada." << endl;
        return;
    }

    ///Obtener plaza asociada a la reserva
    Plaza plaza = _plazaArchivo.leer(reserva.getIdPlaza() - 1);
    if (plaza.getIdPlaza() == -1) {
        cout << "Error: la plaza asociada a la reserva no existe." << endl;
        return;
    }

    if (plaza.getEstado() != 'R') {
        cout << "La plaza reservada no está disponible (estado actual: " << plaza.getEstado() << ")." << endl;
        return;
    }

    cout << "Plaza reservada: ";
    plaza.mostrar();

    cout << "¿Confirmar ingreso del vehículo a la plaza reservada? (S/N): ";
    char confirmar;
    cin >> confirmar;
    if (!(confirmar == 's' || confirmar == 'S')) {
        cout << "Operación cancelada." << endl;
        return;
    }

    ///Buscar tarifa vigente
    Tarifa tarifa = _tarifaArchivo.buscarTarifaVigente(vehiculo.getTipoVehiculo(), FechaHora::ahora());
    if (tarifa.getIdTarifa() == -1) {
        cout << "No hay una tarifa vigente para este tipo de vehículo." << endl;
        return;
    }

    ///Crear ticket
    FechaHora ingreso = FechaHora::ahora();

    Ticket ticket(
        _ticketArchivo.getCantidadRegistros() + 1,
        reserva.getIdReserva(), //reserva
        plaza.getIdPlaza(),
        vehiculo.getPatente(),
        tarifa.getIdTarifa(),
        ingreso,
        FechaHora(),                      // salida vacía
        0.0f,
        "ABIERTO"
    );

    if (!_ticketArchivo.guardar(ticket)) {
        cout << "Error al registrar el ticket de entrada." << endl;
        return;
    }

    cout << "Ticket generado exitosamente (ID: " << ticket.getIdTicket() << ")." << endl;

    //Marcar plaza como OCUPADA y reserva como CONFIRMADA
    plaza.setEstado('O');
    _plazaArchivo.sobreescribir(plaza, plaza.getIdPlaza() - 1);

    reserva.setEstado("CONFIRMADA");
    int posReserva = _reservaArchivo.buscarID(reserva.getIdReserva());
    _reservaArchivo.guardar(posReserva, reserva);

    ///Mostrar resumen
    Cliente cliente = _clienteManager.buscarPorDNI(vehiculo.getDniCliente());
    mostrarResumenTicket(ticket, vehiculo, cliente, plaza);
}


void EntradaConReservaManager::mostrarResumenTicket(
    const Ticket& ticket, const Vehiculo& vehiculo,
    const Cliente& cliente, const Plaza& plaza
)
{
    cout << endl;
    cout << "=== TICKET DE ENTRADA (CON RESERVA) ===" << endl;
    cout << "Ticket ID: " << ticket.getIdTicket() << endl;
    cout << "Vehículo: " << vehiculo.getPatente()
         << " (" << vehiculo.getTipoVehiculo() << ")" << endl;
    cout << "Cliente: " << cliente.getApellido() << ", " << cliente.getNombre() << endl;
    cout << "Plaza asignada: #" << plaza.getIdPlaza()
         << " - Piso " << plaza.getPiso() << endl;
    cout << "Hora de ingreso: " << ticket.getIngreso().toString() << endl;
    cout << "Estado: " << ticket.getEstado() << endl;
    cout << "---------------------------------" << endl;
}
