#include "Plaza.h"
#include <iostream>
#include <cstring>   // Para strncpy

using namespace std;


Plaza::Plaza(int id, int num, int p, const char* sec, const char* t, char est) {
    idPlaza = id;
    numero = num;
    piso = p;
    setSector(sec);
    setTipo(t);
    estado = est;
}

// Setters de cadenas: Usan strncpy para asegurar que no excedan el tamaño del arreglo
void Plaza::setSector(const char* sec) {
    strncpy(sector, sec, 1); // Copia máximo 1 caracter
    sector[1] = '\0';        // Asegura el terminador nulo
}

void Plaza::setTipo(const char* t) {
    strncpy(tipo, t, 20);    // Copia máximo 20 caracteres
    tipo[20] = '\0';         // Asegura el terminador nulo
}



int Plaza::getIdPlaza() const { return idPlaza; }
int Plaza::getNumero() const { return numero; }
int Plaza::getPiso() const { return piso; }
const char* Plaza::getSector() const { return sector; }
const char* Plaza::getTipo() const { return tipo; }
char Plaza::getEstado() const { return estado; }

void Plaza::setIdPlaza(int id) { idPlaza = id; }
void Plaza::setNumero(int num) { numero = num; }
void Plaza::setPiso(int p) { piso = p; }
void Plaza::setEstado(char est) { estado = est; }


void Plaza::cargar() {
    cout << "--- Carga de nueva Plaza ---" << endl;
    
    // NOTA: Aquí se pedirá el ID, pero el Manager/Gestor debería autoincrementarlo.
    cout << "ID de Plaza: ";
    cin >> idPlaza;
    
    cout << "Numero de Plaza: ";
    cin >> numero;
    cout << "Piso: ";
    cin >> piso;
    
    char s[10], t[30]; // Buffers temporales para lectura
    cout << "Sector (ej: A, B): ";
    cin >> s;
    setSector(s);

    cout << "Tipo de Vehiculo (ej: Auto, Moto): ";
    cin >> t;
    setTipo(t);
    
    estado = 'L'; // Estado inicial: Libre
}

void Plaza::mostrar() const {
    cout << "ID: " << idPlaza << " | NUMERO: " << numero << " | PISO: " << piso << endl;
    cout << "SECTOR: " << sector << " | TIPO: " << tipo << " | ESTADO: " << estado << endl;
}
