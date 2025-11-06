#pragma once
class Ticket{
private:
	int _idTicket;
	int _idReserva;
	int _idPlaza;
	char _patente[8];
	int _idTarifa;
	// Hora _horaDeIngreso;
	// Hora _horaDeSalida;
	float _importe;
	bool _estado;

public:
	Ticket();

	int getIdTicket() const;
	int getIdReserva() const;
	int getIdPlaza() const;
	const char* getPatente() const;
	int getIdTarifa() const;
	float getImporte() const;
	bool getEstado() const;

	float calcularImporte() const;

	void setIdTicket(int idTicket);
	void setIdReserva(int idReserva);
	void setIdPlaza(int idPlaza);
	void setPatente(const char* patente);
	void setIdTarifa(int idTarifa);
	void setImporte(float importe);
	void setEstado(bool estado);

	void cargar();
	void mostrar();

	// void abrir(const Hora& ingreso);
	// void cerrar(const Hora& salida);
};

