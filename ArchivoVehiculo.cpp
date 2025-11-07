#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include "ArchivoVehiculo.h"
using namespace std;

ArchivoVehiculo::ArchivoVehiculo(const std::string& nombreArchivo): _nombreArchivo(nombreArchivo){}

bool ArchivoVehiculo::guardar(const Vehiculo& reg) {
	FILE* p;
	p = fopen(_nombreArchivo.c_str(), "ab");
	if (p == nullptr) {
		return false;
	}
	bool ok = fwrite(&reg, sizeof(Vehiculo), 1, p) == 1;
	fclose(p);
	return ok;
}
Vehiculo ArchivoVehiculo::leer(int pos) {
	Vehiculo reg;
	FILE* p = fopen(_nombreArchivo.c_str(), "rb");
	if (p == nullptr) return reg;
	if (fseek(p, pos * sizeof(Vehiculo), SEEK_SET) != 0) {
		fclose(p);
		return reg;
	}
	if (fread(&reg, sizeof(Vehiculo), 1, p) != 1) {
		fclose(p);
		return reg;
	}
	fclose(p);
	return reg;
}
int ArchivoVehiculo::getCantidadRegistros() {
	int cantidad = 0;
	FILE* p = fopen(_nombreArchivo.c_str(), "rb");
	if (p == nullptr) {
		return 0;
	}
	if (fseek(p, 0, SEEK_END) != 0) {
		fclose(p);
		return 0;
	}
	long bytes = ftell(p);
	if (bytes >= 0) {
		cantidad = static_cast<int>(bytes / sizeof(Vehiculo));
	}
	fclose(p);
	return cantidad;
}
void ArchivoVehiculo::listar() {
	Vehiculo reg;
	bool encontrado = false;
	FILE* p = fopen(_nombreArchivo.c_str(), "rb");
	if (p == nullptr) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	while (fread(&reg, sizeof(Vehiculo), 1, p) == 1) {
		// Mostrar sólo si el estado NO es "Retirado"
		if (strcmp(reg.getEstado(), "Retirado") != 0) {
			reg.mostrar();
			encontrado = true;
		}
	}
	if (!encontrado) {
		cout << "No hay Vehiculos activos." << endl;
	}
	fclose(p);
}
int ArchivoVehiculo::buscarPorPatente(const char* patente) {
	Vehiculo reg;
	int pos = 0;
	FILE* p = fopen(_nombreArchivo.c_str(), "rb");
	if (p == nullptr) return -1;

	while (fread(&reg, sizeof(Vehiculo), 1, p) == 1) {
		if (strcmp(reg.getPatente(), patente) == 0) {
			fclose(p);
			return pos;
		}
		pos++;
	}

	fclose(p);
	return -1;
}
bool ArchivoVehiculo::sobreescribir(const Vehiculo& reg, int pos) {
	FILE* p;
	p = fopen(_nombreArchivo.c_str(), "rb+");
	if (p == nullptr) {
		return false;
	}
	if (fseek(p,pos * sizeof(Vehiculo), SEEK_SET) != 0) {
		fclose(p);
		return false;
	}
	bool ok = fwrite(&reg, sizeof(Vehiculo), 1, p) == 1;
	fclose(p);
	return ok;
}