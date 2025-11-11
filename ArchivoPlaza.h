#pragma once

#include "Plaza.h"
#include <string>

class ArchivoPlaza {
private:
    std::string _nombreArchivo;

public:
    ArchivoPlaza(std::string nombre = "plazas.dat");

    bool guardar(const Plaza& reg);
    bool sobreescribir(const Plaza& reg, int pos);
    Plaza leer(int pos);
    int getCantidadRegistros() const;

    Plaza buscarPlazaLibre(char tipoVehiculo);

};
