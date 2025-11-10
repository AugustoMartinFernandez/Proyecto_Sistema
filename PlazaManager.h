#pragma once

#include "Plaza.h"
#include "ArchivoPlaza.h"

class PlazaManager {
private:
    ArchivoPlaza _archivoPlazas; // El Manager usa la clase Archivo

public:
    // Constructor (podría inicializar el nombre de archivo si fuera necesario)
    PlazaManager(const char *rutaPlazas = "plazas.dat");

    void altaPlaza();
    void listarPlazas();
    void modificarPlaza();
    void bajaPlaza();
};
