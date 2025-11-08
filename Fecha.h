#pragma once
#include <string>

class Fecha{
private:
	int _dia;
	int _mes;
	int _anio;

public:
	Fecha();
	Fecha(int dia, int mes, int anio);

	int getDia();
	void setDia(int dia);

	int getMes();
	void setMes(int dia); 

	int getAnio();
	void setAnio(int anio);

	std::string toString() const; 
};
