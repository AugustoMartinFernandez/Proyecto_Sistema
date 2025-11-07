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
        cout << "Ingrese hora (0-23): ";
        cin >> hora;
    } while (hora < 0 || hora > 23);

    do {
        cout << "Ingrese minutos (0-59): ";
        cin >> minuto;
    } while (minuto < 0 || minuto > 59);
    return Hora(hora, minuto);
}
