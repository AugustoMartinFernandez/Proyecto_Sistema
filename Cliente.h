#pragma once
#include <string>

class Cliente
{
public:
    Cliente();
    Cliente(const std::string& dni, const std::string& nombre,
            const std::string& apellido, const std::string& telefono,
            const std::string& email, bool estado);

    void setDni(const std::string& dni);
    void setNombre(const std::string& nombre);
    void setApellido(const std::string& apellido);
    void setTelefono(const std::string& telefono);
    void setEmail(const std::string& email);
    void setEstado(bool estado);

    std::string getDni() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getTelefono() const;
    std::string getEmail() const;
    bool getEstado() const;

    std::string toString() const;

private:
    char _dni[9];
    char _nombre[30];
    char _apellido[30];
    char _telefono[12];
    char _email[30];
    bool _estado;
};
