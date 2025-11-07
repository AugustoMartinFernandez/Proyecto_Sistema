#ifndef PLAZA_H
#define PLAZA_H

class Plaza {
private:
    int idPlaza;
    int numero;
    int piso;
    char sector[2];     // 1 char para el dato + 1 para el terminador nulo '\0'
    char tipo[21];      // 20 chars para el dato + 1 para '\0'
    char estado;        // 'L'ibre, 'O'cupada, 'R'eservada, 'F'uera de servicio

public:
    // Constructor. El valor por defecto id = -1 se usa para indicar un error de lectura.
    Plaza(int id = -1, int num = 0, int p = 0, const char* sec = " ", const char* t = " ", char est = 'L');

    // MÉTODOS DE LECTURA (Getters - se declaran 'const' para seguridad)
    int getIdPlaza() const;
    int getNumero() const;
    int getPiso() const;
    const char* getSector() const;
    const char* getTipo() const;
    char getEstado() const;

    // MÉTODOS DE ESCRITURA (Setters - se declaran 'const' en los punteros)
    void setIdPlaza(int id);
    void setNumero(int num);
    void setPiso(int p);
    void setSector(const char* sec);
    void setTipo(const char* t);
    void setEstado(char est);

    
    void cargar();
    void mostrar() const;
    
};

#endif // PLAZA_H
