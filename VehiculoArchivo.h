#pragma once
#include <string>
#include "Vehiculo.h"

class VehiculoArchivo
{
public:
    VehiculoArchivo(std::string nombreArchivo = "vehiculos.dat");

    bool guardar(Vehiculo registro);
    bool guardar(int pos, Vehiculo registro);

    Vehiculo leer(int pos);
    int leerTodos(Vehiculo *vec, int cantidad);
    int getCantidadRegistros();

    int buscarPorPatente(const std::string &patente);   // pos o -1
    int buscarPorDniCliente(const std::string &dni);    // primera coincidencia (pos o -1)

    bool eliminar(int pos, const char *nuevoEstado = "INACTIVO");

private:
    std::string _nombreArchivo;
};
