#pragma once
#include <string>
#include "Reserva.h"

class ReservaArchivo
{
public:
    ReservaArchivo(std::string nombreArchivo = "reservas.dat");

    bool guardar(Reserva registro);
    bool guardar(int pos, Reserva registro);

    Reserva leer(int pos);
    int leerTodos(Reserva* vec, int cantidad);
    int getCantidadRegistros();
    int getNuevoID();

    int  buscarID(int idReserva);                   // devuelve pos o -1

    bool existeReservaActivaParaPatente(const std::string &patente,
                                    const FechaHora &ahora,
                                    Reserva *out = nullptr);

    bool eliminar(int pos, const char* nuevoEstado = "CANCELADA");

private:
    std::string _nombreArchivo;
};
