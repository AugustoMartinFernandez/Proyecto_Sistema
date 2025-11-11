#include <cstdio>
#include <cstring>

#include "TarifaArchivo.h"

TarifaArchivo::TarifaArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {}


bool TarifaArchivo::guardar(const Tarifa &registro){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr) return false;
    bool ok = fwrite(&registro, sizeof(Tarifa), 1, pFile) == 1;
    fclose(pFile);
    return ok;
}

bool TarifaArchivo::guardar(int pos, const Tarifa &registro){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr) return false;
    fseek(pFile, pos * (int)sizeof(Tarifa), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Tarifa), 1, pFile) == 1;
    fclose(pFile);
    return ok;
}

/*bool TarifaArchivo::modificarPorId(int idTarifa, const Tarifa& r){
    int pos = buscarPorId(idTarifa);
    if(pos < 0) return false;
    return guardar(pos, r);
}*/


bool TarifaArchivo::bajaLogicaPorPos(int pos){
    Tarifa reg = leer(pos);
    if(reg.getIdTarifa() == -1) return false;
    reg.setEstado(false);
    return guardar(pos, reg);
}

/*bool TarifaArchivo::bajaLogicaPorId(int idTarifa, const char* nuevoEstado){
    int pos = buscarPorId(idTarifa);
    if(pos < 0) return false;
    return bajaLogicaPorPos(pos, nuevoEstado);
}*/


Tarifa TarifaArchivo::leer(int pos){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    Tarifa reg;
    if(pFile == nullptr){
        reg.setIdTarifa(-1);
        return reg;
    }
    fseek(pFile, pos * sizeof(Tarifa), SEEK_SET);
    if(fread(&reg, sizeof(Tarifa), 1, pFile) != 1){
        reg.setIdTarifa(-1);
    }
    fclose(pFile);
    return reg;
}

int TarifaArchivo::leerTodos(Tarifa tarifas[], int cantidad){
    int leidos;
    if(tarifas == nullptr || cantidad <= 0) return 0;
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    leidos = fread(tarifas, sizeof(Tarifa), cantidad, pFile);
    fclose(pFile);
    return leidos;
}

int TarifaArchivo::getCantidadRegistros(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    fseek(pFile, 0, SEEK_END);
    int cant = ftell(pFile) / sizeof(Tarifa);
    fclose(pFile);
    return cant;
}

int TarifaArchivo::getNuevoID(){
    if(getCantidadRegistros() == 0){
        return 1;
    }

    return leer(getCantidadRegistros() - 1).getIdTarifa() + 1;
}



int TarifaArchivo::buscarPorId(int idTarifa){
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return -1;

    Tarifa reg;
    int pos = -1;
    while(fread(&reg, sizeof(Tarifa), 1, pFile) == 1){
        if(reg.getIdTarifa() == idTarifa){
            pos = ftell(pFile) / sizeof(Tarifa) - 1;
            break;
        }
    }
    fclose(pFile);
    return pos;
}

Tarifa TarifaArchivo::buscarTarifaVigente(char tipoVehiculo, const FechaHora &ahora) {
    FILE* f = fopen(_nombreArchivo.c_str(), "rb");
    Tarifa t;

    if (!f) {
        t.setIdTarifa(-1);
        return t;
    }
    while (fread(&t, sizeof(Tarifa), 1, f) == 1) {
        if (t.getTipoVehiculo() == tipoVehiculo && t.getEstado()) {
            // Verificar vigencia
            FechaHora desde = t.getVigenciaDesdeHora();
            FechaHora hasta = t.getVigenciaHastaHora();
            if (ahora.estaEntre(desde, hasta)){
                fclose(f);
                return t;
            }

        }
    }

    fclose(f);
    t.setIdTarifa(-1);
    return t;
}
