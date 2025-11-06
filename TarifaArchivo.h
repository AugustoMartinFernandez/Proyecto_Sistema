#pragma once
#include <string>
#include "Tarifa.h"

class TarifaArchivo
{
public:
    TarifaArchivo(std::string nombreArchivo = "tarifas.dat");

    bool guardar(const Tarifa& registro);
    bool guardar(int pos, const Tarifa &registro);//(modificación por pos)
    //bool modificarPorId(int idTarifa, const Tarifa& r);  // modif por ID

    bool bajaLogicaPorPos(int pos, const char *nuevoEstado = "INACTIVO");
    //bool bajaLogicaPorId(int idTarifa, const char* nuevoEstado = "INACTIVO");

    // LECTURA
    Tarifa leer(int pos);
    int leerTodos(Tarifa tarifas[], int cantidad);
    int getCantidadRegistros();
    int getNuevoID();

    // BÚSQUEDAS
    int buscarPorId(int idTarifa);

    // Devuelve la cantidad encontrada y pone en 'out' hasta 'maxOut' coincidencias exactas
    //int buscarPorTipoVehiculo(const std::string& tipo, Tarifa* out, int maxOut);

private:
    std::string _nombreArchivo;
};
