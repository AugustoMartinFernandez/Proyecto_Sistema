#pragma once
#include <string>
#include "Hora.h"
#include "Fecha.h"
#include "FechaHora.h"

std::string cargarCadena();

Hora cargarHora();

Fecha cargarFecha();

FechaHora cargarFechaHora();

int comparaFechas(const FechaHora &a, const FechaHora &b);
