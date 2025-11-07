#pragma once
#include "ArchivoVehiculo.h"
#include "ArchivoCliente.h"
#include "Vehiculo.h"
#include <string>

class ManagerVehiculo {
private:
    ArchivoVehiculo _repo;   // acceso al archivo de vehículos

protected:
    void mostrarLista(const Vehiculo& v);

public:
    ManagerVehiculo(const std::string& nombreArchivo = "Archivos.dat/vehiculos.dat");

    void cargar();      // Alta con validaciones (patente única, cliente activo)
    void mostrar();     // Listar todos los vehículos
    void buscar();      // Buscar por patente
    void actualizar();  // Modificar vehículo
    void eliminar();    // Baja lógica (marcar como retirado)
};

