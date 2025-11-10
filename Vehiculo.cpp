#include <cstring>
#include <string>
#include "Vehiculo.h"

using namespace std;

Vehiculo::Vehiculo() {
    _patente[0] = '\0';
    _dniCliente[0] = '\0';
    _tipoVehiculo[0] = '\0';
    _estado[0] = '\0';
}
Vehiculo::Vehiculo(const string &patente, const string &dniCliente,
                   char tipoVehiculo, const string &estado) {
    setPatente(patente);
    setDniCliente(dniCliente);
    setTipoVehiculo(tipoVehiculo);
    setEstado(estado);
}


void Vehiculo::setPatente(const string &patente) {
    strncpy(_patente, patente.c_str(), 7);
    _patente[7] = '\0';
}
void Vehiculo::setDniCliente(const string &dniCliente) {
    strncpy(_dniCliente, dniCliente.c_str(), 8);
    _dniCliente[8] = '\0';
}
void Vehiculo::setTipoVehiculo(char tipoVehiculo) {
    _tipoVehiculo[0] = tipoVehiculo; // 'A', 'M' o 'C'
}
void Vehiculo::setEstado(const string &estado) {
    strncpy(_estado, estado.c_str(), 19);
    _estado[19] = '\0';
}


string Vehiculo::getPatente() const { return _patente; }
string Vehiculo::getDniCliente() const { return _dniCliente; }
char Vehiculo::getTipoVehiculo() const { return _tipoVehiculo[0]; }
string Vehiculo::getEstado() const { return _estado; }


string Vehiculo::getTipoVehiculoString() const {
    switch (_tipoVehiculo[0]) {
        case 'A': return "AUTO";
        case 'M': return "MOTO";
        case 'C': return "CAMIONETA";
        default:  return "DESCONOCIDO";
    }
}

string Vehiculo::toString() const {
    return string(_patente) + ", " +
           string(_dniCliente) + ", " +
           getTipoVehiculoString() + ", " +
           string(_estado);
}
