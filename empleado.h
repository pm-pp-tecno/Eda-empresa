#ifndef EMPLEADO_H
#define EMPLEADO_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empleado.h
// Modulo de Definición del empleado

#include "definiciones.h"

typedef struct tipo_cargo* Cargo;

typedef struct tipo_persona* Persona;
typedef struct tipo_empleado* Empleado;
typedef struct lista_empleados* ListaEmp;
typedef struct queue_empleados* QueueEmp;
typedef struct tipo_plantilla* Plantilla;

Persona CrearPersona(Cadena nom, Cadena ci);

Empleado CrearEmpleado(Persona persona, Cargo cargo);
// Inicializa el empleado.

Plantilla CrearPlantilla(Empleado empleado);
// Inicializa la plantilla.

ListaEmp CrearListaEmpleados(Empleado primerEmpleado);
// Inicializa lista de empleados en un cargo.

void AsignarEmpleadoPlantilla(Plantilla &plantilla, Empleado empleado);

void InsertarListaEmpleados(Cargo &cargo, Empleado empleado);

void MostrarEmpleado(Empleado empleado, Cadena Formato);
// Imprime los datos del empleado con el formato Formato

bool BuscarEmpleadoPlantilla(Plantilla plantilla, Cadena ci);

Empleado ObtenerEmpleadoPlantilla(Plantilla plantilla, Cadena ci);

bool EliminarEmpleadoPlantilla(Plantilla &plantilla, Cadena ci);

bool EliminarEmpleadoListaEmpleados(ListaEmp &listaEmp, Cadena ci);

bool EliminarEmpleado(Empleado &empleado);

bool isEmptyListaEmpleados(Cargo cargo);

Empleado Head(ListaEmp empleados);

ListaEmp Tail(ListaEmp empleados);

ListaEmp ListaAnt(ListaEmp empleados);

ListaEmp Primero(QueueEmp queueEmpleados);

ListaEmp Ultimo(QueueEmp queueEmpleados);


#endif