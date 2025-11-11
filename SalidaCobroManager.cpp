#include <iostream>
#include "SalidaCobroManager.h"
#include "utils.h"

using namespace std;

void SalidaCobroManager::procesarSalida() {
    cout << "=== SALIDA Y COBRO ===" << endl;

    //Buscar ticket abierto por patente
    cout << "Ingrese patente del vehículo: ";
    string patente = cargarCadena();

    Ticket ticketExistente;
    bool existeTicket = _ticketArchivo.existeTicketAbiertoPorPatente(patente, &ticketExistente);
    if (!existeTicket) {
        cout << "No existe un ticket ABIERTO para esta patente." << endl;
        return;
    }

    //Ticket ticket = _ticketArchivo.leer(posTicket);
    Vehiculo vehiculo = _vehiculoManager.buscarPorPatente(patente);

    cout << "Vehículo encontrado: " << vehiculo.getPatente()
         << " (" << vehiculo.getTipoVehiculo() << ")" << endl;

    //Registrar hora de salida
    FechaHora horaSalida = FechaHora::ahora();
    ticketExistente.setSalida(horaSalida);

    //Buscar tarifa correspondiente al tipo de vehículo
    Tarifa tarifa = _tarifaArchivo.buscarTarifaVigente(vehiculo.getTipoVehiculo(), horaSalida);
    if (tarifa.getIdTarifa() == -1) {
        cout << "No se encontró una tarifa para este tipo de vehículo." << endl;
        return;
    }

    //Calcular importe con el método de Tarifa
    float importe = tarifa.calcularImporte(ticketExistente.getIngreso(), ticketExistente.getSalida());


    cout << "Importe a pagar: $" << importe << endl;

    cout << "¿Confirmar cobro? (S/N): ";
    char confirmar;
    cin >> confirmar;
    cin.ignore();

    if (confirmar != 's' && confirmar != 'S') {
        cout << "Operación cancelada." << endl;
        return;
    }

    //Registrar pago
    FechaHora ahora = FechaHora::ahora();
    Pago pago(
        _pagoArchivo.getNuevoID(),
        ticketExistente.getIdTicket(),
        importe,
        ahora,       // fecha y hora del pago
        "EFECTIVO",  // medio de pago por ahora fijo
        true         // estadoPago
    );

    if (_pagoArchivo.guardar(pago)) {
        cout << "Pago registrado correctamente." << endl;
    } else {
        cout << "Error al registrar el pago." << endl;
    }

    //Cerrar ticket
    ticketExistente.setEstado("CERRADO");
    _ticketArchivo.sobreescribir(ticketExistente, _ticketArchivo.buscarPorID(ticketExistente.getIdTicket()));

    //Liberar plaza
    Plaza plaza = _plazaArchivo.leer(ticketExistente.getIdPlaza() -1);
    plaza.setEstado('L');
    _plazaArchivo.sobreescribir(plaza, plaza.getIdPlaza() -1);

    cout << "Ticket cerrado y plaza liberada correctamente." << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Salida registrada con éxito." << endl;
}

