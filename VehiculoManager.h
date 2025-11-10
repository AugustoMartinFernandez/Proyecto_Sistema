#pragma once
#include <string>
#include "Vehiculo.h"
#include "VehiculoArchivo.h"
#include "ClienteArchivo.h"
#include "ClienteManager.h"

class VehiculoManager {
public:
    void altaVehiculo();
    void listarVehiculos();
    void modificarVehiculo();
    void bajaVehiculo();

    Vehiculo buscarPorPatente(const std::string& patente);
    Vehiculo altaVehiculo(const std::string& patente);
    bool actualizar(const Vehiculo& v);

private:
    void mostrarVehiculo(const Vehiculo& v);
    char normalizarTipo(const std::string& tipo);       // "auto"->'A', "moto"->'M', "camioneta"->'C'
    std::string tipoToString(char c);                   // 'A'->"AUTO", etc.
    std::string validarDniCliente();

    VehiculoArchivo _repo;
    ClienteArchivo _repoCliente;
    ClienteManager _clienteManager;
};
