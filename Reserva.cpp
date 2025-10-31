#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include "Reserva.h"

Reserva::Reserva():_idReserva(0), _idPlaza(0) {
	_patente[0] = '\0';
	_estado[0] = '\0';
}

int Reserva::getIdReserva() const { return _idReserva; }
int Reserva::getIdPlaza() const { return _idPlaza; }
const char* Reserva::getPatente()const{ return _patente; }
const char* Reserva::getEstado()const{ return _estado; }
//Hora getDesdeHora() const;
//Hora getHastaHora() const;

void Reserva::setIdReserva(int idReserva) {
		_idReserva = idReserva;
}
void Reserva::setIdPlaza(int idPlaza){
		_idPlaza = idPlaza;
}
void Reserva::setPatente(const char* patente) {

}
//void setDesdeHora(const Hora& desdeHora);
//void setHastaHora(const Hora& hastaHora);

void Reserva::setEstado(const char* estado) {
	if (estado == nullptr) {
		_estado[0] = '\0';
		return;
	}
	strcpy(_estado, estado);
}

