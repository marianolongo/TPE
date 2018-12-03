#ifndef TPE_FILEMANAGER_H
#define TPE_FILEMANAGER_H

#include <stdio.h>
#include "country.h"



char* getField(char* line, int num);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Leer un archivo cvs y guardar
 *                  la informacion del censo segun
 *                  corresponda en las distintas estructuras.
 *
 * -------------------------------------------------------------------
 * Postcondicion: 	Guarda toda la informacion del censo en un Pais.
 */

countryStructPointer readFile(char *fileName);

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Crea archivos cvs donde almacena
 *                  toda la informacion previamente
 *                  almacenada en las distintas estructuras.
 *                  Si las estructuras estan vacias, imprime
 *                  un mensaje diciendo "Could not create .csv"
 * -------------------------------------------------------------------
 * Precondicion:	Estructuras no esten vacias
 * Postcondicion: 	Archivos cvs con la informacion almacenada
 */

void solution(countryStructPointer country);

#endif //TPE_FILEMANAGER_H
