/*
 * homeList.h
 * Contrato del TAD Lista Lineal
 * simplemente encadenada ordenada, sin repeticiones
 */

#ifndef HOMELIST_H_
#define HOMELIST_H_

typedef int listElementHome;

///* El siguiente tipo define el TAD Lista.
// * Se lo define como puntero a "cierta estructura"
// * para ocultar la real representacion de la misma
// */
typedef struct listCDThome *homeList;


///* Función de comparación para ordenar las componentes del TAD.
// * De no servir este código el usuario debe cambiarlo por el
// * que desea. La convención a seguir es que debe devolver
// * número negativo si el primer parámetro debe aparecer antes
// * que el segundo en la lista, devolver número positivo
// * si debe aparecer después, o bien 0 si son elementos equivalentes
// */
static int compareAllHomes(listElementHome elem1, listElementHome elem2)
{
    return elem1 - elem2;
}

///* Funcion:  		newList
// * Uso:  		list = newList();
// * -------------------------------------------------------------------
// * Descripción: 	Inicializa la lista. No hay error posible.
// * -------------------------------------------------------------------
// * Precondicion:		-
// * Postcondicion: 	Lista creada
// */
homeList newHomeList(void);


/* Funcion:  		Insert
 * Uso:  	        res == 	Insert( list, 12.3);
 * -------------------------------------------------------------------
 * Descripción: 	Inserta un elemento en la lista ordenada,
 *  			usando la función de comparación Compare.
 * 			Si el elemento ya existía, lo ignora y retorna cero.
 * 		        Retorna 1 si lo pudo insertar
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	Lista con el nuevo elemento,si no estaba repetido.
 */
int insertHome(homeList  list, listElementHome element);


/* Funcion:  		delete
 * Uso:  	        res = 	delete(list, 12.3 );
 * -------------------------------------------------------------------
 * Descripción: 	Elimina el elemento de la lista ordenada,
 *  			usando la función Compara. Si el elemento
 * 			no existía devuelve 0, caso contrario 1
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	Lista sin el elemento
 */
//int deleteHome(homeList list, listElementHome element);


/* Funcion:  		listIsEmpty
 * Uso:  		if ( listIsEmpty( list ) ...
 * -------------------------------------------------------------------
 * Descripción: 	Devuelve 1 si la lista está vacía o
 * 			0 en caso contrario
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	- (lista invariante).
 */
int homeListIsEmpty(const homeList list);

/* Funcion:  		elementBelongs
 * Uso:  		if ( elementBelongs( list, 12.3 ))...
 * -------------------------------------------------------------------
 * Descripción: 	Devuelve 1 si el elemento pertenece a la lista
 * 					o 0 en caso contrario
 * -------------------------------------------------------------------
 * Precondicion:	Lista previamente creada
 * Postcondicion: 	- (lista invariante).
 */
int homeBelongs(const homeList list, listElementHome element);


/* Funcion: 		freeList
 * Uso: 		freeList( list );
 * -------------------------------------------------------------------
 * Descripción: 	Destruye la lista, liberando recursos alocados.
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida.
 * Postcondicion: 	-
 */
void freeHomeList(homeList list);

/**
 * Retorna la cantidad de elementos en la lista
 */
int homeListSize(const homeList list);


/**
 * Funciones para poder iterar sobre la lista
 */
void toBeginHomeList(homeList list);

//int hasNextHome(const homeList list);

//listElementHome nextHome(homeList list);

//listElementHome searchHome(homeList list,listElementHome home);
#endif /* LISTADT_H_ */

