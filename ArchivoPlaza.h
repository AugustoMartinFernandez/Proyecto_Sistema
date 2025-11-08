#ifndef ARCHIVOPLAZA_H
#define ARCHIVOPLAZA_H

#include "Plaza.h" // Necesita saber qué estructura maneja

class ArchivoPlaza {
private:
    const char* nombreArchivo;

public:
    // Constructor. Permite cambiar el nombre del archivo si se necesita (ej. para backups).
    ArchivoPlaza(const char* nombre = "plazas.dat");

    bool grabarRegistro(const Plaza& reg);        
    bool modificarRegistro(const Plaza& reg, int pos); 
    Plaza leer(int pos);       
    int contarRegistros() const;                 
};

#endif // ARCHIVOPLAZA_H
