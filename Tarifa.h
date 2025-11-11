#pragma once
#include <string>
#include "FechaHora.h"

class Tarifa
{
public:
    Tarifa();
    Tarifa(
        int idTarifa, char tipoVehiculo, int fraccionMin,
        float precioFraccion, float topeDiario, float precioNocturno,
        int toleranciaMin,
        FechaHora vigenciaDesdeHora, FechaHora vigenciaHastaHora,
        char tipoAbono[20], bool estado
    );

    // Getters
    int getIdTarifa() const;
    char getTipoVehiculo() const;
    int getFraccionMin() const;
    float getPrecioFraccion() const;
    float getTopeDiario() const;
    float getPrecioNocturno() const;
    int getToleranciaMin() const;
    FechaHora getVigenciaDesdeHora() const;
    FechaHora getVigenciaHastaHora() const;
    const char* getTipoAbono() const;
    bool getEstado() const;

    // Setters
    void setIdTarifa(int valor);
    void setTipoVehiculo(char valor);
    void setFraccionMin(int valor);
    void setPrecioFraccion(float valor);
    void setTopeDiario(float valor);
    void setPrecioNocturno(float valor);
    void setToleranciaMin(int valor);
    // --- ACTUALIZADO ---
    void setVigenciaDesdeHora(FechaHora valor);
    void setVigenciaHastaHora(FechaHora valor);
    void setTipoAbono(const char* valor);
    void setEstado(bool valor);

    // Métodos
    float calcularImporte(FechaHora ingreso, FechaHora salida) const;
    void cargar();
    void mostrar();
    std::string toString();

protected:

private:
    int _idTarifa;
    char _tipoVehiculo;
    int _fraccionMin;
    float _precioFraccion;
    float _topeDiario;
    float _precioNocturno;
    int _toleranciaMin;
    FechaHora _vigenciaDesdeHora;
    FechaHora _vigenciaHastaHora;
    char _tipoAbono[20];
    bool _estado;
};
