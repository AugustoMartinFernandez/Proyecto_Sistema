#include <iostream>
#include <algorithm>
#include "VehiculoManager.h"
#include "utils.h"
#include "utilsVehiculo.h"

using namespace std;

/* -------------------- helpers -------------------- */

void VehiculoManager::mostrarVehiculo(const Vehiculo& v){
    cout << "Patente: "      << v.getPatente() << endl;
    cout << "DNI Cliente: "  << v.getDniCliente() << endl;
    cout << "Tipo: "         << tipoVehiculoToString(v.getTipoVehiculo()) << endl;
    cout << "Estado: "       << v.getEstado() << endl;
}

char VehiculoManager::normalizarTipo(const std::string& tipo){
    string t = tipo;
    // normalizamos a minúsculas sin tildes (simple)
    transform(t.begin(), t.end(), t.begin(), [](unsigned char c){ return (char)tolower(c); });

    if(t.size() == 1){
        char c = (char)toupper(t[0]);
        if(c=='A' || c=='M' || c=='C') return c;
    }

    if(t.find("auto") != string::npos)      return 'A';
    if(t.find("moto") != string::npos)      return 'M';
    if(t.find("camio") != string::npos)     return 'C'; // camioneta/camión -> C
    // por defecto
    return 'A';
}

std::string VehiculoManager::validarDniCliente(){
    std::string dni;
    Cliente cliente;
    bool clienteOK = false;

    while(!clienteOK){
        cout << "DNI del cliente: ";
        dni = cargarCadena();

        int pos = _repoCliente.buscarDNI(dni);

        if(pos != -1){ // encontrado
            clienteOK = true;
        } else {
            cout << "No se encuentra un cliente asociado con ese DNI." << endl;
            cout << "1) Intentar con otro DNI" << endl;
            cout << "2) Cargar nuevo cliente con este DNI" << endl;
            cout << "0) Cancelar" << endl;
            cout << "Opcion: ";
            int op;
            cin >> op;
            cin.ignore();

            if(op == 1){
                continue; // vuelve al while
            }
            else if(op == 2){
                cliente = _clienteManager.altaCliente(dni);
                if(!cliente.getDni().empty()){
                    clienteOK = true;
                    cout << "--- CONTINUAMOS ALTA DE VEHICULO ---" << endl;
                } else {
                    cout << "No se pudo dar de alta el cliente." << endl;
                    return ""; // error
                }
            }
            else {
                cout << "Operacion cancelada." << endl;
                return "";
            }
        }
    }
    return dni;
}


/* -------------------- búsquedas/soporte -------------------- */

Vehiculo VehiculoManager::buscarPorPatente(const std::string& patente){
    int pos = _repo.buscarPorPatente(patente);
    if(pos == -1) return Vehiculo(); // patente vacía -> no encontrado
    return _repo.leer(pos);
}

bool VehiculoManager::actualizar(const Vehiculo& v){
    int pos = _repo.buscarPorPatente(v.getPatente());
    if(pos == -1) return false;
    return _repo.guardar(pos, v);
}

/* -------------------- altas -------------------- */

void VehiculoManager::altaVehiculo(){
    cout << "---- ALTA DE VEHICULO ----" << endl;

    cout << "Patente: ";
    string patente = cargarCadena();

    if(_repo.buscarPorPatente(patente) != -1){
        cout << "Ya existe un vehiculo con esa patente." << endl;
        return;
    }

    string dni = validarDniCliente();
    if(dni.empty()){
        cout << "Alta de vehiculo cancelada." << endl;
        return;
    }

    cout << "Tipo de vehiculo (auto/moto/camioneta o A/M/C): ";
    string tipoStr = cargarCadena();
    char tipo = normalizarTipo(tipoStr);

    string estado = "ACTIVO";

    Vehiculo v(patente, dni, tipo, estado);

    if(_repo.guardar(v)){
        cout << "Vehiculo guardado correctamente." << endl;
    }else{
        cout << "Error al guardar el vehiculo." << endl;
    }
}

