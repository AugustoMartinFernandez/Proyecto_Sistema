#include "Abono.h"
#include "utils.h"
#include <iostream>
#include <cstring>   // Para strncpy

using namespace std;


Abono::Abono(int id): desde(),hasta() {
    idAbono = id;
    setIdCliente("0");
    setPlan("Ninguno");
    precioMensual = 0.0f;
    idTarifa = 0;
    estado = 'A'; // Por defecto, Activo
}


void Abono::setIdCliente(const char* id) {
    strncpy(idCliente, id, 8);
    idCliente[8] = '\0';
}

void Abono::setPlan(const char* p) {
    strncpy(plan, p, 20);
    plan[20] = '\0';
}




int Abono::getIdAbono() const { return idAbono; }
FechaHora Abono::getDesde() const { return desde; }
FechaHora Abono::getHasta() const { return hasta; }
const char* Abono::getIdCliente() const { return idCliente; }
const char* Abono::getPlan() const { return plan; }
float Abono::getPrecioMensual() const { return precioMensual; }
int Abono::getIdTarifa() const { return idTarifa; }
char Abono::getEstado() const { return estado; }

void Abono::setIdAbono(int id) { idAbono = id; }
void Abono::setDesde(FechaHora h) { desde = h; }
void Abono::setHasta(FechaHora h) { hasta = h; }
void Abono::setPrecioMensual(float p) { precioMensual = p; }
void Abono::setIdTarifa(int id) { idTarifa = id; }
void Abono::setEstado(char e) { estado = e; }



void Abono::cargar() {
    cout << "--- Carga de nuevo Abono ---" << endl;

    cout << "Fecha desde: " << endl;
    FechaHora desde = cargarFechaHora();

    cout << "Fecha hasta: " << endl;
    FechaHora hasta = cargarFechaHora();
    estado = 'A';
}

void Abono::mostrar() const {
    cout << "ID ABONO: " << idAbono << " | ID CLIENTE: " << idCliente << endl;
    cout << "PLAN: " << plan << " | PRECIO: $" << precioMensual << " | TARIFA: " << idTarifa << endl;

    // MODIFICADO: Usamos el método toString() de la clase Hora
    cout << "VIGENCIA HORARIA: " << desde.toString()
         << " a " << hasta.toString();

    cout << " | ESTADO: " << estado << endl;
}
