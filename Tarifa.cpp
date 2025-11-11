#include <cstring>
#include <string>
#include <iostream>
#include "Tarifa.h"
#include "FechaHora.h" 

using namespace std;

Tarifa::Tarifa()
    : _idTarifa(0),
      _fraccionMin(0),
      _precioFraccion(0.0),
      _topeDiario(0.0),
      _precioNocturno(0.0),
      _toleranciaMin(0),
      _vigenciaDesdeHora(), // Llama al constructor por defecto de FechaHora
      _vigenciaHastaHora()
{
    _tipoVehiculo[0] = '\0';
    _tipoAbono[0]    = '\0';
    _estado[0]       = '\0';
}

Tarifa::Tarifa(
    int idTarifa, std::string tipoVehiculo, int fraccionMin,
    float precioFraccion, float topeDiario, float precioNocturno,
    int toleranciaMin, FechaHora vigenciaDesdeHora, FechaHora vigenciaHastaHora,
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

// --- Setters ---
void Tarifa::setIdTarifa(int idTarifa){ _idTarifa = idTarifa; }
void Tarifa::setTipoVehiculo(std::string tipoVehiculo){
    strncpy(_tipoVehiculo, tipoVehiculo.c_str(), 19);
    _tipoVehiculo[19] = '\0';
}
void Tarifa::setFraccionMin(int fraccionMin){ _fraccionMin = fraccionMin; }
void Tarifa::setPrecioFraccion(float precioFraccion){ _precioFraccion = precioFraccion; }
void Tarifa::setTopeDiario(float topeDiario){ _topeDiario = topeDiario; }
void Tarifa::setPrecioNocturno(float precioNocturno){ _precioNocturno = precioNocturno; }
void Tarifa::setToleranciaMin(int toleranciaMin){ _toleranciaMin = toleranciaMin; }
void Tarifa::setVigenciaDesdeHora(FechaHora vigenciaDesdeHora){ _vigenciaDesdeHora = vigenciaDesdeHora; }
void Tarifa::setVigenciaHastaHora(FechaHora vigenciaHastaHora){ _vigenciaHastaHora = vigenciaHastaHora; }
void Tarifa::setTipoAbono(const char* tipoAbono){
    strncpy(_tipoAbono, tipoAbono, 19);
    _tipoAbono[19] = '\0';
}
void Tarifa::setEstado(const char* estado){
    strncpy(_estado, estado, 19);
    _estado[19] = '\0';
}

// --- Getters ---
int Tarifa::getIdTarifa() const { return _idTarifa; }
std::string Tarifa::getTipoVehiculo() const { return _tipoVehiculo; }
int Tarifa::getFraccionMin() const { return _fraccionMin; }
float Tarifa::getPrecioFraccion() const { return _precioFraccion; }
float Tarifa::getTopeDiario() const { return _topeDiario; }
float Tarifa::getPrecioNocturno() const { return _precioNocturno; }
int Tarifa::getToleranciaMin() const { return _toleranciaMin; }
FechaHora Tarifa::getVigenciaDesdeHora() const { return _vigenciaDesdeHora; }
FechaHora Tarifa::getVigenciaHastaHora() const { return _vigenciaHastaHora; }
const char* Tarifa::getTipoAbono() const { return _tipoAbono; }
const char* Tarifa::getEstado() const { return _estado; }


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

// --- MÉTODO ACTUALIZADO ---
// Ahora acepta FechaHora y usa el método diferenciaMinutos()
float Tarifa::calcularImporte(FechaHora ingreso, FechaHora salida) const
{
    
    // 1. Usamos el método que creamos en FechaHora
    double minutosTotales = salida.diferenciaMinutos(ingreso);

    if (minutosTotales <= _toleranciaMin) {
        return 0.0f; // Dentro de la tolerancia
    }

    if (_fraccionMin <= 0) {
        return 9999.9f; // Error: Evitar división por cero
    }
    
    // 2. Cálculo simple por fracción
    // (Acá iría la lógica de precio nocturno y tope diario)
    
    // Calculamos cuántas fracciones de tiempo pasaron
    int cantidadFracciones = (int)(minutosTotales / _fraccionMin);
    if ( (int)minutosTotales % _fraccionMin > 0 ) {
        cantidadFracciones++; // Se cobra fracción extra si sobran minutos
    }
    
    float importeCalculado = cantidadFracciones * _precioFraccion;

    // 3. Aplicar tope diario (simplificado: si el importe es mayor al tope, se cobra el tope)
    // (Una lógica real debería calcular esto por cada día calendario transcurrido)
    if (_topeDiario > 0 && importeCalculado > _topeDiario) {
        return _topeDiario;
    }
    
    return importeCalculado;
}

// (Metodos que faltabam que faltaban)
void Tarifa::cargar() {
    cout << "Metodo Tarifa::cargar() no implementado." << endl;
}
void Tarifa::mostrar() {
    cout << "Metodo Tarifa::mostrar() no implementado." << endl;
}
