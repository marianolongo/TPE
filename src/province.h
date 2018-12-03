#ifndef TPE_PROVINCE_H
#define TPE_PROVINCE_H

#include "departmentList.h"
typedef struct provinceStruct* provinceStructPointer;

struct provinceStruct{
    char name[128];
    int population;
    departmentList departments;
    int homes;

};

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	crea una nueva provincia leido del cvs.
 * -------------------------------------------------------------------
 */

provinceStructPointer newProvince(const char name[128]);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	incrementa la poblacion de la provincia.
 * -------------------------------------------------------------------
 */

void increaseProvincePopulation(provinceStructPointer province);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	incrementa la cantidad de casas en la porvincia
 * -------------------------------------------------------------------
 */

void increaseProvinceHomesAmount(provinceStructPointer province);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	vacia la estructura de la provincia, con sus
 *                  estructuras internas
 * -------------------------------------------------------------------
 */

void freeProvince(provinceStructPointer province);
#endif //TPE_PROVINCE_H
