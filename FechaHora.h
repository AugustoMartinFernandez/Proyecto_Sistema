#pragma once
#include <string>

class FechaHora {
public:
    FechaHora();
    FechaHora(int anio, int mes, int dia, int hora, int minuto);

    int getAnio() const;
    int getMes() const;
    int getDia() const;
    int getHora() const;
    int getMinuto() const;

    void setAnio(int anio);
    void setMes(int mes);
    void setDia(int dia);
    void setHora(int hora);
    void setMinuto(int minuto);

    std::string toString() const;

    // Devuelve la fecha y hora actual del sistema
    static FechaHora ahora();

private:
    int _anio;
    int _mes;
    int _dia;
    int _hora;
    int _minuto;
};
