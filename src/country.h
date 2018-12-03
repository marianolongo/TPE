#ifndef TPE_COUNTRY_H
#define TPE_COUNTRY_H

#include "provinceList.h"
typedef struct countryStruct*  countryStructPointer;
struct countryStruct{
    provinceList provinces;
    int population;
    int homes;
};

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	crea un nuevo pais al cual se le da una lista
 *                  de provincias.
 * -------------------------------------------------------------------
 */
countryStructPointer newCountry(provinceList pro);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	incrementa la poblacion del pais.
 * -------------------------------------------------------------------
 */

void increaseCountryPopulation(countryStructPointer country);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	incrementa la cantidad de casas en el pais
 * -------------------------------------------------------------------
 */

void increaseCountryHomes(countryStructPointer country);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	vacia la estructura con sus estructuras internas
 * -------------------------------------------------------------------
 */

void freeCountry(countryStructPointer country);
#endif //TPE_COUNTRY_H
