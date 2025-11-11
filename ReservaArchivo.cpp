#include "ReservaArchivo.h"
#include "utils.h"
#include <cstdio>
#include <utility>

ReservaArchivo::ReservaArchivo(std::string nombreArchivo)
: _nombreArchivo(std::move(nombreArchivo)) {}

bool ReservaArchivo::guardar(Reserva registro){
    FILE* f = fopen(_nombreArchivo.c_str(), "ab");
    if(!f) return false;
    bool ok = fwrite(&registro, sizeof(Reserva), 1, f) == 1;
    fclose(f);
    return ok;
}

bool ReservaArchivo::guardar(int pos, Reserva registro){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb+");
    if(!f) return false;
    fseek(f, pos * (int)sizeof(Reserva), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Reserva), 1, f) == 1;
    fclose(f);
    return ok;
}

Reserva ReservaArchivo::leer(int pos){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    Reserva r;
    if(!f){
        r.setIdReserva(-1);
        return r;
    }
    fseek(f, pos * (int)sizeof(Reserva), SEEK_SET);
    if(fread(&r, sizeof(Reserva), 1, f) != 1){
        r.setIdReserva(-1);
    }
    fclose(f);
    return r;
}

int ReservaArchivo::leerTodos(Reserva* vec, int cantidad){
    if(!vec || cantidad <= 0) return 0;
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return 0;
    int leidos = (int)fread(vec, sizeof(Reserva), cantidad, f);
    fclose(f);
    return leidos;
}

int ReservaArchivo::getCantidadRegistros(){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return 0;
    fseek(f, 0, SEEK_END);
    int cant = (int)(ftell(f) / (long)sizeof(Reserva));
    fclose(f);
    return cant;
}

int ReservaArchivo::getNuevoID(){
    int cant = getCantidadRegistros();
    if(cant == 0) return 1;
    Reserva ult = leer(cant - 1);
    if(ult.getIdReserva() == -1) return 1;
    return ult.getIdReserva() + 1;
}

int ReservaArchivo::buscarID(int idReserva){
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return -1;
    Reserva r;
    int pos = -1;
    while(fread(&r, sizeof(Reserva), 1, f) == 1){
        if(r.getIdReserva() == idReserva){
            pos = (int)(ftell(f) / (long)sizeof(Reserva)) - 1;
            break;
        }
    }
    fclose(f);
    return pos;
}


bool ReservaArchivo::existeReservaActivaParaPatente(const std::string &patente,
                                                    const FechaHora &ahora,
                                                    Reserva *out)
{
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    if(!f) return false;

    Reserva r;
    while(fread(&r, sizeof(Reserva), 1, f) == 1){
        if(r.getPatente() == patente && r.getEstado() == "ACTIVA"){
            // valida: _desde <= ahora <= _hasta
            if(comparaFechas(r.getDesde(), ahora) <= 0 && comparaFechas(ahora, r.getHasta()) <= 0){
                if(out) *out = r;
                fclose(f);
                return true;
            }
        }
    }
    fclose(f);
    return false;
}

bool ReservaArchivo::eliminar(int pos, const char* nuevoEstado){
    Reserva r = leer(pos);
    if(r.getIdReserva() == -1) return false;
    r.setEstado(nuevoEstado ? nuevoEstado : "CANCELADA");
    return guardar(pos, r);
}
