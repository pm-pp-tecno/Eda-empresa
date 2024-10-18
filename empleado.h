#ifndef EMPLEADO_H
#define EMPLEADO_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empleado.h
// Modulo de Definición del empleado


typedef struct tipo_persona* Persona;
typedef struct tipo_empleado* Empleado;
typedef struct lista_empleados* ListaEmp;
typedef struct tipo_plantilla* Plantilla;


Empleado CrearEmpleado();
// Inicializa el empleado.

Plantilla CrearPlantilla();
// Inicializa la plantilla.

ListaEmp CrearListaEmpleados();
// Inicializa lista de empleados en un cargo.

#endif