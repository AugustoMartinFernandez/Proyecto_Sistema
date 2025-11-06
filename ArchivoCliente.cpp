#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "ArchivoCliente.h"
using namespace std;

ArchivoCliente::ArchivoCliente(const std::string& nombreArchivo): _nombreArchivo(nombreArchivo) {}

bool ArchivoCliente::guardar(const Cliente& reg) {
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p) == 1;
    fclose(p);
    return ok;
}

Cliente ArchivoCliente::leer(int pos) {
    Cliente reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}

int ArchivoCliente::getCantidadRegistros() {
    int cantidad;
    FILE* p;
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    cantidad = ftell(p) / sizeof(Cliente);
	fclose(p);
    return cantidad;
}

void ArchivoCliente::listar() {
    Cliente reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo de clientes." << endl;
        return;
    }

    // Verificar si el archivo está vacío
    fseek(p, 0, SEEK_END);
    long bytes = ftell(p);
    fclose(p);

    if (bytes == 0) {
        cout << "No hay clientes cargados." << endl;
        return;
    }

    // Volvemos a abrir el archivo desde el inicio
    p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return;

    bool encontrado = false;
    while (fread(&reg, sizeof(Cliente), 1, p) == 1) {
        if (reg.getEstado()) {
            reg.mostrar();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No hay clientes activos." << endl;
    }

    fclose(p);

}

int ArchivoCliente::buscarPorDni(const char* dni) {
    Cliente reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return -1;

    int pos = 0;
    while (fread(&reg, sizeof(Cliente), 1, p) == 1) {
        // Comparar dni
        if (reg.getEstado()&&strcmp(reg.getDni(),dni)==0) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    
    fclose(p);
    return -1;
}

bool ArchivoCliente::sobreescribir(const Cliente& reg, int pos) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p) == 1;
    fclose(p);
    return ok;
}

bool ArchivoCliente::guardarEnPos(const Cliente& reg, int pos) {
    FILE* p;
    if (pos == -1) {
        p = fopen(_nombreArchivo.c_str(), "ab");
        if (p == nullptr) return false;
    }
    else {
        p = fopen(_nombreArchivo.c_str(), "rb+");
        if (p == nullptr) return false;
        fseek(p, pos * sizeof(Cliente), SEEK_SET);
    }
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p) == 1;
    fclose(p);
    return ok;
}