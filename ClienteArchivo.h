#pragma once
#include <string>
#include "Cliente.h"

class ClienteArchivo {
public:
    explicit ClienteArchivo(std::string nombreArchivo = "clientes.dat");

    // Altas / Modificación
    bool guardar(Cliente registro);                 // append
    bool guardar(int pos, Cliente registro);        // overwrite por posición

    // Lectura
    Cliente leer(int pos);
    int     leerTodos(Cliente* vec, int cantidad);
    int     getCantidadRegistros();

    // Búsquedas
    int buscarDNI(const std::string& dni);          // devuelve pos o -1

    // Baja lógica
    bool eliminar(int pos);                         // estado = false

private:
    std::string _nombreArchivo;
};
