// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// cargo.c
// Modulo de Implementacion del Empleado

#include "empleado.h"
#include "cargo.h"
#include <cstring>
#include <iostream>

using namespace std;


struct tipo_cargo{
	Cadena nombreCargo;
	ListaEmp empleados;
};


struct lista_cargos{
	Cargo cargo;
	Cargo padre;
	ListaCargo sig;
	ListaCargo ant;
};



ArbolEmp CrearCargo(Cadena nuevoCargo, Cadena cargoPadre){
// crea el nuevo cargo.
	Cargo nuevo = new(tipo_cargo);
	nuevo->cargo = nuevoCargo;
	nuevo->padre = cargoPadre;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	return nuevo;
}


Cargo buscar_cargo(Cargo listaCargos, Cadena cargo){
// Buscar el cargo en la lista de cargos
	while (listaCargos != NULL){
		if (strcasecmp(listaCargos->cargo, cargo) == 0){
			return listaCargos;
		}else{
			listaCargos = listaCargos->sig;
		}
	}
	return NULL;
}

void insertarCargoOrdenado(Cargo &listaCargos, Cadena cargoPadre, Cadena nuevoCargo){
	return NULL; //en un principio
}