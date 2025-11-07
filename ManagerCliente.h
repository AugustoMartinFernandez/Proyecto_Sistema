#pragma once
#include "ArchivoCliente.h"
#include "Cliente.h"
#include <string>

class ManagerCliente {
private:
    ArchivoCliente _repo;
protected:
    void mostrarLista(const Cliente& cliente);
public:
    ManagerCliente(const std::string& nombreArchivo = "Archivos.dat/clientes.dat");
    void cargar();     // Alta con validación de DNI único
    void mostrar();    // Listar clientes activos
    void buscar();     // Buscar cliente por DNI
    void actualizar(); // Modificar cliente
    void eliminar();   // Baja lógica por DNI
};

