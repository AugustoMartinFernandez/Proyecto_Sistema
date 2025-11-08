#include "Abono.h"
#include <iostream>
#include <cstring>   // Para strncpy

using namespace std;


Abono::Abono(int id) {
    idAbono = id;
    desdeHora = {0, 0};
    hastaHora = {0, 0};
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
Hora Abono::getDesdeHora() const { return desdeHora; }
Hora Abono::getHastaHora() const { return hastaHora; }
const char* Abono::getIdCliente() const { return idCliente; }
const char* Abono::getPlan() const { return plan; }
float Abono::getPrecioMensual() const { return precioMensual; }
int Abono::getIdTarifa() const { return idTarifa; }
char Abono::getEstado() const { return estado; }

void Abono::setIdAbono(int id) { idAbono = id; }
void Abono::setDesdeHora(Hora h) { desdeHora = h; }
void Abono::setHastaHora(Hora h) { hastaHora = h; }
void Abono::setPrecioMensual(float p) { precioMensual = p; }
void Abono::setIdTarifa(int id) { idTarifa = id; }
void Abono::setEstado(char e) { estado = e; }



void Abono::cargar() {
    cout << "--- Carga de nuevo Abono ---" << endl;
    
    // ... (pedir idAbono, idCliente, plan, precio, idTarifa) ...

    // MODIFICADO: Usamos setters
    int h, m;
    cout << "Hora de inicio (HH MM): ";
    cin >> h >> m;
    desdeHora.setHora(h);
    desdeHora.setMinuto(m);

    cout << "Hora de fin (HH MM): ";
    cin >> h >> m;
    hastaHora.setHora(h);
    hastaHora.setMinuto(m);
    
    estado = 'A'; 
}

void Abono::mostrar() const {
    cout << "ID ABONO: " << idAbono << " | ID CLIENTE: " << idCliente << endl;
    cout << "PLAN: " << plan << " | PRECIO: $" << precioMensual << " | TARIFA: " << idTarifa << endl;
    
    // MODIFICADO: Usamos el método toString() de la clase Hora
    cout << "VIGENCIA HORARIA: " << desdeHora.toString() 
         << " a " << hastaHora.toString();
         
    cout << " | ESTADO: " << estado << endl;
}
