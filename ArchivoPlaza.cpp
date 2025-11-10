#include "ArchivoPlaza.h"
#include <cstdio> 

ArchivoPlaza::ArchivoPlaza(std::string nombre) : _nombreArchivo(nombre) {}


bool ArchivoPlaza::guardar(const Plaza& reg) {
    FILE* pArch = fopen(_nombreArchivo.c_str(), "ab");
    if (pArch == nullptr) return false;
    bool escrito = (fwrite(&reg, sizeof(Plaza), 1, pArch) == 1);
    fclose(pArch);
    return escrito;
}

bool ArchivoPlaza::sobreescribir(const Plaza& reg, int pos) {
    FILE* pArch = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArch == nullptr) return false;
    fseek(pArch, pos * sizeof(Plaza), SEEK_SET);
    bool modificado = (fwrite(&reg, sizeof(Plaza), 1, pArch) == 1);
    fclose(pArch);
    return modificado;
}

Plaza ArchivoPlaza::leer(int pos) {
    Plaza reg; // ID por defecto es -1
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return reg;
    }
    fseek(pFile, pos * sizeof(Plaza), SEEK_SET);
    fread(&reg, sizeof(Plaza), 1, pFile);
    fclose(pFile);
    return reg;
}

int ArchivoPlaza::getCantidadRegistros() const {
    FILE* pArch = fopen(_nombreArchivo.c_str(), "rb");
    if (pArch == nullptr) return 0;
    fseek(pArch, 0, SEEK_END);
    int bytes = ftell(pArch);
    fclose(pArch);
    if (sizeof(Plaza) == 0) return 0;
    return bytes / sizeof(Plaza);
}
