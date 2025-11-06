#include <cstring>
#include <string>
#include "Tarifa.h"

using namespace std;

Tarifa::Tarifa()
    : _idTarifa(0),
      _fraccionMin(0),
      _precioFraccion(0.0),
      _topeDiario(0.0),
      _precioNocturno(0.0),
      _toleranciaMin(0),
      _vigenciaDesdeHora(),
      _vigenciaHastaHora()
{
    _tipoVehiculo[0] = '\0';
    _tipoAbono[0]    = '\0';
    _estado[0]       = '\0';
}

Tarifa::Tarifa(
    int idTarifa, std::string tipoVehiculo, int fraccionMin,
    float precioFraccion, float topeDiario, float precioNocturno,
    int toleranciaMin, Fecha vigenciaDesdeHora, Fecha vigenciaHastaHora,
    char tipoAbono[20], char estado[20]
)
{
    setIdTarifa(idTarifa);
    setTipoVehiculo(tipoVehiculo);
    setFraccionMin(fraccionMin);
    setPrecioFraccion(precioFraccion);
    setTopeDiario(topeDiario);
    setPrecioNocturno(precioNocturno);
    setToleranciaMin(toleranciaMin);
    setVigenciaDesdeHora(vigenciaDesdeHora);
    setVigenciaHastaHora(vigenciaHastaHora);
    setTipoAbono(tipoAbono);
    setEstado(estado);
}

///setters
void Tarifa::setIdTarifa(int idTarifa)
{
    _idTarifa = idTarifa;
}

void Tarifa::setTipoVehiculo(std::string tipoVehiculo)
{
    strncpy(_tipoVehiculo, tipoVehiculo.c_str(), 19);
    _tipoVehiculo[19] = '\0';
}

void Tarifa::setFraccionMin(int fraccionMin)
{
    _fraccionMin = fraccionMin;
}
void Tarifa::setPrecioFraccion(float precioFraccion)
{
    _precioFraccion = precioFraccion;
}
void Tarifa::setTopeDiario(float topeDiario)
{
    _topeDiario = topeDiario;
}
void Tarifa::setPrecioNocturno(float precioNocturno)
{
    _precioNocturno = precioNocturno;
}
void Tarifa::setToleranciaMin(int toleranciaMin)
{
    _toleranciaMin = toleranciaMin;
}

void Tarifa::setVigenciaDesdeHora(Fecha vigenciaDesdeHora)
{
    _vigenciaDesdeHora = vigenciaDesdeHora;
}
void Tarifa::setVigenciaHastaHora(Fecha vigenciaHastaHora)
{
    _vigenciaHastaHora = vigenciaHastaHora;
}

void Tarifa::setTipoAbono(const char* tipoAbono)
{
    strncpy(_tipoAbono, tipoAbono, 19);
    _tipoAbono[19] = '\0';
}

void Tarifa::setEstado(const char* estado)
{
    strncpy(_estado, estado, 19);
    _estado[19] = '\0';
}

///getters
int Tarifa::getIdTarifa() const
{
    return _idTarifa;
}
std::string Tarifa::getTipoVehiculo() const
{
    return _tipoVehiculo;
}
int Tarifa::getFraccionMin() const
{
    return _fraccionMin;
}
float Tarifa::getPrecioFraccion() const
{
    return _precioFraccion;
}
float Tarifa::getTopeDiario() const
{
    return _topeDiario;
}
float Tarifa::getPrecioNocturno() const
{
    return _precioNocturno;
}
int Tarifa::getToleranciaMin() const
{
    return _toleranciaMin;
}
Fecha Tarifa::getVigenciaDesdeHora() const
{
    return _vigenciaDesdeHora;
}
Fecha Tarifa::getVigenciaHastaHora() const
{
    return _vigenciaHastaHora;
}
const char* Tarifa::getTipoAbono() const
{
    return _tipoAbono;
}
const char* Tarifa::getEstado() const
{
    return _estado;
}



std::string Tarifa::toString()
{
    return  std::to_string(_idTarifa) + ", " +
            std::string(_tipoVehiculo) + ", " +
            std::to_string(_fraccionMin) + " min, " +
            std::to_string(_precioFraccion) + ", " +
            std::to_string(_topeDiario) + ", " +
            std::to_string(_precioNocturno) + ", " +
            std::to_string(_toleranciaMin) + ", " +
            _vigenciaDesdeHora.toString() + " -> " + _vigenciaHastaHora.toString() + ", " +
            std::string(_tipoAbono) + ", " +
            std::string(_estado);
}
