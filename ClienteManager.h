#pragma once
#include <string>
#include "Cliente.h"
#include "ClienteArchivo.h"

class ClienteManager {
public:
    ClienteManager() = default;

    // ABM interactivo
    void altaCliente();
    void listarClientes();
    void modificarCliente();
    void bajaCliente();

    // Soporte para flujos
    Cliente buscarPorDNI(const std::string& dni);
    Cliente altaCliente(const std::string& dni);  // alta rápida con DNI conocido
    bool actualizar(const Cliente& c);            // guarda por DNI

private:
    void mostrarCliente(const Cliente& c);

    ClienteArchivo _repo;
};
