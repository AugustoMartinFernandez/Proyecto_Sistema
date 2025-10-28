#pragma once
#include "Cliente.h"
class ArchivoCliente{
private:
	char _nombreArchivo[30];

public:
	ArchivoCliente(const char* nombreArchivo = "clientes.dat");

	bool guardar(const Cliente& reg); // alta
	Cliente leer(int pos); // leer un registro por posicion
	int getCantidadRegistros();  // cantidad total de registros
	void listar(); // mostrar todos los clientes
	int buscarPorDni(const char* dni); // busqueda secuencial
	bool sobreescribir(const Cliente& reg, int pos);// modificar un registro

};

