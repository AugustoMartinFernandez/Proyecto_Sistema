#pragma once
class Vehiculo{
private:
	char _patente[8];
	char _dniCliente[9];
	char _tipoVehiculo[20];
	char _estado[20];

public:
	Vehiculo();
	
	const char* getPatente()const;
	const char* getDniCliente()const;
	const char* getTipoVehiculo()const;
	const char* getEstado()const;

	void setPatente(const char* patente);
	void setDniCliente(const char* dniCliente);
	void setTipoVehiculo(const char* tipoVehiculo);
	void setEstado(const char* estado);
	void cargar();
	void mostrar()const;
	bool esPatenteValida(const char* patenteVal);
	bool estadoValido(const char* estado);
};

