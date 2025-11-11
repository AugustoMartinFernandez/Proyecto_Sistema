#include "ReporteRecaudacionManager.h"
#include "utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool ReporteRecaudacionManager::esMismoDia(const FechaHora& f1, const FechaHora& f2) const {
    return f1.getDia() == f2.getDia() && f1.getMes() == f2.getMes() && f1.getAnio() == f2.getAnio();
}
bool ReporteRecaudacionManager::esMismoMes(const FechaHora& f1, const FechaHora& f2) const {
    return f1.getMes() == f2.getMes() && f1.getAnio() == f2.getAnio();
}
bool ReporteRecaudacionManager::esMismoAnio(const FechaHora& f1, const FechaHora& f2) const {
    return f1.getAnio() == f2.getAnio();
}

FechaHora preguntarFecha() {
    cout << "=== ¿QUE FECHA QUERES PARA EL REPORTE? ===" << endl;
    cout << "1. Fecha Actual" << endl;
    cout << "2. Ingresar fecha manual" << endl;
    cout << "Opcion: ";
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 2) {
        cout << "[!] Opcion incorrecta. Vuelva a ingresar." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch (opcion) {
        case 1:{return FechaHora::ahora();}
        case 2:{
            FechaHora fechaHora = cargarFechaHora(true); //solo fecha
            return fechaHora;
        }
    }
}

void ReporteRecaudacionManager::recaudacionDiaria() {
    FechaHora hoy = preguntarFecha();

    float total = 0.0f;
    int cantidadTickets = 0;

    int cantPagos = _pagoArchivo.getCantidadRegistros();
    for (int i = 0; i < cantPagos; i++) {
        Pago p = _pagoArchivo.leer(i);
        if (p.getEstadoPago() && esMismoDia(p.getFechaHora(), hoy)) {
            total += p.getImporte();
            cantidadTickets++;
        }
    }

    cout << "=== RECAUDACIÓN DIARIA ===" << endl;
    cout << "Fecha: " << hoy.toString() << endl;
    cout << "Tickets cerrados: " << cantidadTickets << endl;
    cout << "Total cobrado: $" << fixed << setprecision(2) << total << endl; //fixed y setprecision para dejar solo 2 numeros dsps de la coma
    cout << "--------------------------" << endl;
}

void ReporteRecaudacionManager::recaudacionMensual() {
    FechaHora hoy = preguntarFecha();
    float total = 0.0f;
    int cantidadTickets = 0;

    int cantPagos = _pagoArchivo.getCantidadRegistros();
    for (int i = 0; i < cantPagos; i++) {
        Pago p = _pagoArchivo.leer(i);
        if (p.getEstadoPago() && esMismoMes(p.getFechaHora(), hoy)) {
            total += p.getImporte();
            cantidadTickets++;
        }
    }

    cout << "=== RECAUDACIÓN MENSUAL ===" << endl;
    cout << "Mes/Año: " << hoy.getMes() << "/" << hoy.getAnio() << endl;
    cout << "Tickets cerrados: " << cantidadTickets << endl;
    cout << "Total cobrado: $" << fixed << setprecision(2) << total << endl;
    cout << "---------------------------" << endl;
}

void ReporteRecaudacionManager::recaudacionAnual() {
    FechaHora hoy = preguntarFecha();
    float total = 0.0f;
    int cantidadTickets = 0;

    int cantPagos = _pagoArchivo.getCantidadRegistros();
    for (int i = 0; i < cantPagos; i++) {
        Pago p = _pagoArchivo.leer(i);
        if (p.getEstadoPago() && esMismoAnio(p.getFechaHora(), hoy)) {
            total += p.getImporte();
            cantidadTickets++;
        }
    }

    cout << "=== RECAUDACIÓN ANUAL ===" << endl;
    cout << "Año: " << hoy.getAnio() << endl;
    cout << "Tickets cerrados: " << cantidadTickets << endl;
    cout << "Total cobrado: $" << fixed << setprecision(2) << total << endl;
    cout << "--------------------------" << endl;
}

void ReporteRecaudacionManager::recaudacionPorTipoVehiculo() {
    float totalAuto = 0.0f, totalMoto = 0.0f, totalCamioneta = 0.0f;
    int cantAuto = 0, cantMoto = 0, cantCamioneta = 0;

    int cantPagos = _pagoArchivo.getCantidadRegistros();
    for (int i = 0; i < cantPagos; i++) {
        Pago p = _pagoArchivo.leer(i);
        if (!p.getEstadoPago()) continue;

        int posTicket = _ticketArchivo.buscarPorID(p.getIdTicket());
        Ticket t = _ticketArchivo.leer(posTicket);

        Vehiculo v = _vehiculoManager.buscarPorPatente(t.getPatente());

        char tipo = v.getTipoVehiculo();
        if (tipo == 'A') {
            totalAuto += p.getImporte();
            cantAuto++;
        }
        else if (tipo == 'M') {
            totalMoto += p.getImporte();
            cantMoto++;
        }
        else if (tipo == 'C') {
            totalCamioneta += p.getImporte();
            cantCamioneta++;
        }
    }

    cout << "=== RECAUDACIÓN POR TIPO DE VEHÍCULO ===" << endl;
    cout << "Autos: " << cantAuto << " tickets  - $" << fixed << setprecision(2) << totalAuto << endl;
    cout << "Motos: " << cantMoto << " tickets  - $" << fixed << setprecision(2) << totalMoto << endl;
    cout << "Camionetas: " << cantCamioneta << " tickets  - $" << fixed << setprecision(2) << totalCamioneta << endl;
    cout << "----------------------------------------" << endl;
    cout << "Total general: $" << (totalAuto + totalMoto + totalCamioneta) << endl;
}
