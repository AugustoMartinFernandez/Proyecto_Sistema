#include <iostream>
#include "utils.h"

std::string cargarCadena()
{
  std::string texto;

  if(std::cin.peek() == '\n')
  {
    std::cin.ignore();
  }

  std::getline(std::cin, texto);

  return texto;
}

Hora cargarHora()
{
    int hora = 0;
    int minuto = 0;

    do {
        std::cout << "Ingrese hora (0-23): ";
        std::cin >> hora;
    } while (hora < 0 || hora > 23);

    do {
        std::cout << "Ingrese minutos (0-59): ";
        std::cin >> minuto;
    } while (minuto < 0 || minuto > 59);

    std::cin.ignore();
    return Hora(hora, minuto);
}


bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}
Fecha cargarFecha()
{
    int dia = 0, mes = 0, anio = 0;
    int diasEnMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    do {
        std::cout << "Ingrese año (1900-2100): ";
        std::cin >> anio;
    } while (anio < 1900 || anio > 2100);

    do {
        std::cout << "Ingrese mes (1-12): ";
        std::cin >> mes;
    } while (mes < 1 || mes > 12);

    if (mes == 2 && esBisiesto(anio)) diasEnMes[2] = 29;

    do {
        std::cout << "Ingrese día (1-" << diasEnMes[mes] << "): ";
        std::cin >> dia;
    } while (dia < 1 || dia > diasEnMes[mes]);

    std::cin.ignore();
    return Fecha(dia, mes, anio);
}
