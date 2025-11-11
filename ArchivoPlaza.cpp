#include "ArchivoPlaza.h"
#include <cstdio> // Para FILE*, fopen, fread, fwrite, fseek, ftell
#include <iostream>
#include <cstring>

ArchivoPlaza::ArchivoPlaza(const char* nombre) : nombreArchivo(nombre) {}


bool ArchivoPlaza::grabarRegistro(const Plaza& reg) {
    FILE* pArch;
    pArch = fopen(nombreArchivo, "ab");

    if (pArch == nullptr) return false;

    bool escrito = (fwrite(&reg, sizeof(Plaza), 1, pArch) == 1);

    fclose(pArch);
    return escrito;
}

// Modificar: Recibe el objeto modificado y la posición ("rb+").
bool ArchivoPlaza::modificarRegistro(const Plaza& reg, int pos) {
    FILE* pArch;
    pArch = fopen(nombreArchivo, "rb+");

    if (pArch == nullptr) return false;

    // Posicionar el puntero
    fseek(pArch, pos * sizeof(Plaza), SEEK_SET);

    // Escribir (sobreescribir)
    bool modificado = (fwrite(&reg, sizeof(Plaza), 1, pArch) == 1);

    fclose(pArch);
    return modificado;
}

// Leer: Devuelve el objeto Plaza leído o un objeto con ID = -1 en caso de error.
Plaza ArchivoPlaza::leer(int pos) {
    Plaza registro; // Objeto local. Por defecto, su ID es -1 (indicador de error).
    FILE *pFile;

    pFile = fopen(nombreArchivo, "rb");

    if (pFile == nullptr) {
        return registro; // Devuelve el registro de error (ID = -1)
    }

    // Posicionar el puntero
    fseek(pFile, sizeof(Plaza) * pos, SEEK_SET);

    // Leer el registro. Si la lectura falla, los datos del objeto local no se alteran.
    fread(&registro, sizeof(Plaza), 1, pFile);

    fclose(pFile);

    return registro; // Devuelve el objeto leído o el objeto de error si fseek/fread fallaron.
}


int ArchivoPlaza::contarRegistros() const {
    FILE* pArch;
    pArch = fopen(nombreArchivo, "rb");
    if (pArch == nullptr) return 0;

    fseek(pArch, 0, SEEK_END);
    int bytes = ftell(pArch);
    fclose(pArch);

    if (sizeof(Plaza) == 0) return 0;
    return bytes / sizeof(Plaza);
}

Plaza ArchivoPlaza::buscarPlazaLibre(char tipoVehiculo) {
    FILE *pFile;
    pFile = fopen(nombreArchivo, "rb");
    Plaza plaza;

    if (pFile == nullptr) {
        plaza.setIdPlaza(-1);
        return plaza;
    }

    while(fread(&plaza, sizeof(Plaza), 1, pFile) == 1) {
        if(plaza.getTipo() == tipoVehiculo && plaza.getEstado() == 'L') {
            fclose(pFile);
            return plaza; // retorna la primera libre que encuentra
        }
    }

    fclose(pFile);
    Plaza sinPlaza;
    sinPlaza.setIdPlaza(-1);
    return sinPlaza;
}
