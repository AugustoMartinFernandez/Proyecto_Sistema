#pragma once
#include <string>
#include "Pago.h"

class PagoArchivo
{
public:
    PagoArchivo(std::string nombreArchivo = "pagos.dat");

    bool guardar(Pago registro);
    bool guardar(int pos, Pago registro);

    Pago leer(int pos);
    int  leerTodos(Pago pagos[], int cantidad);
    int  getCantidadRegistros();
    int  getNuevoID();

    int  buscarID(int idPago);// devuelve pos o -1

    bool eliminar(int pos);

private:
    std::string _nombreArchivo;
};
