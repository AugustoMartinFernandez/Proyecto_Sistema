#pragma once
#include <string>
#include "Cliente.h"

class ClienteArchivo
{
public:
    ClienteArchivo(std::string nombreArchivo = "clientes.dat");

    bool guardar(Cliente registro);
    bool guardar(int pos, Cliente registro);

    Cliente leer(int pos);
    int leerTodos(Cliente *vec, int cantidad);
    int getCantidadRegistros();

    int buscarDNI(const std::string& dni);          // devuelve pos o -1

    bool eliminar(int pos);                         // estado = false

private:
    std::string _nombreArchivo;
};
