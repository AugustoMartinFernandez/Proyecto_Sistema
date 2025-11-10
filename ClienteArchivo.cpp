#include "ClienteArchivo.h"
#include <cstdio>
#include <utility>

ClienteArchivo::ClienteArchivo(std::string nombreArchivo)
: _nombreArchivo(std::move(nombreArchivo)) {}

/* ============ GUARDAR ============ */

bool ClienteArchivo::guardar(Cliente registro){
    FILE* f = fopen(_nombreArchivo.c_str(), "ab");
    if(!f) return false;
    bool ok = fwrite(&registro, sizeof(Cliente), 1, f) == 1;
    fclose(f);
    return ok;
}

bool ClienteArchivo::guardar(int pos, Cliente registro){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb+");
    if(!f) return false;
    fseek(f, pos * (int)sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Cliente), 1, f) == 1;
    fclose(f);
    return ok;
}

/* ============ LECTURA ============ */

Cliente ClienteArchivo::leer(int pos){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    Cliente c;                 // por defecto (estado true, strings vacíos)
    if(!f) return c;
    fseek(f, pos * (int)sizeof(Cliente), SEEK_SET);
    fread(&c, sizeof(Cliente), 1, f);  // si falla, queda el ctor por defecto
    fclose(f);
    return c;
}

int ClienteArchivo::leerTodos(Cliente* vec, int cantidad){
    if(!vec || cantidad <= 0) return 0;
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return 0;
    int leidos = (int)fread(vec, sizeof(Cliente), cantidad, f);
    fclose(f);
    return leidos;
}

int ClienteArchivo::getCantidadRegistros(){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return 0;
    fseek(f, 0, SEEK_END);
    int cant = (int)(ftell(f) / (long)sizeof(Cliente));
    fclose(f);
    return cant;
}

/* ============ BÚSQUEDA ============ */

int ClienteArchivo::buscarDNI(const std::string& dni){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return -1;

    Cliente c;
    int pos = -1;
    while(fread(&c, sizeof(Cliente), 1, f) == 1){
        if(c.getDni() == dni){
            pos = (int)(ftell(f) / (long)sizeof(Cliente)) - 1;
            break;
        }
    }
    fclose(f);
    return pos;
}

/* ============ BAJA LÓGICA ============ */

bool ClienteArchivo::eliminar(int pos){
    Cliente c = leer(pos);
    c.setEstado(false);
    return guardar(pos, c);
}
