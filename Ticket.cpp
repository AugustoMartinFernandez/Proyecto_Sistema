#include "Ticket.h"

Ticket::Ticket() :_idTicket(0), _idReserva(0), _idPlaza(0), _idTarifa(0), _importe(0.0f), _estado(false) {
	_patente[0] = '\0'; // Inicializar cadena vacía y terminador garantizado
	// strcpy(_patente, "AA111BB");
}
int Ticket::getIdTicket() const {return _idTicket;}
int Ticket::getIdReserva() const {return _idReserva;}
int Ticket::getIdPlaza() const {return _idPlaza;}
const char* Ticket::getPatente() const {return _patente;}
int Ticket::getIdTarifa() const {return _idTarifa;}
float Ticket::getImporte() const {return _importe;}
bool Ticket::getEstado() const {return _estado;}
float Ticket::calcularImporte() const {
	// Implementacion pendiente
	return 0.0f;
}

void Ticket::setIdTicket(int idTicket) {
	_idTicket = idTicket;
}
void Ticket::setIdReserva(int idReserva) {
	_idReserva = idReserva;
}
void Ticket::setIdPlaza(int idPlaza) {
	_idPlaza = idPlaza;
}
void Ticket::setIdTarifa(int idTarifa) {
	_idTarifa = idTarifa;
}
void Ticket::setEstado(bool estado) {
	_estado = estado;
}
// void abrir(const Hora& ingreso);
// void cerrar(const Hora& salida);