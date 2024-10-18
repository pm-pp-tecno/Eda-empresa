// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empresa.c
// Modulo de Implementacion de la Empresa

#include "cargo.h"
#include "empresa.h"
#include "organigrama.h"

#include <cstring>
#include <iostream>

using namespace std;

/*
struct arbol_emp{
	Cargo cargo;
	ArbolEmp ph;
	ArbolEmp sh;
};
*/

struct nodo_empresa{
	Cadena nombreEmp;			// nombre de la empresa
	ArbolEmp organigrama;       // organigrama (arbol) de la empresa
	Plantilla plantilla;        // lista de empleados de la empresa
	ListaCargos listaCargos;    // lista de cargos de la empresa
};




/**
 * 
 * 
 * FUNCIONES OBLIGATORIO
 * 
 * 
 */

TipoRet CrearOrg(Empresa &e, Cadena cargo){
// Inicializa la empresa y crea el primer cargo de la empresa.
// Originalmente la misma debería  estar vacía, en otro caso la operación quedará sin efecto.
	if (e != NULL){
		cout << " - ERROR: para ejecutar el comando el organigrama NO debe estar creado.\n";
		return ERROR;
	} else {
		e = new(nodo_empresa);
		
		// Nombre de la empresa
		Cadena nombreEmpresa = "EDA Empresa";
		Cadena nombreEmp = new char[strlen(nombreEmpresa) + 1];
		strcpy(e->nombreEmp, nombreEmp);

		// Plantilla general ordenada de empleados de la empresa
		e->plantilla = CrearPlantilla();


		// Crea el primer cargo con una lista de empleados NULL
		Cargo primerCargo = CrearCargo(cargo);

		// Se genera la lista de cargos en orden alfabetico
		ListaCargos listaCargos = CrearListaCargos();
		
		// padre seria NULL
		InsertarCargoOrdenado(listaCargos, NULL, primerCargo);

		// otra opcion es usar InsertarCargoOrganigrama
		CrearOrganigrama(primerCargo);
		
		return OK;
	}
}

TipoRet EliminarOrg(Empresa &e){
// Eliminar el organigrama, elimina toda la estructura del organigrama, liberando la memoria asignada.
	return NO_IMPLEMENTADA;
}

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo){
// Insertar un nuevo cargo como dependiente de otro ya existente.
// El nuevo cargo no debe existir en el sistema.
	if (e == NULL){
		cout << " - ERROR: La empresa no está creada.\n";
        return ERROR;
	}

	Cargo padre = BuscarCargo(e->listaCargos, cargoPadre);
	Cargo nuevo = BuscarCargo(e->listaCargos, nuevoCargo);

	// Si el padre existe y el nuevo cargo no existe
	if (padre != NULL && nuevo == NULL){

		nuevo = CrearCargo(nuevoCargo);
		InsertarCargoOrdenado(e->listaCargos, padre, nuevo);
		InsertarCargoOrganigrama(&e->organigrama, padre, nuevo);
		
		return OK;
	} else if (padre == NULL) {
		cout << " - ERROR: El padre no existe.\n";
		return ERROR;
	} else  {
		cout << " - ERROR: Ese cargo ya existe.\n";
		return ERROR;
	}
}


TipoRet EliminarCargo(Empresa &e, Cadena cargo){
// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.
	return NO_IMPLEMENTADA;
}

TipoRet ListarCargosAlf(Empresa e){
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo. 
	return NO_IMPLEMENTADA;
}

TipoRet ListarJerarquia(Empresa e){
// Listar todos los cargos de la empresa en orden jerárquico. 
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra. 
	return NO_IMPLEMENTADA;
}

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci){
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no este asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.
	return NO_IMPLEMENTADA;
}

TipoRet EliminarPersona(Empresa &e, Cadena ci){
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.
	return NO_IMPLEMENTADA;
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci){
// Reasignar una persona a un nuevo cargo.
// Reasigna una persona de la empresa de cédula ci al nuevo cargo de nombre cargo
// siempre que el cargo exista en la empresa y esa persona no este ya asignada a
// dicho cargo. En caso contrario la operación quedará sin efecto.
	return NO_IMPLEMENTADA;
}

TipoRet ListarPersonas(Empresa e, Cadena cargo){
// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa. 
// Lista todas las personas asignadas al cargo de nombre cargo. 
	return NO_IMPLEMENTADA;
}

TipoRet ListarSuperCargos (Empresa e, Cadena cargo){
// Dado un cargo listar los cargos que lo anteceden.
// Lista todas los cargos que anteceden, en la jerarquía, al cargo de nombre cargo.
	return NO_IMPLEMENTADA;
}

