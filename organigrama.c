
// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// organigrama.c
// Modulo de Implementacion del organigrama

#include "organigrama.h"
#include <cstring>
#include <iostream>


using namespace std;

struct arbol_emp{
	Cargo cargo;
	ArbolEmp ph;
	ArbolEmp sh;
};


ArbolEmp CrearOrganigrama(Cargo primerCargo){
// crea el organigrama con el primer cargo

	ArbolEmp nuevoArbolEmp = new(arbol_emp);
	/*
    nuevo->cargo = new char[strlen(primerCargo->nombreCargo) + 1];
	strcpy(nuevo->cargo, nuevoCargo);
    */
    nuevoArbolEmp->cargo = primerCargo;
	nuevoArbolEmp->ph = NULL;
	nuevoArbolEmp->sh = NULL;
	return nuevoArbolEmp;
}



void InsertarCargoOrganigrama(ArbolEmp &organigrama, Cargo cargoPadre, Cargo nuevoCargo){
// inserta el nuevoCargo como el primer hijo de cargoPadre


    /*

    //Creacion del arbol jerarquico
    ArbolEmp arbolCargos = new(arbol_emp);
    arbolCargos->cargo = cargo;
    arbolCargos->empleados = empleados;
    arbolCargos->ph = NULL;
    arbolCargos->sh = NULL;
    e->arbolCargos = arbolCargos;

    // Actualizo tambien la lista de cargos en orden alfabetico

    // e->listaCargos




    Empleado empleados = CrearEmpleado();

    ArbolEmp organigrama = crearOrganigrama(primerCargo);
    CrearArbolEmp(Cadena nuevoCargo)
    
    // Creacion del arbol jerarquico
    ArbolEmp arbolCargos = new(arbol_emp);
    arbolCargos->cargo = cargo;
    arbolCargos->empleados = empleados;
    arbolCargos->ph = NULL;
    arbolCargos->sh = NULL;
    e->arbolCargos = arbolCargos;







    */

}