#ifndef ABONOMANAGER_H
#define ABONOMANAGER_H

#include "Abono.h"
#include "ArchivoAbono.h"
#include "Hora.h" // Necesario para crear objetos Hora

class AbonoManager {
private:
    ArchivoAbono _archivoAbonos; // El Manager usa la clase Archivo

public:
    AbonoManager(const char* rutaAbonos = "abonos.dat");

    // LÓGICA DE NEGOCIO (ABM)
    void altaAbono();      
    void listarAbonos();   
    void modificarAbono(); 
    void bajaAbono();      
};

#endif // ABONOMANAGER_H
