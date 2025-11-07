#ifndef PLAZAMANAGER_H
#define PLAZAMANAGER_H

#include "Plaza.h"
#include "ArchivoPlaza.h"

class PlazaManager {
private:
    ArchivoPlaza _archivoPlazas; // El Manager usa la clase Archivo

public:
    // Constructor (podría inicializar el nombre de archivo si fuera necesario)
    PlazaManager(const char* rutaPlazas = "plazas.dat");

    // LÓGICA DE NEGOCIO (ABM)
    void altaPlaza();      // (A)ltas
    void listarPlazas();   // (L)istados
    void modificarPlaza(); // (M)odificaciones
    void bajaPlaza();      // (B)ajas (lógica)
};

#endif // PLAZAMANAGER_H
