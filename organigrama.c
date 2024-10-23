
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
    if (organigrama != NULL){
        Cadena nombreCargo = ObtenerCargo(nuevoCargo);
        Cadena nombrePadre = ObtenerCargo(cargoPadre);
        if (strcasecmp (nombreCargo, nombrePadre) == 0){ 
            ArbolEmp nuevo = new(arbol_emp);
            nuevo->cargo = nuevoCargo;
            nuevo->ph = NULL;
            nuevo->sh = organigrama->ph;
            organigrama->ph = nuevo;
        }
        else{
            InsertarCargoOrganigrama(organigrama->ph, cargoPadre, nuevoCargo);
            InsertarCargoOrganigrama(organigrama->sh, cargoPadre, nuevoCargo);
        }
    }
}


void EliminarArbolEmp(ArbolEmp &organigrama){
    if (organigrama != NULL){
        EliminarArbolEmp(organigrama->ph);
        EliminarArbolEmp(organigrama->sh);
        delete(organigrama);
        organigrama = NULL;
    }
}
