#include <iostream>
#include "ClienteManager.h"
#include "utils.h"

using namespace std;

void ClienteManager::mostrarCliente(const Cliente& c){
    cout << "DNI: "      << c.getDni()      << endl;
    cout << "Apellido: " << c.getApellido() << endl;
    cout << "Nombre: "   << c.getNombre()   << endl;
    cout << "Telefono: " << c.getTelefono() << endl;
    cout << "Email: "    << c.getEmail()    << endl;
    cout << "Estado: "   << (c.getEstado() ? "ACTIVO" : "INACTIVO") << endl;
}

Cliente ClienteManager::buscarPorDNI(const std::string& dni){
    int pos = _repo.buscarDNI(dni);
    if(pos == -1) return Cliente();  // ctor por defecto: strings vacíos
    return _repo.leer(pos);
}

bool ClienteManager::actualizar(const Cliente& c){
    int pos = _repo.buscarDNI(c.getDni());
    if(pos == -1) return false;
    return _repo.guardar(pos, c);
}


void ClienteManager::altaCliente(){
    cout << "---- ALTA DE CLIENTE ----" << endl;

    cout << "DNI: ";
    string dni = cargarCadena();

    if(_repo.buscarDNI(dni) != -1){
        cout << "Ya existe un cliente con ese DNI." << endl;
        return;
    }

    cout << "Nombre: ";
    string nombre = cargarCadena();

    cout << "Apellido: ";
    string apellido = cargarCadena();

    cout << "Telefono: ";
    string telefono = cargarCadena();

    cout << "Email: ";
    string email = cargarCadena();

    bool estado = true; // ACTIVO

    Cliente c(dni, nombre, apellido, telefono, email, estado);

    if(_repo.guardar(c)){
        cout << "Cliente guardado correctamente." << endl;
    }else{
        cout << "Error al guardar el cliente." << endl;
    }
}

// Alta rápida para flujos cuando ya tenés el DNI
Cliente ClienteManager::altaCliente(const std::string& dni){
    if(_repo.buscarDNI(dni) != -1){
        return _repo.leer(_repo.buscarDNI(dni));
    }

    cout << "---- ALTA DE CLIENTE (rapida) ----" << endl;
    cout << "DNI: " << dni << endl;

    cout << "Nombre: ";
    string nombre = cargarCadena();

    cout << "Apellido: ";
    string apellido = cargarCadena();

    cout << "Telefono: ";
    string telefono = cargarCadena();

    cout << "Email: ";
    string email = cargarCadena();

    bool estado = true;

    Cliente c(dni, nombre, apellido, telefono, email, estado);

    if(_repo.guardar(c)){
        cout << "Cliente guardado correctamente." << endl;
        return c;
    }else{
        cout << "Error al guardar el cliente." << endl;
        return Cliente();
    }
}


void ClienteManager::listarClientes(){
    cout << "---- LISTADO DE CLIENTES ----" << endl;
    int cant = _repo.getCantidadRegistros();
    for(int i=0; i<cant; ++i){
        Cliente c = _repo.leer(i);
        if(c.getDni().empty()) continue; // registro inválido
        mostrarCliente(c);
        cout << "----------------------------" << endl;
    }
}


void ClienteManager::modificarCliente(){
    cout << "---- MODIFICAR CLIENTE ----" << endl;
    cout << "DNI: ";
    string dni = cargarCadena();

    int pos = _repo.buscarDNI(dni);
    if(pos == -1){
        cout << "No existe un cliente con ese DNI." << endl;
        return;
    }

    Cliente c = _repo.leer(pos);
    cout << "Valores actuales:" << endl;
    mostrarCliente(c);

    int op = -1;
    while(op != 0){
        cout << endl;
        cout << "Que desea modificar?" << endl;
        cout << "1) Nombre" << endl;
        cout << "2) Apellido" << endl;
        cout << "3) Telefono" << endl;
        cout << "4) Email" << endl;
        cout << "5) Estado (Activo/Inactivo)" << endl;
        cout << "0) Guardar y salir" << endl;
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        if(op == 0) break;

        switch(op){
            case 1:{
                cout << "Nuevo nombre: ";
                string s = cargarCadena();
                c.setNombre(s);
            }break;
            case 2:{
                cout << "Nuevo apellido: ";
                string s = cargarCadena();
                c.setApellido(s);
            }break;
            case 3:{
                cout << "Nuevo telefono: ";
                string s = cargarCadena();
                c.setTelefono(s);
            }break;
            case 4:{
                cout << "Nuevo email: ";
                string s = cargarCadena();
                c.setEmail(s);
            }break;
            case 5:{
                char ch;
                cout << "Activo? (S/N): ";
                cin >> ch;
                c.setEstado(ch=='s' || ch=='S');
                cin.ignore();
            }break;
            default:
                cout << "Opcion invalida." << endl;
        }
    }

    if(_repo.guardar(pos, c)){
        cout << "Cliente actualizado correctamente." << endl;
    }else{
        cout << "No se pudieron guardar los cambios." << endl;
    }
}


void ClienteManager::bajaCliente(){
    cout << "---- BAJA LOGICA DE CLIENTE ----" << endl;
    cout << "DNI: ";
    string dni = cargarCadena();

    int pos = _repo.buscarDNI(dni);
    if(pos == -1){
        cout << "No existe un cliente con ese DNI." << endl;
        return;
    }

    Cliente c = _repo.leer(pos);
    cout << "Registro encontrado:" << endl;
    mostrarCliente(c);

    char ch;
    cout << "Confirmar baja (S/N): ";
    cin >> ch;

    if(ch=='s' || ch=='S'){
        if(_repo.eliminar(pos)){
            cout << "Cliente dado de baja correctamente." << endl;
        }else{
            cout << "No se pudo dar de baja el cliente." << endl;
        }
    }else{
        cout << "Operacion cancelada." << endl;
    }
}

