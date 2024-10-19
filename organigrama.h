#ifndef ORGANIGRAMA_H
#define ORGANIGRAMA_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// cargo.h
// Modulo de Definición del cargo


#include "definiciones.h"
#include "cargo.h"
#include "empresa.h"

#include <cstring>
#include <iostream>


typedef struct arbol_emp* ArbolEmp;


ArbolEmp CrearOrganigrama(Cargo primerCargo);
// crea el organigrama con el primer cargo


void InsertarCargoOrganigrama(ArbolEmp &organigrama, Cargo cargoPadre, Cargo nuevoCargo);
// inserta el nuevoCargo como el primer hijo de cargoPadre en el organigrama

#endif