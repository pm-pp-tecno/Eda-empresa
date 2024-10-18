#ifndef CARGO_H
#define CARGO_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// cargo.h
// Modulo de Definición del cargo

#include "definiciones.h"
#include "empleado.h"
#include "empresa.h"

typedef struct tipo_cargo* Cargo;
typedef struct lista_cargos* ListaCargos;


Cargo CrearCargo(Cadena nuevoCargo);
// Crea un nuevo cargo a partir de una cadena

Cargo BuscarCargo(Cargo listaCargos, Cadena cargo);
// Buscar el cargo en la lista de cargos

void InsertarCargoOrdenado(ListaCargos &listaCargos, Cargo cargoPadre, Cargo nuevoCargo);
// Inserta el nuevo cargo de forma ordenada en la listaCargos

void mostrarListaCargos(ListaCargos listaCargos);
// Imprime la lista de Cargo ordenada

bool isEmptyListaCargos(ListaCargos listaCargos);

#endif // CARGO_H