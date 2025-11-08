#include <cstring>
#include <string>
#include "Reserva.h"

using namespace std;

Reserva::Reserva()
: _idReserva(0),
  _idPlaza(0),
  _desdeHora(),
  _hastaHora()
{
    _patente[0] = '\0';
    _estado[0]  = '\0';
}

Reserva::Reserva(int idReserva, int idPlaza, const std::string& patente,
                 Hora desdeHora, Hora hastaHora, const std::string& estado)
{
    setIdReserva(idReserva);
    setIdPlaza(idPlaza);
    setPatente(patente);
    setDesdeHora(desdeHora);
    setHastaHora(hastaHora);
    setEstado(estado);
}

/*================ SETTERS ================*/
void Reserva::setIdReserva(int idReserva){ _idReserva = idReserva; }
void Reserva::setIdPlaza(int idPlaza){ _idPlaza = idPlaza; }

void Reserva::setPatente(const std::string& patente){
    // campo de 8 chars -> 7 + '\0'
    strncpy(_patente, patente.c_str(), 7);
    _patente[7] = '\0';
}

void Reserva::setDesdeHora(Hora desdeHora){ _desdeHora = desdeHora; }
void Reserva::setHastaHora(Hora hastaHora){ _hastaHora = hastaHora; }

void Reserva::setEstado(const std::string& estado){
    // campo de 20 chars -> 19 + '\0'
    strncpy(_estado, estado.c_str(), 19);
    _estado[19] = '\0';
}

/*================ GETTERS (const) ================*/
int Reserva::getIdReserva() const { return _idReserva; }
int Reserva::getIdPlaza() const { return _idPlaza; }
std::string Reserva::getPatente() const { return _patente; }
Hora Reserva::getDesdeHora() const { return _desdeHora; }
Hora Reserva::getHastaHora() const { return _hastaHora; }
std::string Reserva::getEstado() const { return _estado; }

/*================ UTIL ================*/
std::string Reserva::toString() const {
    return  std::to_string(_idReserva) + ", " +
            std::to_string(_idPlaza) + ", " +
            std::string(_patente) + ", " +
            _desdeHora.toString() + " -> " +
            _hastaHora.toString() + ", " +
            std::string(_estado);
}
