#include "VehiculoArchivo.h"
#include <cstdio>
#include <utility>

VehiculoArchivo::VehiculoArchivo(std::string nombreArchivo)
: _nombreArchivo(std::move(nombreArchivo)) {}


bool VehiculoArchivo::guardar(Vehiculo registro){
    FILE* f = fopen(_nombreArchivo.c_str(), "ab");
    if(!f) return false;
    bool ok = fwrite(&registro, sizeof(Vehiculo), 1, f) == 1;
    fclose(f);
    return ok;
}
bool VehiculoArchivo::guardar(int pos, Vehiculo registro){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb+");
    if(!f) return false;
    fseek(f, pos * (int)sizeof(Vehiculo), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Vehiculo), 1, f) == 1;
    fclose(f);
    return ok;
}


Vehiculo VehiculoArchivo::leer(int pos){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    Vehiculo v;
    if(!f) return v;
    fseek(f, pos * (int)sizeof(Vehiculo), SEEK_SET);
    fread(&v, sizeof(Vehiculo), 1, f);
    fclose(f);
    return v;
}
int VehiculoArchivo::leerTodos(Vehiculo* vec, int cantidad){
    if(!vec || cantidad <= 0) return 0;
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return 0;
    int leidos = (int)fread(vec, sizeof(Vehiculo), cantidad, f);
    fclose(f);
    return leidos;
}
int VehiculoArchivo::getCantidadRegistros(){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return 0;
    fseek(f, 0, SEEK_END);
    int cant = (int)(ftell(f) / (long)sizeof(Vehiculo));
    fclose(f);
    return cant;
}


int VehiculoArchivo::buscarPorPatente(const std::string& patente){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return -1;

    Vehiculo v;
    int pos = -1;
    while(fread(&v, sizeof(Vehiculo), 1, f) == 1){
        if(v.getPatente() == patente){
            pos = (int)(ftell(f) / (long)sizeof(Vehiculo)) - 1;
            break;
        }
    }
    fclose(f);
    return pos;
}
int VehiculoArchivo::buscarPorDniCliente(const std::string& dni){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return -1;

    Vehiculo v;
    int pos = -1;
    while(fread(&v, sizeof(Vehiculo), 1, f) == 1){
        if(v.getDniCliente() == dni){
            pos = (int)(ftell(f) / (long)sizeof(Vehiculo)) - 1;
            break; // primera coincidencia
        }
    }
    fclose(f);
    return pos;
}


bool VehiculoArchivo::eliminar(int pos, const char* nuevoEstado){
    Vehiculo v = leer(pos);
    // si el archivo estaba vacío o pos inválida, v tendrá strings vacíos; igual intentamos
    v.setEstado(nuevoEstado ? nuevoEstado : "INACTIVO");
    return guardar(pos, v);
}
