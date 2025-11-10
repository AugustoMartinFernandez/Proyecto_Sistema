#pragma once
#include <string>

class Vehiculo
{
public:
    Vehiculo();
    Vehiculo(const std::string& patente, const std::string& dniCliente,
             char tipoVehiculo, const std::string& estado);

    void setPatente(const std::string& patente);
    void setDniCliente(const std::string& dniCliente);
    void setTipoVehiculo(char tipoVehiculo);
    void setEstado(const std::string& estado);

    std::string getPatente() const;
    std::string getDniCliente() const;
    char getTipoVehiculo() const;
    std::string getEstado() const;


    std::string getTipoVehiculoString() const;
    std::string toString() const;

private:
    char _patente[8];       // ej: "ABC123"
    char _dniCliente[9];    // DNI del cliente
    char _tipoVehiculo[1];  // 'A' = auto, 'M' = moto, 'C' = camioneta
    char _estado[20];       // ACTIVO / INACTIVO / ELIMINADO
};
