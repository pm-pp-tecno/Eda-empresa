#ifndef CARGO_H
#define CARGO_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// cargo.h
// Modulo de Definición del cargo

typedef struct tipo_cargo* Cargo;

Cargo CrearCargo();
// Inicializa el cargo.

Cargo buscar_cargo(Cargo listaCargos, Cadena cargo);
// Buscar el cargo en la lista de cargos

void insertarCargoOrdenado(Cargo &listaCargos, Cadena cargoPadre, Cadena nuevoCargo);
// Inserta el nuevo cargo de forma ordenada en la listaCargos

#endif