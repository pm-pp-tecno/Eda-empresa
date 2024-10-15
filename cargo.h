#ifndef EMPLEADO_H
#define EMPLEADO_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empleado.h
// Modulo de Definición del empleado



typedef tipo_cargo* Cargo;



Cargo CrearCargo();
// Inicializa el cargo.

Cargo buscar_cargo(Cargo listaCargos, Cadena cargo);
// Buscar el cargo en la lista de cargos
