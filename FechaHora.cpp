#include "FechaHora.h"
#include <ctime>  // Para time(), localtime(), mktime(), difftime()
#include <string>
#include <iostream> // (Para debug, aunque no es esencial)

using namespace std;

// Constructores
FechaHora::FechaHora()
: _anio(1970), _mes(1), _dia(1), _hora(0), _minuto(0) {}

FechaHora::FechaHora(int anio, int mes, int dia, int hora, int minuto)
: _anio(anio), _mes(mes), _dia(dia), _hora(hora), _minuto(minuto) {}

// Getters
int FechaHora::getAnio() const { return _anio; }
int FechaHora::getMes() const { return _mes; }
int FechaHora::getDia() const { return _dia; }
int FechaHora::getHora() const { return _hora; }
int FechaHora::getMinuto() const { return _minuto; }

// Setters
void FechaHora::setAnio(int anio) { _anio = anio; }
void FechaHora::setMes(int mes) { _mes = mes; }
void FechaHora::setDia(int dia) { _dia = dia; }
void FechaHora::setHora(int hora) { _hora = hora; }
void FechaHora::setMinuto(int minuto) { _minuto = minuto; }

string FechaHora::toString() const {
    string h = (_hora < 10 ? "0" : "") + to_string(_hora);
    string m = (_minuto < 10 ? "0" : "") + to_string(_minuto);
    return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio) + " " + h + ":" + m;
}

// Obtiene la fecha y hora actual del sistema
FechaHora FechaHora::ahora() {
    time_t t = time(nullptr); // time(0) también funciona
    tm* tiempo = localtime(&t);

    int anio = tiempo->tm_year + 1900; // tm_year es años desde 1900
    int mes = tiempo->tm_mon + 1;     // tm_mon es 0-11
    int dia = tiempo->tm_mday;
    int hora = tiempo->tm_hour;
    int minuto = tiempo->tm_min;

    return FechaHora(anio, mes, dia, hora, minuto);
}

// --- AÑADIDO ---
// Implementación de la diferencia de minutos
double FechaHora::diferenciaMinutos(const FechaHora& otra) const {
    // 1. Convertir 'this' (actual/salida) a time_t
    tm tiempo_actual = {0};
    tiempo_actual.tm_year = _anio - 1900;
    tiempo_actual.tm_mon = _mes - 1;
    tiempo_actual.tm_mday = _dia;
    tiempo_actual.tm_hour = _hora;
    tiempo_actual.tm_min = _minuto;
    tiempo_actual.tm_isdst = -1; // Dejar que mktime decida el horario de verano
    time_t time_actual = mktime(&tiempo_actual);

    // 2. Convertir 'otra' (ingreso) a time_t
    tm tiempo_otra = {0};
    tiempo_otra.tm_year = otra._anio - 1900;
    tiempo_otra.tm_mon = otra._mes - 1;
    tiempo_otra.tm_mday = otra._dia;
    tiempo_otra.tm_hour = otra._hora;
    tiempo_otra.tm_min = otra._minuto;
    tiempo_otra.tm_isdst = -1;
    time_t time_otra = mktime(&tiempo_otra);

    // 3. Calcular diferencia en segundos y convertir a minutos
    if (time_actual == -1 || time_otra == -1) {
        // Error en la conversión (ej. fecha inválida)
        return 0;
    }
    
    // difftime calcula (tiempo_actual - time_otra) en segundos
    // Lo queremos en minutos
    return difftime(time_actual, time_otra) / 60.0;
}
