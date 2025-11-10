#pragma once
#include <string>
#include "Fecha.h"
#include "Hora.h"

class Pago
{
public:
    Pago();
    Pago(int idPago, int idTicket, float importe, Fecha fecha, Hora hora,
         const std::string& medioPago, bool estadoPago);

    // Setters
    void setIdPago(int idPago);
    void setIdTicket(int idTicket);
    void setImporte(float importe);
    void setFecha(Fecha fecha);
    void setHora(Hora hora);
    void setMedioPago(const std::string &medioPago);
    void setEstadoPago(bool estadoPago);

    // Getters
    int getIdPago() const;
    int getIdTicket() const;
    float getImporte() const;
    Fecha getFecha() const;
    Hora getHora() const;
    std::string getMedioPago() const;
    bool getEstadoPago() const;

    std::string toString();

private:
    int   _idPago;
    int   _idTicket;
    float _importe;
    Fecha _fecha;
    Hora _hora;
    char  _medioPago[20];   // efectivo, debito, credito, etc.
    bool  _estadoPago;      // true=activo/valido, false=anulado
};
