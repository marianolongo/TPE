/*
 * listADT.c
 *
 */
/* Version recursiva de listas implementadas dinamicamente */

#include <stdio.h>
#include <stdlib.h>
#include "departmentList.h"

struct node {
    listElementDepartment head;
    struct node * tail;

};

typedef struct node * nodeP;

struct listCDTdepartment {
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


departmentList newList( void ) {
    return calloc(1, sizeof(struct listCDT));
}


int listIsEmpty( departmentList list) {
    return list->size == 0;
}




static int contains(nodeP first, listElementDepartment elem) {
    int c;

    if(first == NULL || (c=compare(first->head, elem)) > 0)
        return 0;

    if ( c == 0 )
        return 1;

    return contains( first->tail, elem);
}

int
elementBelongs(departmentList list, listElementDepartment element)
{
    return contains(list->first, element);
}


static nodeP insertRec(nodeP first, listElementDepartment elem, int * added) {
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

int insert(departmentList list, listElementDepartment element) {
    /* Una mala solucion seria primero llamar a elementBelongs, y si retorna 1 no hacer nada porque ya pertenece
     * a la lista. Y si retorna cero volver a recorrer para insertar */

    int added =0 ;
    list->first = insertRec(list->first, element, &added);
    if (added)
        list->size++;
    return added;
}


static nodeP delRec(nodeP first, listElementDepartment elem, int * res) {

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

int delete(departmentList list, listElementDepartment element) {
    int del=0;
    list->first = delRec(list->first, element, &del);
    if ( del )
        list->size--;
    return del;
}



void freeList(departmentList list) {
    nodeP curr=list->first, aux;

    while (curr != NULL) {
        aux = curr->tail;
        free(curr);
        curr = aux;
    }
    free(list);
}

int listSize(const departmentList list) {
    return list->size;
}

void toBegin(departmentList list) {
    list->next = list->first;
}

int hasNext(const departmentList list) {
    return list->next != NULL;
}

listElementDepartment next(departmentList list) {
    if (list->next==NULL)
        Error("No hay mas elementos a recorrer");
    listElementDepartment ans = list->next->head;
    list->next = list->next->tail;

    return ans;
}

void inject(departmentList list, listElementDepartment (*fn)(listElementDepartment)) {
    nodeP curr=list->first;
    while(curr != NULL) {
        curr->head = fn(curr->head);
        curr=curr->tail;
    }
}

nodeP mapRec(nodeP list,listElementDepartment (*fn)(listElementDepartment)) {
    if (list==NULL)
        return list;
    nodeP aux = malloc(sizeof(*aux));
    aux->head = fn(list->head);
    aux->tail = mapRec(list->tail, fn);
    return aux;
}

departmentList map(departmentList list, listElementDepartment (*fn)(listElementDepartment)) {
    departmentList new = newList();
    new->first = mapRec(list->first, fn);
    return new;
}