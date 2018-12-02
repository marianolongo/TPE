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


int homeListIsEmpty( homeList list) {
    return list->size == 0;
}

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

static nodeP delRec(nodeP first, listElementHome elem, int * res) {

    int c;
    if( first==NULL || (c= compareAllHomes(first->head, elem)) > 0 )
        return first;

    if( c == 0 )
    {
        nodeP aux = first->tail;
        free(first);
        *res = 1;
        return aux;
    }
    first->tail = delRec(first->tail, elem, res);
    return first;

}

int deleteHome( homeList list, listElementHome element) {
    int del=0;
    list->first = delRec(list->first, element, &del);
    if ( del )
        list->size--;
    return del;
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

int homeListSize(const homeList list) {
    return list->size;
}

void toBeginHomeList(homeList list) {
    list->next = list->first;
    list->size = 0;
}

int hasNextHome(const homeList list) {
    return list->next != NULL;
}

listElementHome nextHome(homeList list) {
    if (list->next==NULL)
        Error("No hay mas elementos a recorrer");
    listElementHome ans = list->next->head;
    list->next = list->next->tail;
    return ans;
}

void injectHome(homeList list, listElementHome (*fn)(listElementHome)) {
    nodeP curr=list->first;
    while(curr != NULL) {
        curr->head = fn(curr->head);
        curr=curr->tail;
    }
}

static listElementHome searchHomeRec(nodeP node, listElementHome home){
    if(compareAllHomes(node->head,home) == 0){
        return node->head;
    }
    return searchHomeRec(node->tail, home);
}

listElementHome searchHome(homeList list,listElementHome home){
    return searchHomeRec(list->first, home);
}