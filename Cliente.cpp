#include <cstring>
#include <string>
#include "Cliente.h"

using namespace std;

/*=========== CONSTRUCTORES ===========*/
Cliente::Cliente()
: _estado(true)
{
    _dni[0] = '\0';
    _nombre[0] = '\0';
    _apellido[0] = '\0';
    _telefono[0] = '\0';
    _email[0] = '\0';
}

Cliente::Cliente(const string& dni, const string& nombre,
                 const string& apellido, const string& telefono,
                 const string& email, bool estado)
: _estado(estado)
{
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
}

/*=========== SETTERS ===========*/
void Cliente::setDni(const string& dni){
    strncpy(_dni, dni.c_str(), 8);
    _dni[8] = '\0';
}

void Cliente::setNombre(const string& nombre){
    strncpy(_nombre, nombre.c_str(), 29);
    _nombre[29] = '\0';
}

void Cliente::setApellido(const string& apellido){
    strncpy(_apellido, apellido.c_str(), 29);
    _apellido[29] = '\0';
}

void Cliente::setTelefono(const string& telefono){
    strncpy(_telefono, telefono.c_str(), 11);
    _telefono[11] = '\0';
}

void Cliente::setEmail(const string& email){
    strncpy(_email, email.c_str(), 29);
    _email[29] = '\0';
}

void Cliente::setEstado(bool estado){
    _estado = estado;
}

/*=========== GETTERS ===========*/
string Cliente::getDni() const { return _dni; }
string Cliente::getNombre() const { return _nombre; }
string Cliente::getApellido() const { return _apellido; }
string Cliente::getTelefono() const { return _telefono; }
string Cliente::getEmail() const { return _email; }
bool Cliente::getEstado() const { return _estado; }

/*=========== UTIL ===========*/
string Cliente::toString() const {
    return string(_dni) + ", " +
           string(_apellido) + " " + string(_nombre) + ", " +
           string(_telefono) + ", " +
           string(_email) + ", " +
           (_estado ? "ACTIVO" : "INACTIVO");
}
