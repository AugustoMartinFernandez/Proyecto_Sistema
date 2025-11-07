#include "PagoArchivo.h"
#include <cstdio>

PagoArchivo::PagoArchivo(std::string nombreArchivo)
: _nombreArchivo(std::move(nombreArchivo)) {}


bool PagoArchivo::guardar(Pago registro){
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr) return false;
    bool ok = fwrite(&registro, sizeof(Pago), 1, pFile) == 1;
    fclose(pFile);
    return ok;
}

//modif
bool PagoArchivo::guardar(int pos, Pago registro){
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr) return false;
    fseek(pFile, pos * (int)sizeof(Pago), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Pago), 1, pFile) == 1;
    fclose(pFile);
    return ok;
}

//por pos
Pago PagoArchivo::leer(int pos){
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    Pago reg;
    if(pFile == nullptr){
        reg.setIdPago(-1);
        return reg;
    }
    fseek(pFile, pos * (int)sizeof(Pago), SEEK_SET);
    if(fread(&reg, sizeof(Pago), 1, pFile) != 1){
        reg.setIdPago(-1);
    }
    fclose(pFile);
    return reg;
}

int PagoArchivo::leerTodos(Pago pagos[], int cantidad){
    if(pagos == nullptr || cantidad <= 0) return 0;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    int leidos = (int)fread(pagos, sizeof(Pago), cantidad, pFile);
    fclose(pFile);
    return leidos;
}

int PagoArchivo::getCantidadRegistros(){
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    fseek(pFile, 0, SEEK_END);
    int cant = (int)(ftell(pFile) / (long)sizeof(Pago));
    fclose(pFile);
    return cant;
}

int PagoArchivo::getNuevoID(){
    int cant = getCantidadRegistros();
    if(cant == 0) return 1;
    Pago ultimo = leer(cant - 1);
    if(ultimo.getIdPago() == -1) return 1;
    return ultimo.getIdPago() + 1;
}

//por id
int PagoArchivo::buscarID(int idPago){
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return -1;

    Pago reg;
    int pos = -1;
    while(fread(&reg, sizeof(Pago), 1, pFile) == 1){
        if(reg.getIdPago() == idPago){
            pos = (int)(ftell(pFile) / (long)sizeof(Pago)) - 1;
            break;
        }
    }
    fclose(pFile);
    return pos;
}

// baja lógica
bool PagoArchivo::eliminar(int pos){
    Pago reg = leer(pos);
    if(reg.getIdPago() == -1) return false;
    reg.setEstadoPago(false);
    return guardar(pos, reg);
}
