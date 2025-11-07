#include <iostream>
#include <string>
#include "utils.h"
#include "Tarifa.h"
#include "TarifaArchivo.h"
#include "TarifaManager.h"

using namespace std;

static void mostrarTarifaEnConsola(const Tarifa& t){
    cout << "ID: " << t.getIdTarifa() << endl;
    cout << "Tipo Vehiculo: " << t.getTipoVehiculo() << endl;
    cout << "Fraccion Min: " << t.getFraccionMin() << " min" << endl;
    cout << "Precio por Fraccion: $" << t.getPrecioFraccion() << endl;
    cout << "Tope Diario: $" << t.getTopeDiario() << endl;
    cout << "Precio Nocturno: $" << t.getPrecioNocturno() << endl;
    cout << "Tolerancia: " << t.getToleranciaMin() << " min" << endl;
    cout << "Vigencia: " << t.getVigenciaDesdeHora().toString()
         << " -> " << t.getVigenciaHastaHora().toString() << endl;
    cout << "Tipo Abono: " << t.getTipoAbono() << endl;
    cout << "Estado: " << t.getEstado() << endl;
}

void TarifaManager::altaTarifa()
{
    cout << "---- ALTA DE TARIFA ----" << endl;
    int id = _archivo.getNuevoID();

    cout << "Tipo de vehiculo (auto/moto/etc): ";
    string tipoVehiculo = cargarCadena();
    int fraccionMin;
    cout << "Fraccion minima (minutos): ";
    cin >> fraccionMin;

    float precioFraccion, topeDiario, precioNocturno;
    cout << "Precio por fraccion: $";   cin >> precioFraccion;
    cout << "Tope diario: $";           cin >> topeDiario;
    cout << "Precio nocturno: $";       cin >> precioNocturno;

    int tolerancia;
    cout << "Tolerancia (minutos): ";
    cin >> tolerancia;

    cout << "Vigencia DESDE" << endl;
    Hora desde = cargarHora();
    cout << "Vigencia HASTA" << endl;
    Hora hasta = cargarHora();

    cin.ignore();
    cout << "Tipo de abono (texto corto): ";
    string tipoAbono = cargarCadena();

    // Estado por defecto ACTIVO
    const char* estado = "ACTIVO";

    Tarifa t(
        id, tipoVehiculo, fraccionMin,
        precioFraccion, topeDiario, precioNocturno,
        tolerancia, desde, hasta,
        (char*)tipoAbono.c_str(), (char*)estado
    );

    if(_archivo.guardar(t)){
        cout << "Tarifa #" << id << " guardada correctamente." << endl;
    }else{
        cout << "Error al guardar la tarifa." << endl;
    }
}

void TarifaManager::bajaTarifa()
{
    cout << "---- BAJA LOGICA DE TARIFA ----" << endl;
    int id;
    cout << "Ingrese ID de tarifa: ";
    cin >> id;

    int pos = _archivo.buscarPorId(id);
    if(pos == -1){
        cout << "No existe una tarifa con ese ID." << endl;
        return;
    }

    Tarifa reg = _archivo.leer(pos);
    cout << "Tarifa encontrada:" << endl;
    mostrarTarifaEnConsola(reg);

    char conf;
    cout << "Confirmar baja logica? (S/N): ";
    cin >> conf;

    if(conf=='s' || conf=='S'){
        if(_archivo.bajaLogicaPorPos(id -1, "INACTIVO")){
            cout << "Tarifa dada de baja correctamente." << endl;
        }else{
            cout << "No se pudo realizar la baja." << endl;
        }
    }else{
        cout << "Operacion cancelada." << endl;
    }
}

void TarifaManager::modificarTarifa()
{
    cout << "---- MODIFICAR TARIFA ----" << endl;
    int id;
    cout << "Ingrese ID de tarifa: ";
    cin >> id;

    int pos = _archivo.buscarPorId(id);
    if(pos == -1){
        cout << "No existe una tarifa con ese ID." << endl;
        return;
    }

    Tarifa t = _archivo.leer(pos);
    cout << "Valores actuales:" << endl;
    mostrarTarifaEnConsola(t);

    int opcion = -1;
    while(opcion != 0){
        cout << endl << "Que desea modificar?" << endl;
        cout << "1) Tipo de vehiculo" << endl;
        cout << "2) Fraccion minima" << endl;
        cout << "3) Precio por fraccion" << endl;
        cout << "4) Tope diario" << endl;
        cout << "5) Precio nocturno" << endl;
        cout << "6) Tolerancia" << endl;
        cout << "7) Vigencia DESDE" << endl;
        cout << "8) Vigencia HASTA" << endl;
        cout << "9) Tipo de abono" << endl;
        cout << "10) Estado" << endl;
        cout << "0) Guardar y salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if(opcion == 0) break;

        switch(opcion){
            case 1:{
                cin.ignore();
                cout << "Nuevo tipo de vehiculo: ";
                string s = cargarCadena();
                t.setTipoVehiculo(s.c_str());
            }break;
            case 2:{
                int v; cout << "Nueva fraccion (min): "; cin >> v;
                t.setFraccionMin(v);
            }break;
            case 3:{
                float v; cout << "Nuevo precio por fraccion: $"; cin >> v;
                t.setPrecioFraccion(v);
            }break;
            case 4:{
                float v; cout << "Nuevo tope diario: $"; cin >> v;
                t.setTopeDiario(v);
            }break;
            case 5:{
                float v; cout << "Nuevo precio nocturno: $"; cin >> v;
                t.setPrecioNocturno(v);
            }break;
            case 6:{
                int v; cout << "Nueva tolerancia (min): "; cin >> v;
                t.setToleranciaMin(v);
            }break;
            case 7:{
                cout << "Nueva vigencia DESDE" << endl;
                t.setVigenciaDesdeHora(cargarHora());
            }break;
            case 8:{
                cout << "Nueva vigencia HASTA" << endl;
                t.setVigenciaHastaHora(cargarHora());
            }break;
            case 9:{
                cin.ignore();
                cout << "Nuevo tipo de abono: ";
                string s = cargarCadena();
                t.setTipoAbono(s.c_str());
            }break;
            case 10:{
                cin.ignore();
                cout << "Nuevo estado (ACTIVO/INACTIVO): ";
                string s = cargarCadena();
                t.setEstado(s.c_str());
            }break;
            default: cout << "Opcion no valida." << endl; break;
        }
    }

    if(_archivo.guardar(pos, t)){
        cout << "Tarifa actualizada correctamente." << endl;
    }else{
        cout << "Error al guardar los cambios." << endl;
    }
}

void TarifaManager::listarTarifas()
{
    cout << "---- LISTADO DE TARIFAS ----" << endl;
    int cant = _archivo.getCantidadRegistros();
    for(int i=0; i<cant; ++i){
        Tarifa t = _archivo.leer(i);
        if(t.getIdTarifa() == -1) continue; // registro invalido
        mostrarTarifaEnConsola(t);
        cout << "-----------------------------" << endl;
    }
}
