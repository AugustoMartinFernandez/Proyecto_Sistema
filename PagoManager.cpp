#include <iostream>
#include <string>
#include "utils.h"
#include "PagoManager.h"
#include "Pago.h"

using namespace std;

void PagoManager::mostrarPago(const Pago &p){
    cout << "ID Pago: "     << p.getIdPago()     << endl;
    cout << "ID Ticket: "   << p.getIdTicket()   << endl;
    cout << "Importe: $"    << p.getImporte()    << endl;
    cout << "Fecha y Hora: "<< p.getFechaHora().toString() << endl;
    cout << "Medio: "       << p.getMedioPago() << endl;
    cout << "Estado: "      << (p.getEstadoPago() ? "ACTIVO" : "ANULADO") << endl;
}


void PagoManager::altaPago(){
    cout << "---- ALTA DE PAGO ----" << endl;
    int id = _repo.getNuevoID();
    cout << "Pago #" << id << endl;

    int idTicket;
    cout << "ID del Ticket: ";
    cin >> idTicket;

    float importe;
    cout << "Importe: $";
    cin >> importe;

    cout << "Fecha y Hora: " << endl;
    FechaHora fechaHora = cargarFechaHora();

    cout << "Medio de pago (EFECTIVO/DEBITO/CREDITO): ";
    string medio = cargarCadena();

    bool estado = true; // ACTIVO por defecto

    Pago pago(id, idTicket, importe, fechaHora, medio, estado);

    if(_repo.guardar(pago)){
        cout << "Pago guardado correctamente." << endl;
    }else{
        cout << "Error al guardar el pago." << endl;
    }
}

void PagoManager::listarPagos(){
    cout << "---- LISTADO DE PAGOS ----" << endl;
    int cant = _repo.getCantidadRegistros();
    for(int i=0; i<cant; ++i){
        Pago reg = _repo.leer(i);
        if(reg.getIdPago() == -1) continue;
        mostrarPago(reg);
        cout << "-------------------------" << endl;
    }
}

void PagoManager::modificarPago(){
    cout << "---- MODIFICAR PAGO ----" << endl;
    int id;
    cout << "Ingrese ID de pago: ";
    cin >> id;

    int pos = _repo.buscarID(id);
    if(pos == -1){
        cout << "No existe un pago con ese ID." << endl;
        return;
    }

    Pago p = _repo.leer(pos);
    cout << "Valores actuales:" << endl;
    mostrarPago(p);

    int op = -1;
    while(op != 0){
        cout << endl;
        cout << "Que desea modificar?" << endl;
        cout << "1) ID Ticket" << endl;
        cout << "2) Importe" << endl;
        cout << "3) Fecha" << endl;
        cout << "4) Medio de pago" << endl;
        cout << "5) Estado (Activo/Anulado)" << endl;
        cout << "0) Guardar y salir" << endl;
        cout << "Opcion: ";
        cin >> op;

        if(op == 0) break;

        switch(op){
            case 1:{
                int v;
                cout << "Nuevo ID Ticket: ";
                cin >> v;
                p.setIdTicket(v);
            }break;
            case 2:{
                float v;
                cout << "Nuevo importe: $";
                cin >> v;
                p.setImporte(v);
            }break;
            case 3:
            {
                cout << "Nueva fecha y hora" << endl;
                p.setFechaHora(cargarFechaHora());
            }break;
            case 4:{
                cin.ignore();
                cout << "Nuevo medio de pago: ";
                string s = cargarCadena();
                p.setMedioPago(s);
            }break;
            case 5:{
                char c;
                cout << "Activo? (S/N): ";
                cin >> c;
                p.setEstadoPago(c=='s' || c=='S');
            }break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }

    if(_repo.guardar(pos, p)){
        cout << "Pago actualizado correctamente." << endl;
    }else{
        cout << "No se pudieron guardar los cambios." << endl;
    }
}

void PagoManager::bajaPago(){
    cout << "---- BAJA LOGICA DE PAGO ----" << endl;
    int id;
    cout << "Ingrese ID de pago: ";
    cin >> id;

    int pos = _repo.buscarID(id);
    if(pos == -1){
        cout << "No existe un pago con ese ID." << endl;
        return;
    }

    Pago p = _repo.leer(pos);
    cout << "Registro encontrado:" << endl;
    mostrarPago(p);

    char c;
    cout << "Confirmar baja (S/N): ";
    cin >> c;
    if(c=='s' || c=='S'){
        if(_repo.eliminar(pos)){
            cout << "Pago anulado correctamente." << endl;
        }else{
            cout << "No se pudo anular el pago." << endl;
        }
    }else{
        cout << "Operacion cancelada." << endl;
    }
}
