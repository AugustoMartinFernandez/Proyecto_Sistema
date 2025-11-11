#pragma once

#include "Plaza.h"
#include "ArchivoPlaza.h"
#include "VehiculoManager.h"

class PlazaManager {
private:
    ArchivoPlaza _archivoPlazas; // El Manager usa la clase Archivo
    VehiculoManager _vehiculoManager;

public:
    PlazaManager(const char *rutaPlazas = "plazas.dat");

    void altaPlaza();
    void listarPlazas();
    void modificarPlaza();
    void bajaPlaza();
};
