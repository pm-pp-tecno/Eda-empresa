// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// cargo.c
// Modulo de Implementacion del Empleado

#include "cargo.h"
#include "empleado.h"
#include <cstring>
#include <iostream>

using namespace std;


struct tipo_cargo{
	Cadena nombreCargo;
	ListaEmp empleados;	// siempre apunta al ultimo de la lista
	//QueueEmp queueEmpleados;	// punteros a lista de empleados
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
	//ListaEmp empleados = CrearListaEmpleados(nuevo);
	ListaEmp empleados = NULL;
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


void MostrarCargo(Cargo cargo){
// Muestra el nombreCargo del cargo parametro
	if (cargo != NULL) 
		cout << " - "  << cargo->nombreCargo;
}

void MostrarListaCargos(ListaCargos listaCargo){
	// recursion con mostrarCargo, necesitamos un tail y head
	if(listaCargo != NULL){
		MostrarCargo(Head(listaCargo));
		MostrarListaCargos(Tail(listaCargo));
	}
}

Cadena ObtenerCargo(Cargo cargo){
// Muestra el nombreCargo del cargo parametro
	if (cargo != NULL) 
		return cargo->nombreCargo;
	else return NULL;
}

ListaEmp ObtenerListaEmpleadosCargo(Cargo cargo){
// Muestra la lista de empleados del cargo parametro
	if (cargo != NULL) 
		return cargo->empleados;
	else return NULL;
}


void InsertarEmpleadoListaEmpleados(Cargo &cargo, Empleado empleado){
	/*
	if (cargo->empleados == NULL){
		cargo->empleados = CrearListaEmpleados();
	}
	*/
	if (isEmptyListaEmpleados(cargo)){
		cargo->empleados = CrearListaEmpleados(empleado);
	} else {
		InsertarListaEmpleados(cargo, empleado);
	}
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


void ImprimirCargoListaEmp(Cargo cargo){
// Imprime la lista de empleados de una cargo
// PRE: cargo tiene una lista de empleados creada
	ListaEmp listaEmp = cargo->empleados;
	//QueueEmp queueEmpleados = cargo->queueEmpleados;
	if (listaEmp != NULL){
		Cadena formato = new char[20];
		strcpy(formato, "En linea");
		cout << "Empleados:\n";
		// Si solo hay 1 elemento
		if (Tail(listaEmp) == NULL){
			cout << "ImprimirCargoListaEmp (cargo.c) - Solo hay 1 elemento\n";		
			MostrarEmpleado(Head(listaEmp), formato);
		} else { // Hay mas de 1 elemento
			cout << "ImprimirCargoListaEmp (cargo.c) - Hay mas de 1 elemento\n";	
			ListaEmp iter = cargo->empleados; // ultimo de la lista
			while (iter != NULL){
				MostrarEmpleado(Head(iter), formato);
				iter = ListaAnt(iter);
			}
		}
	} else 
		cout << "Lista de empleados vacia.\n";
}


/*
QueueEmp OtenerQueue(Cargo cargo){
	return cargo->queueEmpleados;
}
*/


Cargo Head(ListaCargos listaCargo){
	return listaCargo->cargo;
}

ListaCargos Tail(ListaCargos listaCargo){
	return listaCargo->sig;
}

ListaEmp Ultimo(Cargo cargo){
// Retorna el ultimo nodo de la lista de empleados.
// Pre: cargo no vacio.
	return cargo->empleados;
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
void EliminarListaCargos(ListaCargos &listaCargos){
//Post: ELimina las listasCargo de una empresa
	while(listaCargos->ant != NULL){ //Retrocede al primer elem. ListaCargos
		listaCargos = listaCargos->ant;
	}
	while(listaCargos != NULL){
		ListaCargos aux = listaCargos;
		//Cargos cargo = listaCargos;
		EliminarListaEmpleados(listaCargos->cargo->empleados); // obtener listaEmp del cargo

		//delete aux->cargo->queueEmpleados;
		delete aux->cargo->nombreCargo;
		//delete aux->cargo;
		//delete aux->padre;
		listaCargos = listaCargos->sig;
		delete aux;
	}
}


void EliminarEmpleadoListaEmpleadosCargo(Cargo &cargo, Cadena ci){
	//ListaEmp listaEmp = cargo->empleados;
	cargo->empleados = EliminarEmpleadoListaEmpleados(cargo->empleados, ci);
}




void ActualizarCargoListaEmp(Cargo &cargo, ListaEmp nuevo){
	//ListaEmp empleados = ObtenerListaEmpleadosCargo(cargo);
	cargo->empleados = ActualizarListaEmp(cargo->empleados, nuevo);

}

