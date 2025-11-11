#include "Ticket.h"
#include <iostream>
#include <cstring>
#include "utils.h" // (Aunque ya no lo usamos aquí)

using namespace std;

Ticket::Ticket()
: _idTicket(0), _idReserva(0), _idPlaza(0),
  _idTarifa(0), _importe(0.0f) {
    setPatente("");
    setEstado("ABIERTO");
}

Ticket::Ticket(int idTicket, int idReserva, int idPlaza,
               const string& patente, int idTarifa,
               const FechaHora& ingreso, const FechaHora& salida,
               float importe, const string& estado)
{
    setIdTicket(idTicket);
    setIdReserva(idReserva);
    setIdPlaza(idPlaza);
    setIdTarifa(idTarifa);
    setIngreso(ingreso);
    setSalida(salida);
    setImporte(importe);
    setPatente(patente);
    setEstado(estado);
}


// --- Getters ---
int Ticket::getIdTicket() const { return _idTicket; }
int Ticket::getIdReserva() const { return _idReserva; }
int Ticket::getIdPlaza() const { return _idPlaza; }
string Ticket::getPatente() const { return _patente; }
int Ticket::getIdTarifa() const { return _idTarifa; }
FechaHora Ticket::getIngreso() const { return _ingreso; }
FechaHora Ticket::getSalida() const { return _salida; }
float Ticket::getImporte() const { return _importe; }
string Ticket::getEstado() const { return _estado; }

// --- Setters ---
void Ticket::setIdTicket(int id) { _idTicket = id; }
void Ticket::setIdReserva(int id) { _idReserva = id; }
void Ticket::setIdPlaza(int id) { _idPlaza = id; }
void Ticket::setPatente(const string &patente) {
    strncpy(_patente, patente.c_str(), 7);
    _patente[7] = '\0';
}
void Ticket::setIdTarifa(int id) { _idTarifa = id; }
void Ticket::setIngreso(FechaHora fh) { _ingreso = fh; }
void Ticket::setSalida(FechaHora fh) { _salida = fh; }
void Ticket::setImporte(float importe) { _importe = importe; }
void Ticket::setEstado(const string &estado) {
    strncpy(_estado, estado.c_str(), 19);
    _estado[19] = '\0';
}

// --- Métodos ---

// 'cargar()' se elimina. El Manager se encarga de setear los datos.

void Ticket::mostrar() const {
    cout << "--- TICKET #" << _idTicket << " ---" << endl;
    cout << "Estado: " << _estado << endl;
    cout << "Plaza: " << _idPlaza << " | Patente: " << _patente << endl;
    cout << "Tarifa ID: " << _idTarifa << " | Reserva ID: " << _idReserva << endl;

    cout << "Ingreso: " << _ingreso.toString() << endl;

    if (strcmp(_estado, "Cerrado") == 0) {
        cout << "Salida: " << _salida.toString() << endl;
        cout << "IMPORTE: $" << _importe << endl;
    }
}
