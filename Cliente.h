#pragma once
class Cliente {
private:
	char _dni[9];
	char _nombre[30];
	char _apellido[30];
	char _telefono[12];
	char _email[30];
	bool _estado;

public:
	Cliente(); 

	const char* getDni();
	void setDni(const char* dni);

	const char* getNombre();
	void setNombre(const char* nombre);

	const char* getApellido();
	void setApellido(const char* apellido);

	const char* getTelefono();
	void setTelefono(const char* telefono);

	const char* getEmail();
	void setEmail(const char* email);

	bool getEstado();
	void setEstado(bool estado);

	void cargar();
	void mostrar();
};
