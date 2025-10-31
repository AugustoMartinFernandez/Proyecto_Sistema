#pragma once
class Reserva{
private:
	int _idReserva;
	int _idPlaza;
	char _patente[8];
	// Hora _desdeHora;
	// Hora _hastaHora;
	char _estado[20];

public:
	/// CONSTRUCTOR
	Reserva();

	/// GETTERS
	int getIdReserva() const;
	int getIdPlaza() const;
	const char* getPatente()const;
	const char* getEstado()const;
	//Hora getDesdeHora() const;
	//Hora getHastaHora() const;

	/// SETTERS
	void setIdReserva(int idReserva);
	void setIdPlaza(int idPlaza);
	void setPatente(const char* patente);
	//void setDesdeHora(const Hora& desdeHora);
	//void setHastaHora(const Hora& hastaHora);
	void setEstado(const char* estado);
	void cargar();
	void mostrar();
};

