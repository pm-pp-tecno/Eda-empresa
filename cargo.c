// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// cargo.c
// Modulo de Implementacion del Empleado

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



bool isEmptyListaCargos(listaCargos){
	return listaCargos == NULL;
}

// Crea el cargo a partir de la cadena nuevoCargo
Cargo CrearCargo(Cadena nuevoCargo){
	Cargo nuevo = new(tipo_cargo);
	nuevo->nombreCargo = new char[strlen(nuevoCargo) + 1];
	strcpy(nuevo->nombreCargo, nuevoCargo);

	// Lista de empleados en el cargo
	ListaEmp empleados = CrearListaEmpleados();
	nuevo->empleados = empleados;
	return nuevo;
}


ListaCargos CrearListaCargos(){
// Inicializa la plantilla.
	return NULL;
}




void InsertarCargoOrdenado(ListaCargos &listaCargos, Cargo nuevoCargo, Cargo cargoPadre){
	// Insercion en lista ordenada
	// PRE: nuevoCargo NO existe y cargoPadre SI existe en la lista
	
	ListaCargos nuevoLC = new(lista_cargos);
	nuevoLC->cargo = nuevoCargo;
	nuevoLC->padre = cargoPadre;

	if (isEmptyListaCargos(listaCargos)){
		nuevoLC->sig = NULL;
		nuevoLC->ant = NULL;
	} else {

		if (strcasecmp(listaCargos->cargo->nombreCargo, nuevoCargo) > 0) {
			// si es mayor que 0 significa el nuevo cargo va primero
			nuevoLC->sig = listaCargos;
			listaCargos->ant = nuevoLC;
			listaCargos = nuevoLC;
		} else {

			ListaCargos actual = listaCargos;
			// en este caso avanzamos hasta encontrar el ultimo cargo o encontrar uno que sea mayor
			// de forma alfabetica al nuevoCargo
			while (actual->sig != NULL && strcasecmp(actual->sig->cargo->nombreCargo, nuevoCargo) < 0) {
				// lo que quiere decir < 0 es que el nombreCargo empieza con una letra
				// que se ubica antes que la primera letra de nuevoCargo en el alfabeto
				// por eso lo recorre hasta encontrar uno que lo supere, entonces va delante de ese
				actual = actual->sig;
			}
			nuevoLC->sig = actual->sig;
			if (actual->sig != NULL) {
				actual->sig->ant = nuevoLC;
			}
			actual->sig = nuevoLC;
			nuevoLC->ant = actual;
			
			return OK;
		} else if (padre == NULL) {
			cout << " - ERROR: El padre no existe.\n";
			return ERROR;
		} else  {
			cout << " - ERROR: Ese cargo ya existe.\n";
			return ERROR;
		}
	
	}
	
}

/*
ListaCargos BuscarListaCargo(Cargo listaCargos, Cadena cargo){
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
*/

Cargo BuscarCargo(ListaCargos listaCargos, Cadena cargo){
// Buscar el cargo en la lista de cargos
	while (listaCargos != NULL){
		if (strcasecmp(listaCargos->cargo, cargo) == 0){
			return listaCargos->cargo;
		}else{
			listaCargos = listaCargos->sig;
		}
	}
	return NULL;
}

/*
Cargo buscar_cargo(ListaCargos listaCargos, Cadena cargo) {
    while (listaCargos != NULL) {
        if (strcasecmp(listaCargos->cargo->nombreCargo, cargo) == 0) {
            return listaCargos->cargo;
        }
        listaCargos = listaCargos->sig;
    }
    return NULL;
}
*/