#pragma once
#include <string>
#include "Vehiculo.h"
class ArchivoVehiculo{
private:
	std::string _nombreArchivo;

public:
	ArchivoVehiculo(const std::string &nombreArchivo ="Archivos.dat/vehiculos.dat");

	bool guardar(const Vehiculo &reg); // Append
	Vehiculo leer(int pos); // Leer por posicion
	int getCantidadRegistros();
	void listar(); // Listar todos
	int buscarPorPatente(const char* patente);
	bool sobreescribir(const Vehiculo& reg, int pos); // Modificar registro en pos
};

