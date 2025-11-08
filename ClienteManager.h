#pragma once

#include "ArchivoCliente.h"
#include "ArchivoVehiculo.h" // Necesario para la baja
#include <string>

class ClienteManager {
private:
    ArchivoCliente _archivoClientes;
    ArchivoVehiculo _archivoVehiculos; // Para la baja lógica de vehículos

public:
    // Constructor
    ClienteManager(
        const std::string& rutaClientes = "clientes.dat",
        const std::string& rutaVehiculos = "vehiculos.dat"
    );


    void altaCliente();
    void listarClientesActivos();
    void buscarClientePorDni();
    void modificarCliente();
    void bajaCliente();
};

