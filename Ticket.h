#pragma once
#include "FechaHora.h"

class Ticket {
private:
    int _idTicket;
    int _idReserva;
    int _idPlaza;
    char _patente[8]; // 7 chars + '\0'
    int _idTarifa;

    FechaHora _ingreso;
    FechaHora _salida;

    float _importe;
    char _estado[20]; // "ABIERTO", "CERRADO"

public:
    // Constructores
    Ticket();
    Ticket(int idTicket, int idReserva, int idPlaza,
           const std::string& patente, int idTarifa,
           const FechaHora& ingreso, const FechaHora& salida,
           float importe, const std::string& estado);

    // Getters
    int getIdTicket() const;
    int getIdReserva() const;
    int getIdPlaza() const;
    std::string getPatente() const;
    int getIdTarifa() const;

    FechaHora getIngreso() const;
    FechaHora getSalida() const;

    float getImporte() const;
    std::string getEstado() const;

    // Setters
    void setIdTicket(int id);
    void setIdReserva(int id);
    void setIdPlaza(int id);
    void setPatente(const std::string &patente);
    void setIdTarifa(int id);

    void setIngreso(FechaHora fh);
    void setSalida(FechaHora fh);

    void setImporte(float importe);
    void setEstado(const std::string &estado);

    // Métodos
    void mostrar() const;
};
