// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empleado.c
// Modulo de Implementacion del Empleado

#include "empleado.h"
#include <iostream>

using namespace std;


struct tipo_persona{
	Cadena ci;
	Cadena nom;
};


struct tipo_empleado{
	Persona persona;
	Cadena alta;
	Empleado sig;
	Empleado ant;
};


struct tipo_planilla{
	Persona persona;
	Cadena alta;
	Cadena cargo;
	Planilla sig;
	Planilla ant;
};


Empleado CrearEmpleado(){
// Inicializa el empleado.
	return NULL;
}


Planilla CrearPlanilla(){
// Inicializa la planilla.
	return NULL;
}
