// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empresa.c
// Modulo de Implementacion de la Empresa

#include "empresa.h"
#include "empleado.h"
#include "cargo.h"
#include <cstring>
#include <iostream>

using namespace std;


typedef arbol_emp* ArbolEmp;

struct arbol_emp{
	Cargo cargo;
	ArbolEmp ph;
	ArbolEmp sh;
};


struct nodo_empresa{
	// aquí deben figurar los campos que usted considere necesarios para manipular el organigrama.
	// Se deberan crear nuevos modulos e incluirlos.
	Cadena nombreEmp;
	ArbolEmp organigrama;
	Plantilla plantilla;
	ListaCargos listaCargos;
};

TipoRet CrearOrg(Empresa &e, Cadena cargo){
// Inicializa la empresa y crea el primer cargo de la empresa.
// Originalmente la misma debería  estar vacía, en otro caso la operación quedará sin efecto.
	if (e != NULL){
		cout << " - ERROR: para ejecutar el comando el organigrama NO debe estar creado.\n";
		return ERROR;
	} else {
		e = new(nodo_empresa);
		
		// Nombre de la empresa
		Cadena nombreEmp = new(char*[100]);
		nombreEmp = "EDA Empresa";
		e->nombreEmp = nombreEmp;

		// Plantilla general ordenada de empleados de la empresa
		//Plantilla plantilla = new(tipo_plantilla);
		/*
		Plantilla plantilla = CrearPlantilla();
		e->plantilla = plantilla;
		*/
		e->plantilla = CrearPlantilla();

		// Se genera la lista de cargos en orden alfabetico
		//Cargo listaCargos = new(tipo_cargo);
		/*
		Cargo listaCargos = CrearCargo(cargo);

		e->listaCargos = listaCargos;
		*/
		e->listaCargos = CrearCargo(cargo, NULL);

		// Empleados en un cargo
		//Empleado empleados = new(tipo_empleado);
		Empleado empleados = CrearEmpleado();

		ArbolEmp arbolCargos = crearOrganigrama(&empleados);
		
		// Creacion del arbol jerarquico
		ArbolEmp arbolCargos = new(arbol_emp);
		arbolCargos->cargo = cargo;
		arbolCargos->empleados = empleados;
		arbolCargos->ph = NULL;
		arbolCargos->sh = NULL;
		e->arbolCargos = arbolCargos;
		
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
	
	//Busquedas en funciones auxiliares
	Cargo padre = buscar_cargo(e->listaCargos, cargoPadre);
	Cargo cargo = buscar_cargo(e->listaCargos, nuevoCargo);
	
	if (padre != NULL && cargo == NULL){

		insertarCargoOrdenado(&e->listaCargos, cargoPadre, nuevoCargo);
		insertarOrganigrama(&e->listaCargos, cargoPadre, nuevoCargo);
		/*
		Dentro de insertarOrganigrama
		//Empleados en un cargo
		Empleado empleados = new(tipo_empleado);
		
		//Creacion del arbol jerarquico
		ArbolEmp arbolCargos = new(arbol_emp);
		arbolCargos->cargo = cargo;
		arbolCargos->empleados = empleados;
		arbolCargos->ph = NULL;
		arbolCargos->sh = NULL;
		e->arbolCargos = arbolCargos;

		// Actualizo tambien la lista de cargos en orden alfabetico

		// e->listaCargos

		typedef tipo_cargo* Cargo;
		struct tipo_cargo{
			Cadena cargo;
			Cadena padre;
			Cargo sig;
			Cargo ant;
		};
		*/
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
