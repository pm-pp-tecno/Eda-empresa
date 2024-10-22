// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empleado.c
// Modulo de Implementacion del Empleado

#include "cargo.h"
#include "empleado.h"

#include <cstring>
#include <iostream>

using namespace std;

/* struct tipo_persona{
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
}; */

Persona CrearPersona(Cadena nom, Cadena ci){
	Persona nuevaPersona = new(tipo_persona);
	nuevaPersona->nom = new char[strlen(nom) + 1];
	strcpy(nuevaPersona->nom, nom);
	nuevaPersona->ci = new char[strlen(ci) + 1];
	strcpy(nuevaPersona->ci, ci);
	return nuevaPersona;
}

Empleado CrearEmpleado(Persona persona, Cargo cargo){
	Empleado nuevoEmpleado = new(tipo_empleado);
	nuevoEmpleado->persona = persona;
	nuevoEmpleado->cargo = cargo;
	nuevoEmpleado->alta = new char[10];
	strcpy(nuevoEmpleado->alta, "10/04/2024");
	return nuevoEmpleado;
}

Plantilla CrearPlantilla(Empleado empleado){
	Plantilla nuevaPlantilla = new(tipo_plantilla);
	nuevaPlantilla->empleado = empleado;
	nuevaPlantilla->sig = NULL;
	nuevaPlantilla->ant = NULL;
    return nuevaPlantilla;
}

void AsignarEmpleadoPlantilla(Plantilla &plantilla, Empleado empleado){
    Plantilla recorre = plantilla;
	cout << "AsignarEmpleadoPlantilla (empleado.c)\n";
	Cadena formato = new char[20];
	strcpy(formato, "En linea");
    while (recorre->sig != NULL){
		MostrarEmpleado(plantilla->empleado, formato);
        recorre = recorre->sig;
    }
    Plantilla nuevoEmpleado = new(tipo_plantilla);
    nuevoEmpleado->empleado = empleado;
    nuevoEmpleado->sig = NULL;
    nuevoEmpleado->ant = recorre;
    recorre->sig = nuevoEmpleado;
}

ListaEmp CrearListaEmpleados(){
    return NULL;
}

void InsertarListaEmpleados(ListaEmp &empleados, Empleado empleado){
    if (empleados == NULL){
        ListaEmp nuevaListaEmpleados = new(lista_empleados);
        nuevaListaEmpleados->empleado = empleado;
        nuevaListaEmpleados->sig = NULL;
        nuevaListaEmpleados->ant = NULL;
        nuevaListaEmpleados->ult = nuevaListaEmpleados;
		empleados = nuevaListaEmpleados;
    }else{
        ListaEmp ultimo = empleados->ult;
        ListaEmp nuevo = new(lista_empleados);
        nuevo->empleado = empleado;
        nuevo->sig = NULL;
        nuevo->ant = ultimo;
        ultimo->sig = nuevo;
        empleados->ult = nuevo;
    }
}



void MostrarEmpleado(Empleado empleado, Cadena formato){
// Imprime los datos del empleado con el formato Formato
	if (empleado != NULL) {
		/*
		switch (formato):
			case "En linea":
				cout << empleado->persona->ci << "-";
				cout << empleado->persona->nom << "-";
				cout << empleado->persona->alta << "\n";
			break;
			case "Otro formato":
				cout << empleado->persona->ci << "-";
				cout << empleado->persona->nom << "-";
				cout << empleado->persona->alta << "\n";
			break;
		*/
		cout << empleado->persona->ci << " -";
		cout << empleado->persona->nom << " - ";
		cout << empleado->alta << "\n";

	}
}


bool BuscarEmpleadoPlantilla(Plantilla plantilla, Cadena ci){
	bool encontre = false;
	while (plantilla != NULL && !encontre) {
		Cadena formato = new char[20];
		strcpy(formato, "En linea");
		MostrarEmpleado(plantilla->empleado, formato);
		if (strcmp(plantilla->empleado->persona->ci, ci) == 0) {
			encontre = true;
		} else {
			plantilla = plantilla->sig;
		}
	}
	return encontre;
}


Empleado ObtenerEmpleadoPlantilla(Plantilla plantilla, Cadena ci){
	Empleado empleado = NULL;
	bool encontre = false;
	cout << "ObtenerEmpleadoPlantilla (empleado.c):\n";
	cout << "Buscando empleado en Plantilla...\n";
	
	while (plantilla != NULL && !encontre) {
		Cadena formato = new char[20];
		strcpy(formato, "En linea");
		//MostrarEmpleado(plantilla->empleado, formato);
		if (strcmp(plantilla->empleado->persona->ci, ci) == 0) {
			encontre = true;
			cout << "Empleado encontrado!: ";
			MostrarEmpleado(plantilla->empleado, formato);
			return plantilla->empleado;
		} else {
			plantilla = plantilla->sig;
		}
	}
	return empleado;
}



