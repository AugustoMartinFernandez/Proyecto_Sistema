#pragma once
#include "Vehiculo.h"
#include "VehiculoManager.h"
#include "VehiculoArchivo.h"

Vehiculo validaVehiculoBasico(VehiculoManager& vehiculoManager,
                        VehiculoArchivo& vehiculoArchivo);

std::string tipoVehiculoToString(char c);
