// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio Organigrama
// main.c
// Consola para ingreso de datos.

#include "definiciones.h"
#include "empresa.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;


int main (){
	Empresa e;
	bool creado = false;
	char * comando = new (char[MAX_COMANDO]);
	char * pch, * pch1, * pch2, *pch3;
	TipoRet ret;
	bool ejecutado = false;
	bool salir = false;

	cout << "\tCrearOrg(cargo)\n";
	cout << "\tEliminarOrg()\n";
	cout << "\tNuevoCargo(cargoPadre, nuevoCargo)\n";
	cout << "\tEliminarCargo(cargo)\n";
	cout << "\tListarCargosAlf()\n";
	cout << "\tListarJerarquia()\n";
	cout << "\tAsignarPersona(cargo, ci, nombre)\n";
	cout << "\tEliminarPersona(ci)\n";
	cout << "\tReasignarPersona(cargo, ci)\n";
	cout << "\tListarPersonas(cargo)\n";
	cout << "\tListarSuperCargos(cargo)\n";
	cout << "\tSalir\n\n";
	
	
	do{

		cout << "> ";
		fflush( stdin );
		ejecutado = false;
		
		fgets (comando, MAX_COMANDO, stdin);
		
		pch = strtok (comando,"( ,)\n");
		
		if (pch != NULL){
			if (strcasecmp (pch, "CrearOrg") == 0){
				pch = strtok (NULL, "( ,)\n");
				if (pch != NULL){
					if (!creado){
						ret = CrearOrg(e, pch);
						ejecutado = true;
						creado = true;
					}else
						cout << " - ERROR: para ejecutar el comando el organigrama NO debe estar creado.\n";
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else if (strcasecmp (pch, "EliminarOrg") == 0){
				if (creado){
					ret = EliminarOrg(e);
					ejecutado = true;
					creado = false;
				}else
					cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
			}else if (strcasecmp (pch, "NuevoCargo") == 0){
				pch = strtok (NULL, "( ,)\n");
				if (pch != NULL){
					pch1 = strtok (NULL, "( ,)\n");
					if (pch1 != NULL){
						if (creado){
							ret = NuevoCargo(e, pch, pch1);
							ejecutado = true;
						}else
							cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
					}else
						cout << " - ERROR: Faltan Parametros.\n";
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else if (strcasecmp (pch, "EliminarCargo") == 0){
				pch = strtok (NULL, "( ,)\n");
				if (pch != NULL){
					if (creado){
						ret = EliminarCargo(e, pch);
						ejecutado = true;
					}else
						cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else if (strcasecmp (pch, "ListarCargosAlf") == 0){
				if (creado){
					ret = ListarCargosAlf(e);
					ejecutado = true;
				}else
					cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
			}else if (strcasecmp (pch, "ListarJerarquia") == 0){
				if (creado){
					ret = ListarJerarquia(e);
					ejecutado = true;
				}else
					cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
			}else if (strcasecmp (pch, "AsignarPersona") == 0){
				pch = strtok (NULL, "( ,)\n");
				if (pch != NULL){
					pch1 = strtok (NULL, "( ,)\n");
					if (pch1 != NULL){
						pch2 = strtok (NULL, "(,)\n");
						if (pch2 != NULL){
							if (creado){
								ret = AsignarPersona (e, pch, pch2, pch1);
								ejecutado = true;
							}else
								cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
						}else
							cout << " - ERROR: Faltan Parametros.\n";
					}else
						cout << " - ERROR: Faltan Parametros.\n";
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else if (strcasecmp (pch, "EliminarPersona") == 0){
				pch = strtok (NULL, "( ,)\n");
				if (pch != NULL){
					if (creado){
						ret = EliminarCargo(e, pch);
						ejecutado = true;
					}else
						cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else if (strcasecmp (pch, "ReasignarPersona") == 0){
				pch = strtok (NULL, "( ,)\n");
				if (pch != NULL)
				{
					pch1 = strtok (NULL, "( ,)\n");
					if (pch1 != NULL){
						if (creado){
							ret = ReasignarPersona(e, pch, pch1);
							ejecutado = true;
						}else
							cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
			}
			else if (strcasecmp (pch, "ListarPersonas") == 0){
				pch = strtok (NULL, "( ,)\n");
				if (pch != NULL){
					if (creado){
						ret = ListarPersonas(e, pch);
						ejecutado = true;
					}else
						cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else if (strcasecmp (pch, "ListarSuperCargos") == 0){
				pch = strtok (NULL, "( ,)\n");
				if (pch != NULL){
					if (creado){
						ret = ListarSuperCargos(e, pch);
						ejecutado = true;
					}else
							cout << " - ERROR: para ejecutar el comando el organigrama debe estar creado.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else if (strcasecmp (pch, "salir") == 0)
				salir = true;
			else
				cout << " - Comando Incorrecto\n";
			if (ejecutado){
				if (ret == OK)
					cout << " - OK\n";
				else if (ret == ERROR)
					cout << " - ERROR\n";
				else
					cout << " - NO IMPLEMENTADA\n";
			}
		}
	}while (!salir);
	cout << "\n\n - CHAUU!!!!\n";

	if (creado)
		ret = EliminarOrg(e);
	delete [] comando;
}
