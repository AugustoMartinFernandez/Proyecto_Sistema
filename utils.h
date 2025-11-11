#pragma once
#include <string>
#include "Hora.h"
#include "Fecha.h"
#include "FechaHora.h"

std::string cargarCadena();


FechaHora cargarFechaHora();
FechaHora cargarFechaHora(bool soloFecha);

int comparaFechas(const FechaHora &a, const FechaHora &b);
