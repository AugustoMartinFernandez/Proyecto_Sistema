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
    char _estado[20]; // "Abierto", "Cerrado"

public:
    // Constructor (ID = -1 para error)
    Ticket(int id = -1);

    // Getters
    int getIdTicket() const;
    int getIdReserva() const;
    int getIdPlaza() const;
    const char* getPatente() const;
    int getIdTarifa() const;
    
    FechaHora getIngreso() const;
    FechaHora getSalida() const;
    
    float getImporte() const;
    const char* getEstado() const;

    // Setters
    void setIdTicket(int id);
    void setIdReserva(int id);
    void setIdPlaza(int id);
    void setPatente(const char* patente);
    void setIdTarifa(int id);

    void setIngreso(FechaHora fh);
    void setSalida(FechaHora fh);

    void setImporte(float importe);
    void setEstado(const char* estado);

    // Métodos
    void mostrar() const;
};
