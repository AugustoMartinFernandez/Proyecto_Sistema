#include "Ticket.h"
#include <iostream>
#include <cstring>
#include "utils.h" // Para cargarHora() y cargarCadena() (aunque 'cargar' aquí no es interactivo)

using namespace std;

Ticket::Ticket(int id) {
    _idTicket = id;
    _idReserva = 0;
    _idPlaza = 0;
    setPatente("");
    _idTarifa = 0;
    // _ingresoFecha y _ingresoHora se setean en el Manager
    _importe = 0.0f;
    setEstado("Abierto");
}

// --- Getters ---
int Ticket::getIdTicket() const { return _idTicket; }
int Ticket::getIdReserva() const { return _idReserva; }
int Ticket::getIdPlaza() const { return _idPlaza; }
const char* Ticket::getPatente() const { return _patente; }
int Ticket::getIdTarifa() const { return _idTarifa; }
Fecha Ticket::getIngresoFecha() const { return _ingresoFecha; }
Hora Ticket::getIngresoHora() const { return _ingresoHora; }
Fecha Ticket::getSalidaFecha() const { return _salidaFecha; }
Hora Ticket::getSalidaHora() const { return _salidaHora; }
float Ticket::getImporte() const { return _importe; }
const char* Ticket::getEstado() const { return _estado; }

// --- Setters ---
void Ticket::setIdTicket(int id) { _idTicket = id; }
void Ticket::setIdReserva(int id) { _idReserva = id; }
void Ticket::setIdPlaza(int id) { _idPlaza = id; }
void Ticket::setPatente(const char* patente) {
    strncpy(_patente, patente, 7);
    _patente[7] = '\0';
}
void Ticket::setIdTarifa(int id) { _idTarifa = id; }
void Ticket::setIngresoFecha(Fecha f) { _ingresoFecha = f; }
void Ticket::setIngresoHora(Hora h) { _ingresoHora = h; }
void Ticket::setSalidaFecha(Fecha f) { _salidaFecha = f; }
void Ticket::setSalidaHora(Hora h) { _salidaHora = h; }
void Ticket::setImporte(float importe) { _importe = importe; }
void Ticket::setEstado(const char* estado) {
    strncpy(_estado, estado, 19);
    _estado[19] = '\0';
}

// --- Métodos ---

// 'cargar' lo usamos para que el Manager pida los datos
void Ticket::cargar(int id) {
    _idTicket = id;
    
    cout << "ID Plaza: ";
    cin >> _idPlaza;
    cout << "Patente: ";
    char p[10];
    cin >> p;
    setPatente(p);
    cout << "ID Tarifa: ";
    cin >> _idTarifa;

    // Asumimos que la fecha y hora de ingreso son las actuales
    // (debemos tener una función para esto, si no, se pide)
    cout << "Fecha Ingreso (dd mm aaaa): ";
    int d, m, a;
    cin >> d >> m >> a;
    _ingresoFecha.setDia(d);
    _ingresoFecha.setMes(m);
    _ingresoFecha.setAnio(a);
    
    cout << "Hora Ingreso:" << endl;
    _ingresoHora = cargarHora();
    
    setEstado("Abierto");
    _importe = 0;
}

void Ticket::mostrar() const {
    cout << "--- TICKET #" << _idTicket << " ---" << endl;
    cout << "Estado: " << _estado << endl;
    cout << "Plaza: " << _idPlaza << " | Patente: " << _patente << endl;
    cout << "Tarifa ID: " << _idTarifa << " | Reserva ID: " << _idReserva << endl;
    cout << "Ingreso: " << _ingresoFecha.toString() << " " << _ingresoHora.toString() << endl;
    
    if (strcmp(_estado, "Cerrado") == 0) {
        cout << "Salida: " << _salidaFecha.toString() << " " << _salidaHora.toString() << endl;
        cout << "IMPORTE: $" << _importe << endl;
    }
}
