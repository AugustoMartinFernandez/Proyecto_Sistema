#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "ArchivoCliente.h"
using namespace std;

ArchivoCliente::ArchivoCliente(const char* nombreArchivo) {
	// Copiamos el nombre del archivo de forma segura
	strncpy(_nombreArchivo, nombreArchivo, sizeof(_nombreArchivo) - 1);
	_nombreArchivo[sizeof(_nombreArchivo) - 1] = '\0'; // aseguramos terminador
}

bool ArchivoCliente::guardar(const Cliente& reg) {
	FILE* p = fopen(_nombreArchivo, "ab");
	if (p == NULL) return false;
	bool ok = fwrite(&reg, sizeof(Cliente),1,p)==1;
	fclose(p);
	return ok;
}

Cliente ArchivoCliente::leer(int pos) {
	Cliente reg;
	FILE* p = fopen(_nombreArchivo, "rb");
	if (p == NULL) return reg;
	fseek(p, pos * sizeof(Cliente), SEEK_SET);
	fread(&reg, sizeof(Cliente), 1, p);
	fclose(p);
	return reg;
}

int ArchivoCliente::getCantidadRegistros(){
	FILE* p = fopen(_nombreArchivo, "rb");
	if (p == NULL) {
		cout << "No se pudo abrir el archivo: " << _nombreArchivo << endl;
		return 0;
	}
	fseek(p, 0, SEEK_END);
	long bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(Cliente);
}

void ArchivoCliente::listar() {
	Cliente reg;
	FILE* p = fopen(_nombreArchivo, "rb");
	if (p == NULL) {
		cout << "No se pudo abrir el archivo." << endl;
		return;
	}
	int mostrados = 0;
	while (fread(&reg, sizeof(Cliente),1,p)== 1) {
		if (reg.getEstado()) { // solo activos
			reg.mostrar();
			mostrados++;
		}
	}
	fclose(p);
	if (mostrados == 0) {
		cout << "No hay clientes activos para listar." << endl;
		cout << endl;
	}
}
int ArchivoCliente::buscarPorDni(const char* dni) {
	Cliente reg;
	int pos = 0;

	FILE* p = fopen(_nombreArchivo, "rb");
	if (p == NULL) { 
		cout << "No se pudo abrir el archivo." << endl;
		return -1;
}
	while (fread(&reg,sizeof(Cliente),1,p)==1) {
		if (strcmp(reg.getDni(),dni)== 0 && reg.getEstado()) {
			fclose(p);
			return pos;
		}
		pos++;
	}
	fclose(p);
	return -1;
}

bool ArchivoCliente::sobreescribir(const Cliente& reg, int pos) {
	FILE* p = fopen(_nombreArchivo, "rb+"); // lectura y escritura
	if (p == NULL) return false;
	fseek(p, pos * sizeof(Cliente), SEEK_SET);
	bool ok = fwrite(&reg, sizeof(Cliente), 1, p) == 1;
	fclose(p);
	return ok;
}