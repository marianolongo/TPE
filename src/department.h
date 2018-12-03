#ifndef TPE_DEPARTMENT_H
#define TPE_DEPARTMENT_H

#include <stdio.h>
#include "homeList.h"


typedef struct departmentStruct *departmentStructPointer;

struct departmentStruct{
    int ocupation[4];
    int population;
    char name[128];
    homeList homes;
};

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	crea un nuevo departamento leido del cvs.
 * -------------------------------------------------------------------
 */
departmentStructPointer newDepartment(const char name[128]);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Incrementa la poblacion del pais
 * -------------------------------------------------------------------
 */

void increaseDepartmentPopulation(departmentStructPointer department, int ocupation);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Agrega una casa al departamento, si
 *                  la misma no existe en la estructura.
 *                  Si esta existe retorna 0,
 *                  sino retorna 1.
 * -------------------------------------------------------------------
 */

int addHome(departmentStructPointer department, listElementHome home);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	vacia la provincia, vaciando
 *                  las estructuras internas que tiene.
 * -------------------------------------------------------------------
 */

void freeDepartment(departmentStructPointer department);
#endif //TPE_DEPARTMENT_H
