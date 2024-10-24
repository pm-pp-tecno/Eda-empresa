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
	//ListaEmp ult; // ultimo elemento de la lista. Solo se actualiza el 1er elemento
};


/*
// Punteros a primero y ultimo de lista de empleados de un CARGO
struct queue_empleados{
	ListaEmp pri; // ultimo elemento de la lista de empleados
	ListaEmp ult; // ultimo elemento de la lista de empleados
};
*/


// Plantilla general de empleados en la empresa
// Lista ordenada contiene a todos los empleados
struct tipo_plantilla{
	Empleado empleado;
	Plantilla sig;
	Plantilla ant;
};

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

ListaEmp CrearListaEmpleados(Empleado primerEmpleado){
	if (primerEmpleado != NULL){
		ListaEmp nuevaListaEmpleados = new(lista_empleados);
		nuevaListaEmpleados->empleado = primerEmpleado;
		nuevaListaEmpleados->sig = NULL;
		nuevaListaEmpleados->ant = NULL;
		return nuevaListaEmpleados;
	} else {
		return NULL;
	}

    
}

void InsertarListaEmpleados(Cargo &cargo, Empleado empleado){
// PRE: lista de empleados de cargo no esta vacia. Sino voy a crearLista con el primer empleo
// PRE: empleado no vacio

	// obtengo el puntero al ultimo, genero uno nuevo y actualizo queueEmp->ultimo;
	// tengo que chequear si no tengo que cambiar el primero tb.
	

	// cambiado temporalmente pq elimino empleados->ult;

	
	//QueueEmp queue = OtenerQueue(cargo);
	ListaEmp ultimo = Ultimo(cargo);

	ListaEmp nuevo = new(lista_empleados);
	nuevo->empleado = empleado;
	nuevo->sig = NULL;
	nuevo->ant = ultimo;
	nuevo->ant->sig = nuevo;

	ActualizarCargoListaEmp(cargo, nuevo);

	// Actualizo queue
	//queue->ult = ultimo;






	/*

	
	if (queueEmpleados == NULL){
        ListaEmp nuevaListaEmpleados = new(lista_empleados);
        nuevaListaEmpleados->empleado = empleado;
        nuevaListaEmpleados->sig = NULL;
        nuevaListaEmpleados->ant = NULL;
		empleados = nuevaListaEmpleados;
		
    }else{
        //ListaEmp ultimo = empleados->ult;
		

		// cambiado temporalmente pq elimino empleados->ult;
		ListaEmp ultimo = empleados;
        ListaEmp nuevo = new(lista_empleados);
        nuevo->empleado = empleado;
        nuevo->sig = NULL;
        nuevo->ant = ultimo;
        ultimo->sig = nuevo;
        //empleados->ult = nuevo;
    }

	*/
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

/*
Persona ObtenerPersona(Empleado empleado){
	return empleado->persona;
}

Cadena ObtenerAlta(Empleado empleado){
	return empleado->alta;
}
*/

Cargo ObtenerCargoEmpleado(Empleado empleado){
	return empleado->cargo;
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
			

			//Empleado empleado = iter->empleado;
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



ListaEmp EliminarEmpleadoListaEmpleados(ListaEmp &listaEmp, Cadena ci){
// Elimina un empleado de una lista de empleados
	bool encontre = false;
	Cadena formato = new char[20];
	strcpy(formato, "En linea");
	cout << "EliminarEmpleadoListaEmpleados (empleado.c):\n";

	ListaEmp iter = listaEmp;

	while (iter != NULL && !encontre) {

		//MostrarEmpleado(iter->empleado, formato);
		if (strcmp(iter->empleado->persona->ci, ci) == 0) {
			
			encontre = true;
			
			//Empleado empleado = iter->empleado;
			//EliminarEmpleado(empleado);
			
			// Solo hay 1 elemento
			if (iter->ant == NULL && iter->sig == NULL){
				cout << "Elimino solo 1 elemento. Lista vacia\n";
				listaEmp->ant = NULL;
				listaEmp->sig = NULL;
				listaEmp->empleado = NULL;
				listaEmp = NULL;
				delete listaEmp;
				return NULL;
			} else { // + de 1 elemento
				cout << "Hay mas de 1 elemento en la lista\n";
				ListaEmp aux = iter; // Me guardo el nodo ListaEmp a eliminar al final
				
				if (iter == listaEmp){ // Es el ultimo elemento
					// Actualizo el puntero al ultimo de la lista de empleados
					listaEmp->ant->sig = NULL;
					listaEmp = listaEmp->ant;
				} else { // No es el ultimo, no actualizo puntero de la lista
					
					if (iter->ant != NULL){ // Si no es el primero
						iter->ant->sig = iter->sig;
					}
					
					// Como no era el ultimo iter->sig != NULL
					iter->sig->ant = iter->ant;

				}

				delete aux;
				//return listaEmp;
			}

		} else {
			iter = iter->ant;
		}
	}
	//cout << "Salgo de EliminarEmpleadoListaEmpleados\n";
	//return encontre;
	return listaEmp;
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


bool isEmptyListaEmpleados(Cargo cargo){
	ListaEmp listaEmp = ObtenerListaEmpleadosCargo(cargo);
	return listaEmp == NULL;
}


Empleado Head(ListaEmp empleados){
// Retorna el primer elemento de la lista.
// Pre: l no vacia.
	return empleados->empleado;
}

ListaEmp Tail(ListaEmp empleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	//cout << "Tail ListaEmp\n";
	return empleados->ant;
}


ListaEmp ListaAnt(ListaEmp empleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return empleados->ant;
}

/*
ListaEmp Primero(QueueEmp queueEmpleados){
// Retorna el "resto" de la lista.
// Pre: l no vacia.
	return queueEmpleados->pri;
}
*/
void EliminarPlantilla(Plantilla &plantilla){
	while (plantilla->ant != NULL){
		plantilla = plantilla->ant;
	}
	while (plantilla != NULL){
		Plantilla temp = plantilla;
		plantilla = plantilla->sig;
		delete temp->empleado;
		delete temp;
	}
}

void EliminarListaEmpleados(ListaEmp &listaEmpleados) {
	while (listaEmpleados->ant != NULL){
		listaEmpleados = listaEmpleados->ant;
	}
    while (listaEmpleados != NULL) {
        ListaEmp temp = listaEmpleados;
        listaEmpleados = listaEmpleados->sig;
        //delete temp->empleado;
        delete temp;
    }
	
}
/*
void ImprimirListaEmp(ListaEmp empleados){
	if (empleados != NULL){
		cout<< empleados->ult->empleado->persona->ci << "-" <<  empleados->ult->empleado->persona->nom << "-" << empleados->ult->empleado->alta << "\n";
	}
	ImprimirListaEmp (empleados->ant);
}
*/

ListaEmp ActualizarListaEmp(ListaEmp &listaEmpleados, ListaEmp nuevo){
// PRE: listaEmpleados no vacia
// Suma un nuevo nodo a listaEmp y devuelve el puntero al ultimo
	if (nuevo != NULL){
		nuevo->ant = listaEmpleados;
		listaEmpleados->sig = nuevo;
		return nuevo;
	} else {
		return NULL;
	}

}

