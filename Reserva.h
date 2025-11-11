#pragma once
#include <string>
#include "FechaHora.h"

class Reserva
{
public:
    Reserva();
    Reserva(int idReserva, int idPlaza, const std::string& patente,
            FechaHora desde, FechaHora hasta, const std::string& estado);

    void setIdReserva(int idReserva);
    void setIdPlaza(int idPlaza);
    void setPatente(const std::string& patente);
    void setDesde(FechaHora desde);
    void setHasta(FechaHora hasta);
    void setEstado(const std::string& estado);

    int getIdReserva() const;
    int getIdPlaza() const;
    std::string getPatente() const;
    FechaHora getDesde() const;
    FechaHora getHasta() const;
    std::string getEstado() const;

    std::string toString() const;

private:
    int  _idReserva;
    int  _idPlaza;
    char _patente[8];     // ej: "ABC123" (7 + '\0')
    FechaHora _desde;
    FechaHora _hasta;
    char _estado[20];     // ACTIVA/CONFIRMADA/VENCIDA/CANCELADA
};
