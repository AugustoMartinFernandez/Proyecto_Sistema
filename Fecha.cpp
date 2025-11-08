#include "Fecha.h"
#include <string>
using namespace std;

Fecha::Fecha() :_dia(0), _mes(0), _anio(0){
}
Fecha::Fecha(int dia, int mes, int anio) {
	setDia(dia);
	setMes(mes);
	setAnio(anio);
}
int Fecha::getDia() {
	return _dia;
}
int Fecha::getMes() {
	return _mes;
}
int Fecha::getAnio() {
	return _anio;
}

void Fecha::setDia(int dia){
	_dia = dia;
}
void Fecha::setMes(int mes){ 
	_mes = mes;
}
void Fecha::setAnio(int anio){
	_anio = anio;
}

string Fecha::toString() const { 
	return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}
