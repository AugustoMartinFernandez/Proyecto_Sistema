#pragma once

#include "Abono.h"
#include "ArchivoAbono.h"
#include "FechaHora.h"

class AbonoManager {
private:
    ArchivoAbono _archivoAbonos;

public:
    AbonoManager(const char* rutaAbonos = "abonos.dat");

    void altaAbono();
    void listarAbonos();
    void modificarAbono();
    void bajaAbono();
};
