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
	ListaCargos sig;
	ListaCargos ant;
};



bool isEmptyListaCargos(ListaCargos listaCargos){
	return listaCargos == NULL;
}

// Crea el cargo a partir de la cadena nuevoCargo
Cargo CrearCargo(Cadena nuevoCargo){
	Cargo nuevo = new(tipo_cargo);
	nuevo->nombreCargo = new char[strlen(nuevoCargo) + 1];
	strcpy(nuevo->nombreCargo, nuevoCargo);
	//nuevo->nombreCargo = nuevoCargo;
	cout << "Creando Cargo en CrearCargo (cargo.c). nuevo->nombreCargo: " << nuevo->nombreCargo << "\n";
	

	// Lista de empleados en el cargo
	ListaEmp empleados = CrearListaEmpleados();
	nuevo->empleados = empleados;
	return nuevo;
}


Cargo BuscarCargo(ListaCargos listaCargos, Cadena cargo){
// Buscar el cargo en la lista de cargos
	//cout << "BuscarCargo (cargo.c).\n";
	while (listaCargos != NULL){
		//cout << "BuscarCargo (cargo.c). Distinta de NULL\n";
		cout << "BuscarCargo (cargo.c). listaCargos->cargo->nombreCargo: " << listaCargos->cargo->nombreCargo << ".\n";
		if (strcasecmp(listaCargos->cargo->nombreCargo, cargo) == 0){
			cout << "BuscarCargo (cargo.c). Encontre el cargo!!.\n";
			return listaCargos->cargo;
		}else{
			listaCargos = listaCargos->sig;
		}
	}
	return NULL;
}

ListaCargos CrearListaCargos(Cargo primerCargo){
// Inicializa la lista de cargos.

	ListaCargos nuevoLC = new(lista_cargos);
	nuevoLC->cargo = primerCargo;
	nuevoLC->padre = NULL;
	nuevoLC->sig = NULL;
	nuevoLC->ant = NULL;

	cout << "(cargo.c - CrearListaCargos). nuevoLC->cargo->nombreCargo: " << nuevoLC->cargo->nombreCargo  << ".\n";

	return nuevoLC;
}

void InsertarCargoOrdenado(ListaCargos &listaCargos, Cargo cargoPadre, Cargo nuevoCargo){
	// Insercion en lista ordenada
	// PRE: listaCargos no es vacia
	// PRE: nuevoCargo NO existe y cargoPadre SI existe en la lista

	cout << "Insertando el cargo (cargo.c - InsertarCargoOrdenado):\nnuevoCargo->nombreCargo: " << nuevoCargo->nombreCargo  << ".\n";
	
	ListaCargos nuevoLC = new(lista_cargos);
	nuevoLC->cargo = nuevoCargo;
	cout << "(cargo.c - InsertarCargoOrdenado). nuevoLC->cargo: " << nuevoLC->cargo->nombreCargo  << ".\n";
/*
	if (isEmptyListaCargos(listaCargos)){
		cout << "Lista de cargos vacia (cargo.c). Sig y Ant son NULL\n";
		nuevoLC->sig = NULL;
		nuevoLC->ant = NULL;
		listaCargos->cargo = nuevoLC->cargo;
		listaCargos->padre = nuevoLC->padre;
	} else {
*/
	cout << "Lista de cargos NO vacia (cargo.c).\n";
	if (strcasecmp(listaCargos->cargo->nombreCargo, nuevoCargo->nombreCargo) > 0) {
		// si es mayor que 0 significa el nuevo cargo va primero
		nuevoLC->sig = listaCargos;
		listaCargos->ant = nuevoLC;
		listaCargos = nuevoLC;
	} else {

		ListaCargos actual = listaCargos;
		// en este caso avanzamos hasta encontrar el ultimo cargo o encontrar uno que sea mayor
		// de forma alfabetica al nuevoCargo
		while (actual->sig != NULL && strcasecmp(actual->sig->cargo->nombreCargo, nuevoCargo->nombreCargo) < 0) {
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
	} 
	//}
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