#include "ArchivoAbono.h"
#include <cstdio> // Para FILE*, fopen, fread, fwrite, fseek, ftell

// **********************************
// IMPLEMENTACIÓN DE ARCHIVOABONO
// **********************************

ArchivoAbono::ArchivoAbono(const char* nombre) : nombreArchivo(nombre) {}

// Graba: Añade un nuevo registro al final ("ab").
bool ArchivoAbono::grabarRegistro(const Abono& reg) {
    FILE* pArch;
    pArch = fopen(nombreArchivo, "ab"); 
    
    if (pArch == nullptr) return false;

    bool escrito = (fwrite(&reg, sizeof(Abono), 1, pArch) == 1);
    
    fclose(pArch);
    return escrito;
}

// Modificar: Sobreescribe un registro existente en 'pos' ("rb+").
bool ArchivoAbono::modificarRegistro(const Abono& reg, int pos) {
    FILE* pArch;
    pArch = fopen(nombreArchivo, "rb+"); 
    
    if (pArch == nullptr) return false;

    fseek(pArch, pos * sizeof(Abono), SEEK_SET);
    
    bool modificado = (fwrite(&reg, sizeof(Abono), 1, pArch) == 1);
    
    fclose(pArch);
    return modificado;
}

// Leer: Devuelve el objeto Abono (o Abono con ID=-1 si falla).
Abono ArchivoAbono::leerRegistro(int pos) {
    Abono registro; // Por defecto, ID = -1 (indicador de error).
    FILE *pFile;

    pFile = fopen(nombreArchivo, "rb");

    if (pFile == nullptr) {
        return registro; // Devuelve el registro de error
    }

    fseek(pFile, sizeof(Abono) * pos, SEEK_SET);
    fread(&registro, sizeof(Abono), 1, pFile);
    fclose(pFile);

    return registro; 
}

// Contar: Devuelve el total de registros en el archivo.
int ArchivoAbono::contarRegistros() const {
    FILE* pArch;
    pArch = fopen(nombreArchivo, "rb");
    if (pArch == nullptr) return 0;

    fseek(pArch, 0, SEEK_END);
    int bytes = ftell(pArch);
    fclose(pArch);

    if (sizeof(Abono) == 0) return 0;
    return bytes / sizeof(Abono);
}
