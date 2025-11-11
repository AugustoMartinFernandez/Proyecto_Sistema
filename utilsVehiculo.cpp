#include <iostream>
#include "utilsVehiculo.h"
#include "utils.h"

using namespace std;

Vehiculo validaVehiculoBasico(VehiculoManager& vehiculoManager,
                        VehiculoArchivo& vehiculoArchivo)
{
    cout << "Ingrese patente del vehículo: ";
    string patente = cargarCadena();

    int posVehiculo = vehiculoArchivo.buscarPorPatente(patente);
    Vehiculo vehiculo;

    //Si no existe el vehículo
    if (posVehiculo == -1) {
        cout << "Vehículo no encontrado. ¿Desea registrarlo? (S/N): ";
        char opc;
        cin >> opc;
        cin.ignore();

        if (opc == 's' || opc == 'S') {
            vehiculo = vehiculoManager.altaVehiculo(patente);
            posVehiculo = vehiculoArchivo.buscarPorPatente(patente);

            if (posVehiculo == -1) {
                cout << "Error al registrar el vehículo." << endl;
                return Vehiculo(); // vacío
            }
        } else {
            cout << "Operación cancelada." << endl;
            return Vehiculo(); // vacío
        }
    }

    //Si ya existía
    vehiculo = vehiculoArchivo.leer(posVehiculo);
    cout << "Vehículo encontrado (Patente: " << vehiculo.getPatente() << ")" << endl;
    return vehiculo;
}


std::string tipoVehiculoToString(char c){
    switch(c){
        case 'A': return "AUTO";
        case 'M': return "MOTO";
        case 'C': return "CAMIONETA";
        default:  return "DESCONOCIDO";
    }
}


