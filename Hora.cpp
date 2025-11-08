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

// --- Getters (con const) ---
int Hora::getHora() const {
    return _hora;
}

int Hora::getMinuto() const {
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

// --- toString (con const) ---
string Hora::toString() const {
    string h = (_hora < 10 ? "0" : "") + to_string(_hora);
    string m = (_minuto < 10 ? "0" : "") + to_string(_minuto);
    return h + ":" + m;
}

// --- aMinutos (con const) ---
int Hora::aMinutos() const {
    return _hora * 60 + _minuto;
}

// --- diferenciaMinutos (con const) ---
int Hora::diferenciaMinutos(const Hora& h) const {
    // El 'this' es const, pero 'h' no necesita serlo para leer sus miembros privados
    // (Aunque el parámetro 'h' ya es 'const Hora&')
    return this->aMinutos() - h.aMinutos(); // Usamos aMinutos() para ser consistentes
}
