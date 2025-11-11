#include <cstring>
#include <string>
#include "Pago.h"

using namespace std;

Pago::Pago()
: _idPago(0),
  _idTicket(0),
  _importe(0.0f),
  _fechaHora(),
  _estadoPago(true)
{
    _medioPago[0] = '\0';
}

Pago::Pago(int idPago, int idTicket, float importe, FechaHora fechaHora,
           const std::string& medioPago, bool estadoPago)
{
    setIdPago(idPago);
    setIdTicket(idTicket);
    setImporte(importe);
    setFechaHora(fechaHora);
    setMedioPago(medioPago);
    setEstadoPago(estadoPago);
}


void Pago::setIdPago(int idPago){ _idPago = idPago; }
void Pago::setIdTicket(int idTicket){ _idTicket = idTicket; }
void Pago::setImporte(float importe){ _importe = importe; }
void Pago::setFechaHora(FechaHora fechaHora){ _fechaHora = fechaHora; }
void Pago::setMedioPago(const std::string& medioPago){
    // 20 chars en total -> 19 + '\0'
    strncpy(_medioPago, medioPago.c_str(), 19);
    _medioPago[19] = '\0';
}
void Pago::setEstadoPago(bool estadoPago){ _estadoPago = estadoPago; }


int Pago::getIdPago() const { return _idPago; }
int Pago::getIdTicket() const { return _idTicket; }
float Pago::getImporte() const { return _importe; }
FechaHora Pago::getFechaHora() const { return _fechaHora; }
std::string Pago::getMedioPago() const { return _medioPago; }
bool Pago::getEstadoPago() const { return _estadoPago; }


std::string Pago::toString(){
    return  std::to_string(_idPago) + ", " +
            std::to_string(_idTicket) + ", " +
            std::to_string(_importe) + ", " +
            _fechaHora.toString() + ", " +
            std::string(_medioPago) + ", " +
            (_estadoPago ? "ACTIVO" : "ANULADO");
}
