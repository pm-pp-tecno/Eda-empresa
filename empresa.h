#ifndef EMPRESA_H
#define EMPRESA_H

// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empresa.h
// Modulo de Definición de la Empresa


#include "definiciones.h"

typedef struct nodo_empresa * Empresa;


TipoRet CrearOrg(Empresa &e, Cadena cargo);
// Inicializa la empresa y crea el primer cargo de la empresa.
// Originalmente la misma debería  estar vacía, en otro caso la operación quedará sin efecto. 

TipoRet EliminarOrg(Empresa &e);
// Eliminar el organigrama, elimina toda la estructura del organigrama, liberando la memoria asignada.

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo);
// Insertar un nuevo cargo como dependiente de otro ya existente.
// El nuevo cargo no debe existir en el sistema.

TipoRet EliminarCargo(Empresa &e, Cadena cargo);
// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.

TipoRet ListarCargosAlf(Empresa e);
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo. 

TipoRet ListarJerarquia(Empresa e);
// Listar todos los cargos de la empresa en orden jerárquico. 
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra. 

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci);
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no este asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.

TipoRet EliminarPersona(Empresa &e, Cadena ci);
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci);
// Reasignar una persona a un nuevo cargo.
// Reasigna una persona de la empresa de cédula ci al nuevo cargo de nombre cargo
// siempre que el cargo exista en la empresa y esa persona no este ya asignada a
// dicho cargo. En caso contrario la operación quedará sin efecto.

TipoRet ListarPersonas(Empresa e, Cadena cargo);
// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa. 
// Lista todas las personas asignadas al cargo de nombre cargo. 

TipoRet ListarSuperCargos (Empresa e, Cadena cargo);
// Dado un cargo listar los cargos que lo anteceden.
// Lista todas los cargos que anteceden, en la jerarquía, al cargo de nombre cargo. 

#endif


