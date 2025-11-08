#pragma once

#include "ArchivoVehiculo.h"
#include "ArchivoCliente.h" // Necesario para validar el DNI
#include <string>

class VehiculoManager {
private:
    ArchivoVehiculo _archivoVehiculos;
    ArchivoCliente _archivoClientes; // Para validación

public:
    // Constructor
    VehiculoManager(
        const std::string& rutaVehiculos = "vehiculos.dat",
        const std::string& rutaClientes = "clientes.dat"
    );

    void altaVehiculo();
    void listarVehiculos();
    void buscarVehiculoPorPatente();
    void modificarVehiculo();
    void bajaVehiculo(); // Marcar como retirado
};

