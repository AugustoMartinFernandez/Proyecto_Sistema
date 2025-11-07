#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include "Cliente.h"
using namespace std;

Cliente::Cliente() {
    strcpy(_dni, "00000000");
    strcpy(_nombre, "Sin Nombre");
    strcpy(_apellido, "Sin Apellido");
    strcpy(_telefono, "Sin_Numero");
    strcpy(_email,"sin_email@default");
    _estado = false;
}
void Cliente::cargar() {
    char dni[9], nombre[30], apellido[30], telefono[12], email[30];

    system("cls");
    cout << "==============================" << endl;
    cout << "        CARGA DE CLIENTE      " << endl;
    cout << "==============================" << endl;
    do {
        cout << "DNI (8 digitos)       : ";
        cin >> dni;
        setDni(dni);
        if (strcmp(getDni(), "00000000") == 0) {
            cout << "DNI invalido. Debe contener exactamente 8 digitos numericos." << endl;
            system("pause");
            system("cls");
        }
        else break;
    } while (true);
    cin.ignore();
    cout << "Apellido              : ";
    cin.getline(apellido, 30);
    setApellido(apellido);
    cout << "Nombre                : ";
    cin.getline(nombre, 30);
    setNombre(nombre);
    do {
        cout << "Telefono              : ";
        cin >> telefono;
        setTelefono(telefono);
        if (strcmp(_telefono, "sin telefono") == 0) {
            cout << "Telefono invalido. Ejemplo: 1123456789" << endl;
            system("pause");
            system("cls");
        }
        else break;
    } while (true);
    do {
        cout << "Email (usuario@dominio.com): ";
        cin >> email;
        setEmail(email);
        if (strcmp(_email, "sin_email@default") == 0) {
            cout << "Error: Email invalido. Debe contener '@' y '.'" << endl;
            system("pause");
            system("cls");
        }
        else break;
    } while (true);
    int estado;
    do {
        cout << "Esta activo (1 = Si | 0 = No): ";
        cin >> estado;

        if (estado == 1) {
            setEstado(true);
            break;
        }
        else if (estado == 0) {
            setEstado(false);
            break;
        }
        else {
            cout << "Error: Debe ingresar 1 (Si) o 0 (No)." << endl;
            system("pause");
            system("cls");
        }
    } while (true);

    cout << "==============================" << endl;
    system("pause");
}
void Cliente::mostrar()const{
    cout << "==============================" << endl;
    cout << "        DATOS DEL CLIENTE     " << endl;
    cout << "==============================" << endl;
    cout << "DNI         : " << _dni << endl;
    cout << "Apellido    : " << _apellido << endl;
    cout << "Nombre      : " << _nombre << endl;
    cout << "Teléfono    : " << _telefono << endl;
    cout << "Email       : " << _email << endl;
    cout << "Estado      : " << (_estado ? "ACTIVO" : "INACTIVO") << endl;
}

void Cliente::setDni(const char* dni) {
    if (strlen(dni) == 8) {
        bool esValido = true;
		// Recorremos cada uno de los 8 caracteres del DNI
        for (int i = 0; i < 8; i++) {
           // verifica si ese caracter es un numero
            if (!isdigit(dni[i])) {
                esValido = false;
                break;
            }
        }
        if (esValido) {
            strncpy(_dni, dni, 8);
            _dni[8] = '\0';
        }
        else {
            strncpy(_dni, "00000000",8);
            _dni[8] = '\0';
        }
    }
    else {
        strncpy(_dni, "00000000",8);
		_dni[8] = '\0';
    }
    
}
void Cliente::setNombre(const char* nombre) {
    if (strlen(nombre) < 30) {
        strncpy(_nombre, nombre, 29);
        _nombre[29] = '\0';
    }
    else {
        strncpy(_nombre, "Sin Nombre",29);
		_nombre[29] = '\0';
    }
}
void Cliente::setApellido(const char* apellido) {
    if (strlen(apellido) < 30) {
        strncpy(_apellido, apellido, 29);
		_apellido[29] = '\0';
    }
    else {
        strncpy(_apellido, "Sin Apellido",29);
        _apellido[29] = '\0';
    }
}
void Cliente::setTelefono(const char* telefono) {
    bool esValido = true;

    if (strlen(telefono) < 12) {
        for (int i = 0; i < strlen(telefono); i++) {
            if (!isdigit(telefono[i])) {
                esValido = false;
                break;
            }
        }

        if (esValido) {
            strncpy(_telefono, telefono, 11);
            _telefono[11] = '\0';
        }
        else {
            strncpy(_telefono, "sin telefono", 11);
            _telefono[11] = '\0';
        }
    }
    else {
        strncpy(_telefono, "sin telefono", 11);
        _telefono[11] = '\0';
    }
}
void Cliente::setEmail(const char* email) {
    bool tieneArroba = false;
    bool tienePunto = false;

    if (strlen(email) < 30) {
        for (int i = 0; i < strlen(email); i++) {
            if (email[i] == '@') {
                tieneArroba = true;
            }
            if (email[i] == '.') {
                tienePunto = true;
            }
        }

        if (tieneArroba && tienePunto) {
            strncpy(_email, email, 29);
            _email[29] = '\0';
        }
        else {
            strncpy(_email, "sin_email@default", 29);
            _email[29] = '\0';
        }
    }
    else {
        strncpy(_email, "sin_email@default", 29);
        _email[29] = '\0';
    }
}
void Cliente::setEstado(bool estado) {
    	_estado = estado;
}

const char* Cliente::getDni() {
	return _dni;
}
const char* Cliente::getNombre() {
	return _nombre;
}
const char* Cliente::getApellido() {
	return _apellido;
}
const char* Cliente::getTelefono() {
	return _telefono;
}
const char* Cliente::getEmail() {
	return _email;
}
bool Cliente::getEstado() {
	return _estado;
}