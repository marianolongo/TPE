/*
 * homeList.c
 *
 */
/* Version recursiva de listas implementadas dinamicamente */

#include <stdio.h>
#include <stdlib.h>
#include "homeList.h"

struct node {
    listElementHome head;
    struct node * tail;

};

typedef struct node * nodeP;

struct listCDThome {
    nodeP first;
    unsigned int size;
    nodeP next;
};

static void
Error(const char* s)
{
    fprintf(stderr, "%s", s);
    exit(EXIT_FAILURE);
}

homeList newHomeList( void ) {
    return calloc(1, sizeof(struct listCDThome));
}

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Busca si la lista contiene un elemento
 *                  si lo contiene devuelve 1, y por lo
 *                  contrario devuelve 0.
 * -------------------------------------------------------------------
 */

static int contains(nodeP first, listElementHome elem) {
    int c;

    if(first == NULL || (c= compareAllHomes(first->head, elem)) > 0)
        return 0;

    if ( c == 0 )
        return 1;

    return contains( first->tail, elem);
}

int homeBelongs( homeList list, listElementHome element) {
    return contains(list->first, element);
}

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Funcion recursiva a la hora de instertar
 *                  un elemento. Si la lista se quedo sin
 *                  espacio devuelve un error. Devuelve el nodo
 *                  del elemento eliminado.
 * -------------------------------------------------------------------
 */

static nodeP insertRec(nodeP first, listElementHome elem, int * added) {
    int c;
    if( first == NULL || (c= compareAllHomes(first->head, elem)) > 0 )
    {
        nodeP aux = malloc(sizeof( struct node ));
        if (aux == NULL)
            Error("No hay lugar para otro nodo\n");
        aux->tail = first;
        aux->head = elem;
        *added = 1;
        return aux;
    }

    if( c < 0 )
        first->tail = insertRec( first->tail, elem, added);
    return first;
}

int insertHome(homeList list, listElementHome element) {
    /* Una mala solucion seria primero llamar a elementBelongs, y si retorna 1 no hacer nada porque ya pertenece
     * a la lista. Y si retorna cero volver a recorrer para insertar */

    int added =0 ;
    list->first = insertRec(list->first, element, &added);
    if (added)
        list->size++;
    return added;
}

void freeHomeList(homeList list) {
    nodeP curr=list->first, aux;

    while (curr != NULL) {
        aux = curr->tail;
        free(curr);
        curr = aux;
    }
    free(list);
}

void toBeginHomeList(homeList list) {
    list->next = list->first;
    list->size = 0;
}

int compareAllHomes(listElementHome elem1, listElementHome elem2) {
    return elem1 - elem2;
}