Vehiculo VehiculoManager::altaVehiculo(const std::string& patente){
    // para flujos: asume patente ya ingresada
    if(_repo.buscarPorPatente(patente) != -1){
        return _repo.leer(_repo.buscarPorPatente(patente));
    }

    cout << "---- ALTA DE VEHICULO ----" << endl;
    cout << "Patente: " << patente << endl;

    //validacion si existe el DNI cargado
    string dni = validarDniCliente();
    if(dni.empty()){
        cout << "Alta de vehiculo cancelada." << endl;
        return Vehiculo();
    }

    cout << "Tipo de vehiculo (auto/moto/camioneta o A/M/C): ";
    string tipoStr = cargarCadena();
    char tipo = normalizarTipo(tipoStr);

    string estado = "ACTIVO";

    Vehiculo v(patente, dni, tipo, estado);

    if(_repo.guardar(v)){
        cout << "Vehiculo guardado correctamente." << endl;
        return v;
    }else{
        cout << "Error al guardar el vehiculo." << endl;
        return Vehiculo(); // patente vacía = no válido
    }
}

/* -------------------- listado -------------------- */

void VehiculoManager::listarVehiculos(){
    cout << "---- LISTADO DE VEHICULOS ----" << endl;
    int cant = _repo.getCantidadRegistros();
    for(int i=0; i<cant; ++i){
        Vehiculo v = _repo.leer(i);
        if(v.getPatente().empty()) continue; // registro invalido
        mostrarVehiculo(v);
        cout << "-----------------------------" << endl;
    }
}

/* -------------------- modificación -------------------- */

void VehiculoManager::modificarVehiculo(){
    cout << "---- MODIFICAR VEHICULO ----" << endl;
    cout << "Patente: ";
    string patente = cargarCadena();

    int pos = _repo.buscarPorPatente(patente);
    if(pos == -1){
        cout << "No existe un vehiculo con esa patente." << endl;
        return;
    }

    Vehiculo v = _repo.leer(pos);
    cout << "Valores actuales:" << endl;
    mostrarVehiculo(v);

    int op = -1;
    while(op != 0){
        cout << endl;
        cout << "Que desea modificar?" << endl;
        cout << "1) DNI del cliente" << endl;
        cout << "2) Tipo de vehiculo" << endl;
        cout << "3) Estado" << endl;
        cout << "0) Guardar y salir" << endl;
        cout << "Opcion: ";
        cin >> op;
        cin.ignore(); // limpiar salto para cargarCadena

        if(op == 0) break;

        switch(op){
            case 1:{
                cout << "Nuevo DNI del cliente: ";
                string dni = cargarCadena();
                v.setDniCliente(dni);
            }break;
            case 2:{
                cout << "Nuevo tipo (auto/moto/camioneta o A/M/C): ";
                string tipoStr = cargarCadena();
                v.setTipoVehiculo(normalizarTipo(tipoStr));
            }break;
            case 3:{
                cout << "Nuevo estado (ACTIVO/INACTIVO): ";
                string est = cargarCadena();
                v.setEstado(est);
            }break;
            default:
                cout << "Opcion invalida." << endl;
        }
    }

    if(_repo.guardar(pos, v)){
        cout << "Vehiculo actualizado correctamente." << endl;
    }else{
        cout << "No se pudieron guardar los cambios." << endl;
    }
}

/* -------------------- baja lógica -------------------- */

void VehiculoManager::bajaVehiculo(){
    cout << "---- BAJA LOGICA DE VEHICULO ----" << endl;
    cout << "Patente: ";
    string patente = cargarCadena();

    int pos = _repo.buscarPorPatente(patente);
    if(pos == -1){
        cout << "No existe un vehiculo con esa patente." << endl;
        return;
    }

    Vehiculo v = _repo.leer(pos);
    cout << "Registro encontrado:" << endl;
    mostrarVehiculo(v);

    char c;
    cout << "Confirmar baja (S/N): ";
    cin >> c;
    if(c=='s' || c=='S'){
        if(_repo.eliminar(pos, "INACTIVO")){
            cout << "Vehiculo dado de baja correctamente." << endl;
        }else{
            cout << "No se pudo dar de baja el vehiculo." << endl;
        }
    }else{
        cout << "Operacion cancelada." << endl;
    }
}

