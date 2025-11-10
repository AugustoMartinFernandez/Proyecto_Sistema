#include "FechaHora.h"
#include <ctime>
#include <string>

using namespace std;

// Constructores
FechaHora::FechaHora()
: _anio(1970), _mes(1), _dia(1), _hora(0), _minuto(0) {}

FechaHora::FechaHora(int anio, int mes, int dia, int hora, int minuto)
: _anio(anio), _mes(mes), _dia(dia), _hora(hora), _minuto(minuto) {}

// Getters
int FechaHora::getAnio() const { return _anio; }
int FechaHora::getMes() const { return _mes; }
int FechaHora::getDia() const { return _dia; }
int FechaHora::getHora() const { return _hora; }
int FechaHora::getMinuto() const { return _minuto; }

// Setters
void FechaHora::setAnio(int anio) { _anio = anio; }
void FechaHora::setMes(int mes) { _mes = mes; }
void FechaHora::setDia(int dia) { _dia = dia; }
void FechaHora::setHora(int hora) { _hora = hora; }
void FechaHora::setMinuto(int minuto) { _minuto = minuto; }

string FechaHora::toString() const {
    string h = (_hora < 10 ? "0" : "") + to_string(_hora);
    string m = (_minuto < 10 ? "0" : "") + to_string(_minuto);
    return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio) + " " + h + ":" + m;
}

// Obtiene la fecha y hora actual del sistema
FechaHora FechaHora::ahora() {
    time_t t = time(nullptr);
    tm* tiempo = localtime(&t);

    int anio = tiempo->tm_year + 1900;
    int mes = tiempo->tm_mon + 1;
    int dia = tiempo->tm_mday;
    int hora = tiempo->tm_hour;
    int minuto = tiempo->tm_min;

    return FechaHora(anio, mes, dia, hora, minuto);
}
