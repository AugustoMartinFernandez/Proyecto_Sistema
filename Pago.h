#pragma once
#include <string>
#include "FechaHora.h"

class Pago
{
public:
    Pago();
    Pago(int idPago, int idTicket, float importe, FechaHora fechaHora,
         const std::string& medioPago, bool estadoPago);

    // Setters
    void setIdPago(int idPago);
    void setIdTicket(int idTicket);
    void setImporte(float importe);
    void setFechaHora(FechaHora fechaHora);
    void setMedioPago(const std::string &medioPago);
    void setEstadoPago(bool estadoPago);

    // Getters
    int getIdPago() const;
    int getIdTicket() const;
    float getImporte() const;
    FechaHora getFechaHora() const;
    std::string getMedioPago() const;
    bool getEstadoPago() const;

    std::string toString();

private:
    int   _idPago;
    int   _idTicket;
    float _importe;
    FechaHora _fechaHora;
    char  _medioPago[20];   // efectivo, debito, credito, etc.
    bool  _estadoPago;      // true=activo/valido, false=anulado
};
