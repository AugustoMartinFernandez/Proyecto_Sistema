#include "Plaza.h"
#include "utilsVehiculo.h"
#include <iostream>
#include <cstring>   // Para strncpy

using namespace std;


Plaza::Plaza(int id, int num, int p, const char* sec, char t, char est) {
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

int Plaza::getIdPlaza() const { return idPlaza; }
int Plaza::getNumero() const { return numero; }
int Plaza::getPiso() const { return piso; }
const char* Plaza::getSector() const { return sector; }
char Plaza::getTipo() const { return tipo; }
char Plaza::getEstado() const { return estado; }

void Plaza::setIdPlaza(int id) { idPlaza = id; }
void Plaza::setNumero(int num) { numero = num; }
void Plaza::setPiso(int p) { piso = p; }
void Plaza::setTipo(char t) { tipo = t; }
void Plaza::setEstado(char est) { estado = est; }


void Plaza::mostrar() const {
    cout << "ID: " << idPlaza << " | NUMERO: " << numero << " | PISO: " << piso << endl;
    cout << "SECTOR: " << sector << " | TIPO: " << tipoVehiculoToString(tipo) << " | ESTADO: " << estado << endl;
}
