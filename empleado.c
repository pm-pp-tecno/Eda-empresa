// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empleado.c
// Modulo de Implementacion del Empleado

#include "empleado.h"
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
	ListaEmp ult;
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
