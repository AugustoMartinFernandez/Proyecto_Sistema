#pragma once
#include <string>
#include "Cliente.h"
class ArchivoCliente{
private:
	std::string _nombreArchivo;

public:
	ArchivoCliente(const std::string& nombreArchivo = "Archivos.dat/clientes.dat");

	bool guardar(const Cliente& reg); // alta
	Cliente leer(int pos); // leer un registro por posicion
	int getCantidadRegistros();  // cantidad total de registros
	void listar(); // mostrar todos los clientes
	int buscarPorDni(const char* dni); // busqueda secuencial
	bool sobreescribir(const Cliente& reg, int pos);// modificar un registro
	bool guardarEnPos(const Cliente& reg, int pos); // Este metodo reemplaza a Cliente::escribirDisco para permitir guardar en una posicion especifica
};

