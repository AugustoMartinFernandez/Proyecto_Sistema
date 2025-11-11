#pragma once

#include "FechaHora.h" // Incluimos la estructura de Hora

class Abono {
private:
    int idAbono;
    FechaHora desde;
    FechaHora hasta;
    char idCliente[9];  // 8 chars para el DNI/ID + 1 para '\0'
    char plan[21];      // 20 chars para el nombre del plan + 1 para '\0'
    float precioMensual;
    int idTarifa;       // Según el diagrama, se relaciona con una Tarifa
    char estado;        // 'A' (Activo), 'V' (Vencido), 'B' (Baja)

public:
    // Constructor (ID = -1 para indicador de error de lectura)
    Abono(int id = -1);

    int getIdAbono() const;
    FechaHora getDesde() const;
    FechaHora getHasta() const;
    const char* getIdCliente() const;
    const char* getPlan() const;
    float getPrecioMensual() const;
    int getIdTarifa() const;
    char getEstado() const;

    void setIdAbono(int id);
    void setDesde(FechaHora h);
    void setHasta(FechaHora h);
    void setIdCliente(const char* id);
    void setPlan(const char* p);
    void setPrecioMensual(float p);
    void setIdTarifa(int id);
    void setEstado(char e);

    void cargar();
    void mostrar() const;
};
