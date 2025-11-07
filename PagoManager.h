#pragma once
#include "PagoArchivo.h"

class PagoManager {
public:
    PagoManager() = default;

    void altaPago();
    void listarPagos();
    void modificarPago();
    void bajaPago();

private:
    void mostrarPago(const Pago &p);

    PagoArchivo _repo;
};
