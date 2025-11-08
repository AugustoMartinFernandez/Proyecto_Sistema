#include <iostream>
#include <string>
#include "utils.h"
#include "ReservaManager.h"
#include "Reserva.h"

using namespace std;

/* -------- helper -------- */
void ReservaManager::mostrarReserva(const Reserva& r){
    cout << "ID Reserva: " << r.getIdReserva() << endl;
    cout << "ID Plaza: "   << r.getIdPlaza()   << endl;
    cout << "Patente: "    << r.getPatente()   << endl;
    cout << "Desde: "      << r.getDesdeHora().toString() << endl;
    cout << "Hasta: "      << r.getHastaHora().toString() << endl;
    cout << "Estado: "     << r.getEstado()    << endl;
}

/* -------- ABM -------- */

void ReservaManager::altaReserva(){
    cout << "---- ALTA DE RESERVA ----" << endl;

    int id = _repo.getNuevoID();
    cout << "Reserva #" << id << endl;

    int idPlaza;
    cout << "ID de Plaza: ";
    cin >> idPlaza;

    cin.ignore(); // limpiar fin de linea
    cout << "Patente (ej. ABC123): ";
    string patente = cargarCadena();

    cout << "Hora DESDE" << endl;
    Hora desde = cargarHora();
    cout << "Hora HASTA" << endl;
    Hora hasta = cargarHora();

    // Estado por defecto
    const string estado = "ACTIVA";

    Reserva r(id, idPlaza, patente, desde, hasta, estado);

    if(_repo.guardar(r)){
        cout << "Reserva guardada correctamente." << endl;
    }else{
        cout << "Error al guardar la reserva." << endl;
    }
}

void ReservaManager::listarReservas(){
    cout << "---- LISTADO DE RESERVAS ----" << endl;
    int cant = _repo.getCantidadRegistros();
    for(int i = 0; i < cant; ++i){
        Reserva r = _repo.leer(i);
        if(r.getIdReserva() == -1) continue;
        mostrarReserva(r);
        cout << "----------------------------" << endl;
    }
}

void ReservaManager::modificarReserva(){
    cout << "---- MODIFICAR RESERVA ----" << endl;
    int id;
    cout << "Ingrese ID de reserva: ";
    cin >> id;

    int pos = _repo.buscarID(id);
    if(pos == -1){
        cout << "No existe una reserva con ese ID." << endl;
        return;
    }

    Reserva r = _repo.leer(pos);
    cout << "Valores actuales:" << endl;
    mostrarReserva(r);

    int op = -1;
    while(op != 0){
        cout << endl;
        cout << "Que desea modificar?" << endl;
        cout << "1) ID Plaza" << endl;
        cout << "2) Patente" << endl;
        cout << "3) Hora DESDE" << endl;
        cout << "4) Hora HASTA" << endl;
        cout << "5) Estado" << endl;
        cout << "0) Guardar y salir" << endl;
        cout << "Opcion: ";
        cin >> op;

        if(op == 0) break;

        switch(op){
            case 1:{
                int v;
                cout << "Nuevo ID Plaza: ";
                cin >> v;
                r.setIdPlaza(v);
            }break;

            case 2:{
                cin.ignore();
                cout << "Nueva patente: ";
                string s = cargarCadena();
                r.setPatente(s);
            }break;

            case 3:{
                cout << "Nueva hora DESDE (hh mm): " << endl;
                r.setDesdeHora(cargarHora());
            }break;

            case 4:{
                cout << "Nueva hora HASTA (hh mm): " << endl;
                r.setHastaHora(cargarHora());
            }break;

            case 5:{
                cin.ignore();
                cout << "Nuevo estado (ACTIVA/CANCELADA): ";
                string s = cargarCadena();
                r.setEstado(s);
            }break;

            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }

    if(_repo.guardar(pos, r)){
        cout << "Reserva actualizada correctamente." << endl;
    }else{
        cout << "No se pudieron guardar los cambios." << endl;
    }
}

void ReservaManager::bajaReserva(){
    cout << "---- BAJA LOGICA DE RESERVA ----" << endl;
    int id;
    cout << "Ingrese ID de reserva: ";
    cin >> id;

    int pos = _repo.buscarID(id);
    if(pos == -1){
        cout << "No existe una reserva con ese ID." << endl;
        return;
    }

    Reserva r = _repo.leer(pos);
    cout << "Registro encontrado:" << endl;
    mostrarReserva(r);

    char c;
    cout << "Confirmar baja (S/N): ";
    cin >> c;

    if(c == 's' || c == 'S'){
        if(_repo.eliminar(pos, "CANCELADA")){
            cout << "Reserva dada de baja correctamente." << endl;
        }else{
            cout << "No se pudo dar de baja la reserva." << endl;
        }
    }else{
        cout << "Operacion cancelada." << endl;
    }
}
