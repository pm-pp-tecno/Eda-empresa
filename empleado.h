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


typedef struct tipo_planilla* Planilla;



Empleado CrearEmpleado();
// Inicializa el empleado.


Planilla CrearPlanilla();
// Inicializa la planilla.

#endif