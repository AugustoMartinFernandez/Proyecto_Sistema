#pragma once
#include "Hora.h"

class Tarifa
{
public:
    Tarifa();
    Tarifa(
        int idTarifa, std::string tipoVehiculo, int fraccionMin,
        float precioFraccion, float topeDiario, float precioNocturno,
        int toleranciaMin, Hora vigenciaDesdeHora, Hora vigenciaHastaHora,
        char tipoAbono[20], char estado[20]
    );

    // Getters
    int getIdTarifa() const;
    std::string getTipoVehiculo() const;
    int getFraccionMin() const;
    float getPrecioFraccion() const;
    float getTopeDiario() const;
    float getPrecioNocturno() const;
    int getToleranciaMin() const;
    Hora getVigenciaDesdeHora() const;
    Hora getVigenciaHastaHora() const;
    const char* getTipoAbono() const;
    const char* getEstado() const;

    // Setters
    void setIdTarifa(int valor);
    void setTipoVehiculo(std::string valor);
    void setFraccionMin(int valor);
    void setPrecioFraccion(float valor);
    void setTopeDiario(float valor);
    void setPrecioNocturno(float valor);
    void setToleranciaMin(int valor);
    void setVigenciaDesdeHora(Hora valor);
    void setVigenciaHastaHora(Hora valor);
    void setTipoAbono(const char* valor);
    void setEstado(const char* valor);

    // Métodos
    float calcularImporte(Hora ingreso, Hora salida);
    void cargar();
    void mostrar();
    std::string toString();

protected:

private:
    int _idTarifa;
    char _tipoVehiculo[20];
    int _fraccionMin;
    float _precioFraccion;
    float _topeDiario;
    float _precioNocturno;
    int _toleranciaMin;
    Hora _vigenciaDesdeHora;
    Hora _vigenciaHastaHora;
    char _tipoAbono[20];
    char _estado[20];
};

