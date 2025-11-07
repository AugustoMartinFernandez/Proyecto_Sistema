#pragma once

#include "Hora.h" // Incluimos la estructura de Hora

class Abono {
private:
    int idAbono;
    Hora desdeHora;
    Hora hastaHora;
    char idCliente[9];  // 8 chars para el DNI/ID + 1 para '\0'
    char plan[21];      // 20 chars para el nombre del plan + 1 para '\0'
    float precioMensual;
    int idTarifa;       // Según el diagrama, se relaciona con una Tarifa
    char estado;        // 'A' (Activo), 'V' (Vencido), 'B' (Baja)

public:
    // Constructor (ID = -1 para indicador de error de lectura)
    Abono(int id = -1);

    // MÉTODOS DE LECTURA
    int getIdAbono() const;
    Hora getDesdeHora() const;
    Hora getHastaHora() const;
    const char* getIdCliente() const;
    const char* getPlan() const;
    float getPrecioMensual() const;
    int getIdTarifa() const;
    char getEstado() const;

    // MÉTODOS DE ESCRITURA
    void setIdAbono(int id);
    void setDesdeHora(Hora h);
    void setHastaHora(Hora h);
    void setIdCliente(const char* id);
    void setPlan(const char* p);
    void setPrecioMensual(float p);
    void setIdTarifa(int id);
    void setEstado(char e);

    // MÉTODOS DE GESTIÓN (Interfaz)
    void cargar();
    void mostrar() const;
};
