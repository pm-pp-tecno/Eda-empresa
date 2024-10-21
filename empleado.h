#ifndef EMPLEADO_H
#define EMPLEADO_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empleado.h
// Modulo de Definición del empleado

#include "cargo.h"
#include "definiciones.h"


typedef struct tipo_persona* Persona;
typedef struct tipo_empleado* Empleado;
typedef struct lista_empleados* ListaEmp;
typedef struct tipo_plantilla* Plantilla;

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

Persona CrearPersona(Cadena nom, Cadena ci);

Empleado CrearEmpleado(Persona persona, Cargo cargo);
// Inicializa el empleado.

Plantilla CrearPlantilla(Empleado empleado);
// Inicializa la plantilla.

ListaEmp CrearListaEmpleados();
// Inicializa lista de empleados en un cargo.

void AsignarEmpleadoPlantilla(Plantilla &plantilla, Empleado empleado);

void InsertarListaEmpleados(ListaEmp &empleados, Empleado empleado);

void MostrarEmpleado(Empleado empleado, Cadena Formato);
// Imprime los datos del empleado con el formato Formato

bool BuscarEmpleadoPlantilla(Plantilla plantilla, Cadena ci);

Empleado ObtenerEmpleadoPlantilla(Plantilla plantilla, Cadena ci);

bool EliminarEmpleadoPlantilla(Plantilla &plantilla, Cadena ci);

bool EliminarEmpleadoListaEmpleados(ListaEmp &listaEmp, Cadena ci);


Empleado Head(ListaEmp empleados);

ListaEmp Tail(ListaEmp empleados);

ListaEmp ListaAnt(ListaEmp empleados);

ListaEmp Ultimo(ListaEmp empleados);


#endif