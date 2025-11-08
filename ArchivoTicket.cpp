#include "ArchivoTicket.h"
#include <cstdio>

ArchivoTicket::ArchivoTicket(const char* nombre) : _nombreArchivo(nombre) {}

bool ArchivoTicket::guardar(const Ticket& reg) {
    FILE* pArch = fopen(_nombreArchivo, "ab");
    if (pArch == nullptr) return false;
    bool escrito = (fwrite(&reg, sizeof(Ticket), 1, pArch) == 1);
    fclose(pArch);
    return escrito;
}

bool ArchivoTicket::sobreescribir(const Ticket& reg, int pos) {
    FILE* pArch = fopen(_nombreArchivo, "rb+");
    if (pArch == nullptr) return false;
    fseek(pArch, pos * sizeof(Ticket), SEEK_SET);
    bool modificado = (fwrite(&reg, sizeof(Ticket), 1, pArch) == 1);
    fclose(pArch);
    return modificado;
}

Ticket ArchivoTicket::leer(int pos) {
    Ticket reg; // ID por defecto es -1
    FILE* pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) {
        return reg;
    }
    fseek(pFile, pos * sizeof(Ticket), SEEK_SET);
    fread(&reg, sizeof(Ticket), 1, pFile);
    fclose(pFile);
    return reg;
}

int ArchivoTicket::getCantidadRegistros() const {
    FILE* pArch = fopen(_nombreArchivo, "rb");
    if (pArch == nullptr) return 0;
    fseek(pArch, 0, SEEK_END);
    int bytes = ftell(pArch);
    fclose(pArch);
    return bytes / sizeof(Ticket);
}

int ArchivoTicket::buscarPorID(int id) {
    int cant = getCantidadRegistros();
    for (int i = 0; i < cant; i++) {
        Ticket reg = leer(i);
        if (reg.getIdTicket() == id) {
            return i; // Devuelve la posición
        }
    }
    return -1; // No encontrado
}
