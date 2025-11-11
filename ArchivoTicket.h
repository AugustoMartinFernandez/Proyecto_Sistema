#pragma once

#include "Ticket.h"
#include <string>

class ArchivoTicket {
private:
    const char* _nombreArchivo;

public:
    ArchivoTicket(const char* nombre = "tickets.dat");

    // Métodos estandarizados
    bool guardar(const Ticket& reg);
    bool sobreescribir(const Ticket& reg, int pos);
    Ticket leer(int pos);
    int getCantidadRegistros() const;

    // Métodos específicos
    int buscarPorID(int id); // Devuelve la posición (pos)
    bool existeTicketAbiertoPorPatente(const std::string& patente, Ticket* out = nullptr);
};
