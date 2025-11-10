#include "ArchivoAbono.h"
#include <cstdio> 

ArchivoAbono::ArchivoAbono(std::string nombre) : _nombreArchivo(nombre) {}

bool ArchivoAbono::guardar(const Abono& reg) {
    FILE* pArch = fopen(_nombreArchivo.c_str(), "ab"); 
    if (pArch == nullptr) return false;
    bool escrito = (fwrite(&reg, sizeof(Abono), 1, pArch) == 1);
    fclose(pArch);
    return escrito;
}

bool ArchivoAbono::sobreescribir(const Abono& reg, int pos) {
    FILE* pArch = fopen(_nombreArchivo.c_str(), "rb+"); 
    if (pArch == nullptr) return false;
    fseek(pArch, pos * sizeof(Abono), SEEK_SET);
    bool modificado = (fwrite(&reg, sizeof(Abono), 1, pArch) == 1);
    fclose(pArch);
    return modificado;
}

Abono ArchivoAbono::leer(int pos) {
    Abono registro; 
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return registro; 
    }
    fseek(pFile, sizeof(Abono) * pos, SEEK_SET);
    fread(&registro, sizeof(Abono), 1, pFile);
    fclose(pFile);
    return registro; 
}

int ArchivoAbono::getCantidadRegistros() const {
    FILE* pArch = fopen(_nombreArchivo.c_str(), "rb");
    if (pArch == nullptr) return 0;
    fseek(pArch, 0, SEEK_END);
    int bytes = ftell(pArch);
    fclose(pArch);
    if (sizeof(Abono) == 0) return 0;
    return bytes / sizeof(Abono);
}
