#ifndef TPE_PROVINCELIST_H
#define TPE_PROVINCELIST_H

#include "province.h"

typedef provinceStructPointer listElementProvince;

/**
 * El siguiente tipo define el TAD Lista.
 * Se lo define como puntero a "cierta estructura"
 * para ocultar la real representacion de la misma
 */
typedef struct listCDTprovince *provinceList;


/**
 * Funci�n de comparaci�n para ordenar las componentes del TAD.
 * De no servir este c�digo el usuario debe cambiarlo por el
 * que desea. La convenci�n a seguir es que debe devolver
 * n�mero negativo si el primer par�metro debe aparecer antes
 * que el segundo en la lista, devolver n�mero positivo
 * si debe aparecer despu�s, o bien 0 si son elementos equivalentes
 */
int compareAllProvinces(listElementProvince elem1, listElementProvince elem2 );

/**
 * Funcion:  		newList
 * Uso:  		list = newList();
 * -------------------------------------------------------------------
 * Descripci�n: 	Inicializa la lista. No hay error posible.
 * -------------------------------------------------------------------
 * Precondicion:		-
 * Postcondicion: 	Lista creada
 */
provinceList newProvinceList(void);

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
int insertProvince(provinceList  list, listElementProvince element);


/**
 * Funcion:  		delete
 * Uso:  	        res = 	deleteProvince(list, 12.3 );
 * -------------------------------------------------------------------
 * Descripci�n: 	Elimina el elemento de la lista ordenada,
 *  			usando la funci�n Compara. Si el elemento
 * 			no exist�a devuelve 0, caso contrario 1
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	Lista sin el elemento
 */
int deleteProvince(provinceList list, listElementProvince element);

/**
 * Funcion: 		freeList
 * Uso: 		freeProvinceList( list );
 * -------------------------------------------------------------------
 * Descripci�n: 	Destruye la lista, liberando recursos alocados.
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida.
 * Postcondicion: 	-
 */
void freeProvinceList(provinceList list);

/**
 * Retorna la cantidad de elementos en la lista
 */
int listProvinceSize(const provinceList list);


/**
 * Funciones para poder iterar sobre la lista
 */
void toBeginProvinceList(provinceList list);

int hasNextProvince(const provinceList list);

listElementProvince nextProvince(provinceList list);

listElementProvince searchProvince(provinceList list, provinceStructPointer province);

#endif //TPE_PROVINCELIST_H
