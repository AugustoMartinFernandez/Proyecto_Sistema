#pragma once
#include <string>
#include "Hora.h"

class Reserva
{
public:
    Reserva();
    Reserva(int idReserva, int idPlaza, const std::string& patente,
            Hora desdeHora, Hora hastaHora, const std::string& estado);

    // Setters
    void setIdReserva(int idReserva);
    void setIdPlaza(int idPlaza);
    void setPatente(const std::string& patente);
    void setDesdeHora(Hora desdeHora);
    void setHastaHora(Hora hastaHora);
    void setEstado(const std::string& estado);

    // Getters (const-correct)
    int getIdReserva() const;
    int getIdPlaza() const;
    std::string getPatente() const;
    Hora getDesdeHora() const;
    Hora getHastaHora() const;
    std::string getEstado() const;

    // Util
    std::string toString() const;

private:
    int  _idReserva;
    int  _idPlaza;
    char _patente[8];     // ej: "ABC123" (7 + '\0')
    Hora _desdeHora;
    Hora _hastaHora;
    char _estado[20];     // ACTIVA / CANCELADA / etc.
};
