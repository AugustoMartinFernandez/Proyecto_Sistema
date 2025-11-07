#include "Hora.h"
#include <iostream>
#include <string>
using namespace std;

// --- Constructores ---
Hora::Hora() : _hora(0), _minuto(0) {}

Hora::Hora(int hora, int minuto) {
    setHora(hora);
    setMinuto(minuto);
}

// --- Getters ---
int Hora::getHora() {
    return _hora;
}

int Hora::getMinuto() {
    return _minuto;
}

// --- Setters ---
void Hora::setHora(int hora) {
    if (hora >= 0 && hora < 24) _hora = hora;
    else _hora = 0;
}

void Hora::setMinuto(int minuto) {
    if (minuto >= 0 && minuto < 60) _minuto = minuto;
    else _minuto = 0;
}

// --- Devuelve la hora como texto "HH:MM" ---
string Hora::toString() {
    string h = (_hora < 10 ? "0" : "") + to_string(_hora);
    string m = (_minuto < 10 ? "0" : "") + to_string(_minuto);
    return h + ":" + m;
}

// --- Convierte a minutos totales desde 00:00 ---
int Hora::aMinutos() {
    return _hora * 60 + _minuto;
}

// --- Diferencia en minutos entre dos horas ---
int Hora::diferenciaMinutos(const Hora& h) {
    return this->aMinutos() - h._hora * 60 - h._minuto;
}
