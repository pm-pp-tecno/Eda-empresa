// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empleado.c
// Modulo de Implementacion del Empleado

#include "empleado.h"
#include "cargo.h"
#include <cstring>
#include <iostream>

using namespace std;

struct tipo_persona{
	Cadena ci;
	Cadena nom;
};

struct tipo_empleado{
	Persona persona;
	Cadena alta;
	Cargo cargo;
};

// Lista de empleados de un CARGO
struct lista_empleados{
	Empleado empleado;
	ListaEmp sig;
	ListaEmp ant;
	ListaEmp ult; // ultimo elemento de la lista. Solo se actualiza el 1er elemento
};

// Plantilla general de empleados en la empresa
// Lista ordenada contiene a todos los empleados
struct tipo_plantilla{
	Empleado empleado;
	Plantilla sig;
	Plantilla ant;
};



Empleado CrearEmpleado(){
// Inicializa el empleado.
	return NULL;
}

Plantilla CrearPlantilla(){
// Inicializa la plantilla.
	return NULL;
}

ListaEmp CrearListaEmpleados(){
// Inicializa el empleado.
	return NULL;
}


void MostrarEmpleado(Empleado empleado, Cadena formato){
// Imprime los datos del empleado con el formato Formato
	if (empleado != NULL) {
		/*
		switch (formato):
			case "En linea":
				cout << empleado->persona->ci << "-";
				cout << empleado->persona->nom << "-";
				cout << empleado->persona->alta << "\n";
			break;
			case "Otro formato":
				cout << empleado->persona->ci << "-";
				cout << empleado->persona->nom << "-";
				cout << empleado->persona->alta << "\n";
			break;
		*/
		cout << empleado->persona->ci << "-";
		cout << empleado->persona->nom << "-";
		cout << empleado->alta << "\n";

	}
}


Empleado Head(ListaEmp empleados){
// Retorna el primer elemento de la lista.
// Pre: l no vacia.
	return empleados->empleado;
}

ListaEmp Tail(ListaEmp empleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return empleados->sig;
}


ListaEmp ListaAnt(ListaEmp empleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return empleados->ant;
}


ListaEmp Ultimo(ListaEmp empleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return empleados->ult;
}

/*
void ImprimirListaEmp(ListaEmp empleados){
	if (empleados != NULL){
		cout<< empleados->ult->empleado->persona->ci << "-" <<  empleados->ult->empleado->persona->nom << "-" << empleados->ult->empleado->alta << "\n";
	}
	ImprimirListaEmp (empleados->ant);
}
*/

