#pragma once

#include "Abono.h"
#include <string>

class ArchivoAbono {
private:
    std::string _nombreArchivo;

public:
    ArchivoAbono(std::string nombre = "abonos.dat");

    bool guardar(const Abono& reg);        
    bool sobreescribir(const Abono& reg, int pos); 
    Abono leer(int pos);       
    int getCantidadRegistros() const;                  
};
