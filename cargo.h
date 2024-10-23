#ifndef CARGO_H
#define CARGO_H

#include "definiciones.h"
#include "empleado.h"

typedef struct tipo_cargo* Cargo;
typedef struct lista_cargos* ListaCargos;

Cargo CrearCargo(Cadena nuevoCargo);
// Crea un nuevo cargo a partir de una cadena

Cargo BuscarCargo(ListaCargos listaCargos, Cadena cargo);
// Buscar el cargo en la lista de cargos

void MostrarCargo(Cargo cargo);
// Muestra el nombreCargo del cargo parametro

void InsertarCargoOrdenado(ListaCargos &listaCargos, Cargo cargoPadre, Cargo nuevoCargo);
// Inserta el nuevo cargo de forma ordenada en la listaCargos

void InsertarEmpleadoListaEmpleados(Cargo &cargo, Empleado empleado);

void ImprimirCargoListaEmp(Cargo cargo);
// Imprime la lista de empleados de una cargo
// PRE: cargo tiene una lista de empleados creada

/*
void mostrarListaCargos(ListaCargos listaCargos);
// Imprime la lista de Cargo ordenada
*/

bool isEmptyListaCargos(ListaCargos listaCargos);

ListaCargos CrearListaCargos(Cargo primerCargo);

Cadena ObtenerCargo(Cargo cargo);

ListaEmp ObtenerListaEmpleadosCargo(Cargo cargo);

void MostrarListaCargos(ListaCargos listaCargo);

//QueueEmp OtenerQueue(Cargo cargo);

Cargo Head(ListaCargos listaCargo);

ListaCargos Tail(ListaCargos listaCargo);

ListaEmp Ultimo(Cargo cargo);

void EliminarListaCargos(ListaCargos &listaCargos);

void ActualizarCargoListaEmp(Cargo &cargo, ListaEmp nuevo);

#endif // CARGO_H