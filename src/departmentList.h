#ifndef TPE_DEPARTMENTLIST_H
#define TPE_DEPARTMENTLIST_H

#include <string.h>
#include "department.h"

typedef departmentStructPointer listElementDepartment;

/**
 * El siguiente tipo define el TAD Lista.
 * Se lo define como puntero a "cierta estructura"
 * para ocultar la real representacion de la misma
 */
typedef struct listCDTdepartment *departmentList;

/**
 * Funci�n de comparaci�n para ordenar las componentes del TAD.
 * De no servir este c�digo el usuario debe cambiarlo por el
 * que desea. La convenci�n a seguir es que debe devolver
 * n�mero negativo si el primer par�metro debe aparecer antes
 * que el segundo en la lista, devolver n�mero positivo
 * si debe aparecer despu�s, o bien 0 si son elementos equivalentes
 */
int compareAllDepartments(listElementDepartment elem1, listElementDepartment elem2);

/**
 * Funcion:  		newList
 * Uso:  		list = newList();
 * -------------------------------------------------------------------
 * Descripci�n: 	Inicializa la lista. No hay error posible.
 * -------------------------------------------------------------------
 * Precondicion:		-
 * Postcondicion: 	Lista creada
 */
departmentList newDepartmentList(void);

/**
 * Funcion:  		Insert
 * Uso:  	        res == 	Insert( list, 12.3);
 * -------------------------------------------------------------------
 * Descripci�n: 	Inserta un elemento en la lista ordenada,
 *  			usando la funci�n de comparaci�n Compare.
 * 			Si el elemento ya exist�a, lo ignora y retorna cero.
 * 		        Retorna 1 si lo pudo insertar
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	Lista con el nuevo elemento,si no estaba repetido.
 */
int insertDepartment(departmentList list, listElementDepartment element);

/**
 * Funcion:  		delete
 * Uso:  	        res = 	delete(list, 12.3 );
 * -------------------------------------------------------------------
 * Descripci�n: 	Elimina el elemento de la lista ordenada,
 *  			usando la funci�n Compara. Si el elemento
 * 			no exist�a devuelve 0, caso contrario 1
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	Lista sin el elemento
 */
int deleteDepartment(departmentList list, listElementDepartment element);

/**
 * Funcion: 		freeList
 * Uso: 		freeList( list );
 * -------------------------------------------------------------------
 * Descripci�n: 	Destruye la lista, liberando recursos alocados.
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida.
 * Postcondicion: 	-
 */
void freeDepartmentList(departmentList list);

/**
 * Funciones para poder iterar sobre la lista
 */
void toBeginDepartmentList(departmentList list);

int hasNextDepartment(const departmentList list);

listElementDepartment nextDepartment(departmentList list);

listElementDepartment searchDepartment(departmentList list, departmentStructPointer department);

#endif //TPE_DEPARTMENTLIST_H
