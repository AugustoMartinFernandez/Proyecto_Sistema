#include <iostream>
#include <string>
#include "EntradaSinReservaManager.h"
#include "utils.h"
#include "utilsVehiculo.h"

using namespace std;

void EntradaSinReservaManager::procesarEntrada()
{
    cout << "=== ENTRADA SIN RESERVA ===" << endl;

    ///Buscar vehículo por patente
    Vehiculo vehiculo = validaVehiculoBasico(_vehiculoManager, _vehiculoArchivo);

    if (vehiculo.getPatente().empty()){
        cout << "Operación cancelada o error al validar vehículo." << endl;
        return; // cortar el flujo
    }

    ///Fijarse que no tenga reservas
    FechaHora ahora = FechaHora::ahora();
    Reserva rActiva;
    bool tieneReserva = _reservaArchivo.existeReservaActivaParaPatente(vehiculo.getPatente(), ahora, &rActiva);

    if(tieneReserva){
        cout << "Hay una RESERVA ACTIVA para esta patente." << endl;
        cout << "Ventana: " << rActiva.getDesde().toString() << " -> "<< rActiva.getHasta().toString() << endl;
        cout << "Operación cancelada. Ingrese a la opción correspondiente" << endl;
        return;
    }


    ///Buscar plaza libre compatible
    Plaza plaza = _plazaArchivo.buscarPlazaLibre(vehiculo.getTipoVehiculo());
    if (plaza.getIdPlaza() == -1)
    {
        cout << "No hay plazas disponibles para este tipo de vehículo." << endl;
        return;
    }

    cout << "Plaza sugerida: ";
    plaza.mostrar();
    cout << "¿Confirmar asignación de plaza? (S/N): ";
    char confirmar;
    cin >> confirmar;
    if (!(confirmar == 's' || confirmar == 'S'))
    {
        cout << "Operación cancelada." << endl;
        return;
    }
/*
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

    if (!_ticketManager.guardar(ticket))
    {
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
)
{
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
