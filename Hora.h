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

    // --- Getters ---
    int getHora();
    int getMinuto();

    // --- Setters ---
    void setHora(int hora);
    void setMinuto(int minuto);

    // --- Métodos utilitarios ---
    string toString();                      // Devuelve "HH:MM"
    int aMinutos();                         // Convierte hora a minutos totales
    int diferenciaMinutos(const Hora& h);   // Diferencia entre dos horas
};