bool EliminarEmpleadoPlantilla(Plantilla &plantilla, Cadena ci){
	bool encontre = false;
	cout << "EliminarEmpleadoPlantilla (empleado.c) - Elimino empleado de la Plantilla:\n";
	cout << "Buscando empleado en Plantilla...\n";

	Plantilla iter = plantilla;

	while (iter != NULL && !encontre) {
		Cadena formato = new char[20];
		strcpy(formato, "En linea");
		MostrarEmpleado(iter->empleado, formato);
		if (strcmp(iter->empleado->persona->ci, ci) == 0) {
			

			Empleado empleado = iter->empleado;
			//EliminarEmpleado(empleado);
			
			// Solo hay 1 elemento
			if (iter->ant == NULL && iter->sig == NULL){
				cout << "Elimino solo 1 elemento. Plantilla vacia\n";
				plantilla = NULL;
				delete iter;
			} else { // + de 1 elemento
				cout << "Hay mas de 1 elemento en la Plantilla\n";
				Plantilla aux = iter;
				
				// Es el primer elemento
				if (iter == plantilla){
					// Actualizo el puntero principal a la Plantilla
					plantilla = iter->sig;
					plantilla->ant = NULL;
				} else {
					iter->ant->sig = iter->sig;

					if (iter->sig != NULL){
						iter->sig->ant = iter->ant;
					}

				}

				delete aux;
			}

			encontre = true;
		} else {
			iter = iter->sig;
		}
	}
	return encontre;
}



bool EliminarEmpleadoListaEmpleados(ListaEmp &listaEmp, Cadena ci){
// Elimina un empleado de una lista de empleados
	bool encontre = false;
	Cadena formato = new char[20];
	strcpy(formato, "En linea");
	cout << "EliminarEmpleadoListaEmpleados (empleado.c) - Empleado a eliminar:\n";

	ListaEmp iter = listaEmp;

	while (iter != NULL && !encontre) {

		//MostrarEmpleado(iter->empleado, formato);
		if (strcmp(iter->empleado->persona->ci, ci) == 0) {
			
			Empleado empleado = iter->empleado;
			//EliminarEmpleado(empleado);
			
			// Solo hay 1 elemento
			if (iter->ant == NULL && iter->sig == NULL){
				cout << "Elimino solo 1 elemento. Lista vacia\n";
				listaEmp = NULL;
				delete iter;
			} else { // + de 1 elemento
				cout << "Hay mas de 1 elemento en la lista\n";
				ListaEmp aux = iter;
				
				// Es el primer elemento
				if (iter == listaEmp){
					// Actualizo el puntero principal a la lista de empleados
					listaEmp = iter->sig;
					listaEmp->ant = NULL;
				} else {
					iter->ant->sig = iter->sig;

					if (iter->sig != NULL){
						iter->sig->ant = iter->ant;
					}

				}

				delete aux;
			}

			encontre = true;
		} else {
			iter = iter->sig;
		}
	}
	//cout << "Salgo de EliminarEmpleadoListaEmpleados\n";
	return encontre;
}


bool EliminarEmpleado(Empleado &empleado){
	bool elimine = false;
	if (empleado != NULL) {
		Cadena formato = new char[20];
		strcpy(formato, "En linea");
		cout << "Empleado eliminado: ";
		MostrarEmpleado(empleado, formato);
		
		delete empleado->persona->ci;
		delete empleado->persona->nom;
		delete empleado->persona;
		delete empleado->alta;
		delete empleado;

		elimine = true;
	} else
		cout << "El empleado no existe\n";
	return elimine;
}



Empleado Head(ListaEmp empleados){
// Retorna el primer elemento de la lista.
// Pre: l no vacia.
	return empleados->empleado;
}

ListaEmp Tail(ListaEmp empleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return empleados->sig;
}


ListaEmp ListaAnt(ListaEmp empleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return empleados->ant;
}


ListaEmp Ultimo(ListaEmp empleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return empleados->ult;
}

/*
void ImprimirListaEmp(ListaEmp empleados){
	if (empleados != NULL){
		cout<< empleados->ult->empleado->persona->ci << "-" <<  empleados->ult->empleado->persona->nom << "-" << empleados->ult->empleado->alta << "\n";
	}
	ImprimirListaEmp (empleados->ant);
}
*/

