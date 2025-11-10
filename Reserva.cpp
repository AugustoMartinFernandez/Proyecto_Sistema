#include <cstring>
#include <string>
#include "Reserva.h"

using namespace std;

Reserva::Reserva()
: _idReserva(0),
  _idPlaza(0),
  _desde(),
  _hasta()
{
    _patente[0] = '\0';
    _estado[0]  = '\0';
}

Reserva::Reserva(int idReserva, int idPlaza, const std::string& patente,
                 FechaHora desde, FechaHora hasta, const std::string& estado)
{
    setIdReserva(idReserva);
    setIdPlaza(idPlaza);
    setPatente(patente);
    setDesde(desde);
    setHasta(hasta);
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

void Reserva::setDesde(FechaHora desde){ _desde = desde; }
void Reserva::setHasta(FechaHora hasta){ _hasta = hasta; }

void Reserva::setEstado(const std::string& estado){
    // campo de 20 chars -> 19 + '\0'
    strncpy(_estado, estado.c_str(), 19);
    _estado[19] = '\0';
}

/*================ GETTERS (const) ================*/
int Reserva::getIdReserva() const { return _idReserva; }
int Reserva::getIdPlaza() const { return _idPlaza; }
std::string Reserva::getPatente() const { return _patente; }
FechaHora Reserva::getDesde() const { return _desde; }
FechaHora Reserva::getHasta() const { return _hasta; }
std::string Reserva::getEstado() const { return _estado; }

/*================ UTIL ================*/
std::string Reserva::toString() const {
    return  std::to_string(_idReserva) + ", " +
            std::to_string(_idPlaza) + ", " +
            std::string(_patente) + ", " +
            _desde.toString() + " -> " +
            _hasta.toString() + ", " +
            std::string(_estado);
}
