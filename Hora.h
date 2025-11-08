#pragma once

#include <string>
using namespace std;

class Hora {
private:
    int _hora;
    int _minuto;

public:
    // --- Constructores ---
    Hora();
    Hora(int hora, int minuto);

    // --- Getters (AHORA SON CONST) ---
    int getHora() const;
    int getMinuto() const;

    // --- Setters ---
    void setHora(int hora);
    void setMinuto(int minuto);

    // --- Métodos utilitarios (AHORA SON CONST) ---
    string toString() const;
    int aMinutos() const;
    int diferenciaMinutos(const Hora& h) const;
};
