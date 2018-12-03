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

/**
 * -------------------------------------------------------------------
 * Descripci�n: Funcion que devuelve un error
 * -------------------------------------------------------------------
 */

static void Error(const char* s) {
    fprintf(stderr, "%s", s);
    exit(EXIT_FAILURE);
}

departmentList newDepartmentList( void ) {
    return calloc(1, sizeof(struct listCDTdepartment));
}

/**
 * -------------------------------------------------------------------
 * Descripci�n: Busca si la lsta contiene el elemento
 *              y devuelve 1 si lo contiene, y 0 si no.
 * -------------------------------------------------------------------
 */

static int contains(nodeP first, listElementDepartment elem) {
    int c;

    if(first == NULL || (c= compareAllDepartments(first->head, elem)) > 0)
        return 0;

    if ( c == 0 )
        return 1;

    return contains( first->tail, elem);
}

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Funcion recursiva a la hora de instertar
 *                  un elemento. Si la lista se quedo sin
 *                  espacio devuelve un error. Devuelve el nodo
 *                  del elemento eliminado.
 * -------------------------------------------------------------------
 */

static nodeP insertRec(nodeP first, listElementDepartment elem, int * added) {
    int c;
    if( first == NULL || (c= compareAllDepartments(first->head, elem)) > 0 )
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

int insertDepartment(departmentList list, listElementDepartment element) {
    /* Una mala solucion seria primero llamar a elementBelongs, y si retorna 1 no hacer nada porque ya pertenece
     * a la lista. Y si retorna cero volver a recorrer para insertar */

    int added =0 ;
    list->first = insertRec(list->first, element, &added);
    if (added)
        list->size++;
    return added;
}

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Funcion recursiva de deleteDepartment.
 *                  Busca el elemento y si lo encuentra
 *                  lo elimina de la lista. Devuelve
 *                  el nodo del elemento eliminado.
 * -------------------------------------------------------------------
 */

static nodeP delRec(nodeP first, listElementDepartment elem, int * res) {

    int c;
    if( first==NULL || (c= compareAllDepartments(first->head, elem)) > 0 )
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

int deleteDepartment(departmentList list, listElementDepartment element) {
    int del=0;
    list->first = delRec(list->first, element, &del);
    if ( del )
        list->size--;
    return del;
}

void freeDepartmentList(departmentList list) {
    nodeP curr=list->first, aux;

    while (curr != NULL) {
        aux = curr->tail;
        free(curr);
        curr = aux;
    }
    free(list);
}

void toBeginDepartmentList(departmentList list) {
    list->next = list->first;
}

int hasNextDepartment(const departmentList list) {
    return list->next != NULL;
}

listElementDepartment nextDepartment(departmentList list) {
    if (list->next==NULL)
        Error("No hay mas elementos a recorrer");
    listElementDepartment ans = list->next->head;
    list->next = list->next->tail;

    return ans;
}

/**
 * -------------------------------------------------------------------
 * Descripci�n: 	Funcion recursiva que busca si el departamento
 *                  se encuentra en la lista de departamentos,
 *                  Si lo encuentra devuelve el nodo.
 * -------------------------------------------------------------------
 */

static listElementDepartment searchDepartmentRec(nodeP node, departmentStructPointer department){
    if(compareAllDepartments(node->head,department) == 0){
        return node->head;
    }
    return searchDepartmentRec(node->tail,department);
}

listElementDepartment searchDepartment(departmentList list, departmentStructPointer department){
    return searchDepartmentRec(list->first,department);
}

int compareAllDepartments(listElementDepartment elem1, listElementDepartment elem2) {
    return strcmp(elem1->name, elem2->name);
}