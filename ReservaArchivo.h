#pragma once
#include <string>
#include "Reserva.h"

class ReservaArchivo
{
public:
    ReservaArchivo(std::string nombreArchivo = "reservas.dat");

    // Altas / Modificación
    bool guardar(Reserva registro);                 // append
    bool guardar(int pos, Reserva registro);        // overwrite (modificación por posición)

    // Lectura
    Reserva leer(int pos);
    int     leerTodos(Reserva* vec, int cantidad);
    int     getCantidadRegistros();
    int     getNuevoID();

    // Búsquedas
    int  buscarID(int idReserva);                   // devuelve pos o -1
    int  buscarPorPatente(const std::string& patente, Reserva* out, int maxOut); // opcional

    // Baja lógica (cambiar estado)
    bool eliminar(int pos, const char* nuevoEstado = "CANCELADA");

private:
    std::string _nombreArchivo;
};
