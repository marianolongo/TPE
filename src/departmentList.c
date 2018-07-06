/*
 * listADT.c
 *
 */
/* Version recursiva de listas implementadas dinamicamente */

#include <stdio.h>
#include <stdlib.h>
#include "departmentList.h"

struct node {
    listElementTdepartment head;
    struct node * tail;

};

typedef struct node * nodeP;

struct listCDT {
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


listADT
newList( void )
{
    return calloc(1, sizeof(struct listCDT));
}


int
listIsEmpty( listADT list)
{
    return list->size == 0;
}




static int contains(nodeP first, listElementTdepartment elem) {
    int c;

    if(first == NULL || (c=compare(first->head, elem)) > 0)
        return 0;

    if ( c == 0 )
        return 1;

    return contains( first->tail, elem);
}

int
elementBelongs( listADT list, listElementTdepartment element)
{
    return contains(list->first, element);
}


static nodeP insertRec(nodeP first, listElementTdepartment elem, int * added) {
    int c;
    if( first == NULL || (c=compare(first->head, elem)) > 0 )
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

int
insert( listADT list, listElementTdepartment element)
{
    /* Una mala solucion seria primero llamar a elementBelongs, y si retorna 1 no hacer nada porque ya pertenece
     * a la lista. Y si retorna cero volver a recorrer para insertar */

    int added =0 ;
    list->first = insertRec(list->first, element, &added);
    if (added)
        list->size++;
    return added;
}


static nodeP delRec(nodeP first, listElementTdepartment elem, int * res) {

    int c;
    if( first==NULL || (c=compare(first->head, elem)) > 0 )
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

int
delete( listADT list, listElementTdepartment element)
{
    int del=0;
    list->first = delRec(list->first, element, &del);
    if ( del )
        list->size--;
    return del;
}



void
freeList( listADT list)
{
    nodeP curr=list->first, aux;

    while (curr != NULL) {
        aux = curr->tail;
        free(curr);
        curr = aux;
    }
    free(list);
}

int
listSize(const listADT list) {
    return list->size;
}

void
toBegin(listADT list) {
    list->next = list->first;
}

int
hasNext(const listADT list) {
    return list->next != NULL;
}

listElementTdepartment
next(listADT list) {
    if (list->next==NULL)
        Error("No hay mas elementos a recorrer");
    listElementTdepartment ans = list->next->head;
    list->next = list->next->tail;

    return ans;
}

void
inject(listADT list, listElementTdepartment (*fn)(listElementTdepartment)) {
    nodeP curr=list->first;
    while(curr != NULL) {
        curr->head = fn(curr->head);
        curr=curr->tail;
    }
}

nodeP
mapRec(nodeP list,listElementTdepartment (*fn)(listElementTdepartment)) {
    if (list==NULL)
        return list;
    nodeP aux = malloc(sizeof(*aux));
    aux->head = fn(list->head);
    aux->tail = mapRec(list->tail, fn);
    return aux;
}

listADT
map(listADT list, listElementTdepartment (*fn)(listElementTdepartment)) {
    listADT new = newList();
    new->first = mapRec(list->first, fn);
    return new;
}/*
 * listADT.c
 *
 */
/* Version recursiva de listas implementadas dinamicamente */

#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

struct node {
    listElementTdepartment head;
    struct node * tail;

};

typedef struct node * nodeP;

struct listCDT {
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


listADT
newList( void )
{
    return calloc(1, sizeof(struct listCDT));
}


int
listIsEmpty( listADT list)
{
    return list->size == 0;
}




static int contains(nodeP first, listElementTdepartment elem) {
    int c;

    if(first == NULL || (c=compare(first->head, elem)) > 0)
        return 0;

    if ( c == 0 )
        return 1;

    return contains( first->tail, elem);
}

int
elementBelongs( listADT list, listElementTdepartment element)
{
    return contains(list->first, element);
}


static nodeP insertRec(nodeP first, listElementTdepartment elem, int * added) {
    int c;
    if( first == NULL || (c=compare(first->head, elem)) > 0 )
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

int
insert( listADT list, listElementTdepartment element)
{
    /* Una mala solucion seria primero llamar a elementBelongs, y si retorna 1 no hacer nada porque ya pertenece
     * a la lista. Y si retorna cero volver a recorrer para insertar */

    int added =0 ;
    list->first = insertRec(list->first, element, &added);
    if (added)
        list->size++;
    return added;
}


static nodeP delRec(nodeP first, listElementTdepartment elem, int * res) {

    int c;
    if( first==NULL || (c=compare(first->head, elem)) > 0 )
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

int
delete( listADT list, listElementTdepartment element)
{
    int del=0;
    list->first = delRec(list->first, element, &del);
    if ( del )
        list->size--;
    return del;
}



void
freeList( listADT list)
{
    nodeP curr=list->first, aux;

    while (curr != NULL) {
        aux = curr->tail;
        free(curr);
        curr = aux;
    }
    free(list);
}

int
listSize(const listADT list) {
    return list->size;
}

void
toBegin(listADT list) {
    list->next = list->first;
}

int
hasNext(const listADT list) {
    return list->next != NULL;
}

listElementTdepartment
next(listADT list) {
    if (list->next==NULL)
        Error("No hay mas elementos a recorrer");
    listElementTdepartment ans = list->next->head;
    list->next = list->next->tail;

    return ans;
}

void
inject(listADT list, listElementTdepartment (*fn)(listElementTdepartment)) {
    nodeP curr=list->first;
    while(curr != NULL) {
        curr->head = fn(curr->head);
        curr=curr->tail;
    }
}

nodeP
mapRec(nodeP list,listElementTdepartment (*fn)(listElementTdepartment)) {
    if (list==NULL)
        return list;
    nodeP aux = malloc(sizeof(*aux));
    aux->head = fn(list->head);
    aux->tail = mapRec(list->tail, fn);
    return aux;
}

listADT
map(listADT list, listElementTdepartment (*fn)(listElementTdepartment)) {
    listADT new = newList();
    new->first = mapRec(list->first, fn);
    return new;
}