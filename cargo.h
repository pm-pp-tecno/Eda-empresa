#ifndef CARGO_H
#define CARGO_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// cargo.h
// Modulo de Definición del cargo

#include "definiciones.h"
//#include "empleado.h"
//#include "empresa.h"

typedef struct lista_empleados* ListaEmp;

typedef struct tipo_cargo* Cargo;
typedef struct lista_cargos* ListaCargos;

struct tipo_cargo{
	Cadena nombreCargo;
	ListaEmp empleados;
};

struct lista_cargos{
	Cargo cargo;
	Cargo padre;
	ListaCargos sig;
	ListaCargos ant;
};


Cargo CrearCargo(Cadena nuevoCargo);
// Crea un nuevo cargo a partir de una cadena

Cargo BuscarCargo(ListaCargos listaCargos, Cadena cargo);
// Buscar el cargo en la lista de cargos

void MostrarCargo(Cargo cargo);
// Muestra el nombreCargo del cargo parametro

void InsertarCargoOrdenado(ListaCargos &listaCargos, Cargo cargoPadre, Cargo nuevoCargo);
// Inserta el nuevo cargo de forma ordenada en la listaCargos


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

#endif // CARGO_H