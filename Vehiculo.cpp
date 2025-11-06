#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include "Vehiculo.h"
using namespace std;

Vehiculo::Vehiculo() {
	strcpy(_patente,"AA111BB");
	strcpy(_dniCliente,"00000000");
	strcpy(_tipoVehiculo,"SinTipo");
	strcpy(_estado,"Default");
}

void Vehiculo::setPatente(const char* patente) {
	if (esPatenteValida(patente)) {
		strncpy(_patente, patente, 7);
		_patente[7] = '\0';
	}
	else {
		strncpy(_patente, "AA111BB", 7);
		_patente[7] = '\0';
	}
}

void Vehiculo::setDniCliente(const char* dniCliente) {
	if (strlen(dniCliente) == 8) {
		bool esValido = true;
		for (int i = 0; i < 8; i++) {
			if (!isdigit(dniCliente[i])) {
				esValido = false;
				break;
			}
		}
		if (esValido) {
			strncpy(_dniCliente, dniCliente, 8);
			_dniCliente[8] = '\0';
		} else{
			strncpy(_dniCliente, "00000000", 8);
			_dniCliente[8] = '\0';
		}
	}
	else {
		strncpy(_dniCliente, "00000000", 8);
		_dniCliente[8] = '\0';
	}
}
void Vehiculo::setTipoVehiculo(const char* tipoVehiculo) {
	if (strlen(tipoVehiculo)<20) {
		strncpy(_tipoVehiculo, tipoVehiculo, 19);
		_tipoVehiculo[19] = '\0';
	}
	else {
		strncpy(_tipoVehiculo, "SinTipo", 19);
		_tipoVehiculo[19] = '\0';
	}
}

void Vehiculo::setEstado(const char* estado) {
	if (estadoValido(estado)) {
		strncpy(_estado, estado, 19);
		_estado[19] = '\0';
	}
	else {
		strncpy(_estado, "Default", 19);
		_estado[19] = '\0';
	}
}

void Vehiculo::cargar() {
	char patente[10];
	char dni[10];
	char tipo[20];
	char estado[20];
	cout << "==============================" << endl;
	cout << "       CARGA DE VEHICULO      " << endl;
	cout << "==============================" << endl;
	cout << "Patente (formato AA111BB): ";
	cin >> patente;
	setPatente(patente);
	cout << "DNI del cliente (8 digitos): ";
	cin >> dni;
	setDniCliente(dni);
	cin.ignore(); // limpiar buffer antes de getline
	cout << "Tipo de vehiculo (ej: Auto, Moto, Camioneta): ";
	cin.getline(tipo, 20);
	setTipoVehiculo(tipo);
	cout << "Estado (Estacionado / Retirado / Reservado / En Espera): ";
	cin.getline(estado, 20);
	setEstado(estado);
	cout << "==============================" << endl;
}
void Vehiculo::mostrar() {
	cout << "==============================" << endl;
	cout << "       DATOS DEL VEHICULO     " << endl;
	cout << "==============================" << endl;
	cout << "Patente     : " << _patente << endl;
	cout << "DNI Cliente : " << _dniCliente << endl;
	cout << "Tipo        : " << _tipoVehiculo << endl;
	cout << "Estado      : " << _estado << endl;
}

bool Vehiculo::esPatenteValida(const char* patenteVal) {
	//Verificamos que la patente tenga exactamente 7 caracteres
	return strlen(patenteVal) == 7 &&
		// Verificamos que los dos primeros caracteres sean letras
		isalpha(patenteVal[0]) && isalpha(patenteVal[1]) &&
		// Los tres siguientes caracteres sean siguientes seas numeros del 0 al 9
		isdigit(patenteVal[2]) && isdigit(patenteVal[3]) && isdigit(patenteVal[4]) &&
		// Dos ultimos caracteres sean letras
		isalpha(patenteVal[5]) && isalpha(patenteVal[6]);
}
bool Vehiculo::estadoValido(const char* estado) {
	return strcmp(estado, "Estacionado") == 0 || strcmp(estado, "Retirado") == 0 || strcmp(estado, "Reservado") == 0 || strcmp(estado, "En Espera") == 0;
}

const char* Vehiculo::getPatente()const {
	return _patente;
}
const char* Vehiculo::getDniCliente()const {
	return _dniCliente;
}
const char* Vehiculo::getTipoVehiculo()const {
	return _tipoVehiculo;
}
const char* Vehiculo::getEstado()const {
	return _estado;
}