#pragma once
#include <string>

class Plaza {
private:
    int idPlaza;
    int numero;
    int piso;
    char sector[2];     // 1 char para el dato + 1 para el terminador nulo '\0'
    char tipo;
    char estado;        // 'L'ibre, 'O'cupada, 'R'eservada, 'F'uera de servicio

public:
    // Constructor. El valor por defecto id = -1 se usa para indicar un error de lectura.
    Plaza(int id = -1, int num = 0, int p = 0, const char* sec = " ", char t= 'A', char est = 'L');

    // MÉTODOS DE LECTURA (Getters - se declaran 'const' para seguridad)
    int getIdPlaza() const;
    int getNumero() const;
    int getPiso() const;
    const char* getSector() const;
    char getTipo() const;
    char getEstado() const;

    // MÉTODOS DE ESCRITURA (Setters - se declaran 'const' en los punteros)
    void setIdPlaza(int id);
    void setNumero(int num);
    void setPiso(int p);
    void setSector(const char* sec);
    void setTipo(char t);
    void setEstado(char est);


    void mostrar() const;

};
