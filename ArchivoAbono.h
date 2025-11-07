#ifndef ARCHIVOABONO_H
#define ARCHIVOABONO_H

#include "Abono.h" // Necesita saber qué estructura maneja

class ArchivoAbono {
private:
    const char* nombreArchivo;

public:
    // Constructor
    ArchivoAbono(const char* nombre = "abonos.dat");

    // MÉTODOS DE GESTIÓN DE ARCHIVOS (cstdio/FILE*)
    bool grabarRegistro(const Abono& reg);        
    bool modificarRegistro(const Abono& reg, int pos); 
    
    // Devuelve el objeto Abono leído o un objeto de error (ID = -1).
    Abono leerRegistro(int pos);       
    
    int contarRegistros() const;                  
};

#endif // ARCHIVOABONO_H
