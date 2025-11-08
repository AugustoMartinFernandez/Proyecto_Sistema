#pragma once

#include "Hora.h"
#include "Fecha.h"

class Ticket {
private:
    int _idTicket;
    int _idReserva; // (0 si no aplica)
    int _idPlaza;
    char _patente[8]; // 
    int _idTarifa;
    Fecha _ingresoFecha;
    Hora _ingresoHora;
    Fecha _salidaFecha;
    Hora _salidaHora;
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
    Fecha getIngresoFecha() const;
    Hora getIngresoHora() const;
    Fecha getSalidaFecha() const;
    Hora getSalidaHora() const;
    float getImporte() const;
    const char* getEstado() const;

    // Setters
    void setIdTicket(int id);
    void setIdReserva(int id);
    void setIdPlaza(int id);
    void setPatente(const char* patente);
    void setIdTarifa(int id);
    void setIngresoFecha(Fecha f);
    void setIngresoHora(Hora h);
    void setSalidaFecha(Fecha f);
    void setSalidaHora(Hora h);
    void setImporte(float importe);
    void setEstado(const char* estado);

    // Métodos
    void cargar(int id); // 
    void mostrar() const;
};
