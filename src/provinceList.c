/*
 * homeList.c
 *
 */
/* Version recursiva de listas implementadas dinamicamente */

#include <stdio.h>
#include <stdlib.h>
#include "provinceList.h"

struct node {
    listElementProvince head;
    struct node * tail;
};

typedef struct node * nodeP;

struct listCDTprovince {
    nodeP first;
    unsigned int size;
    nodeP next;
};

listElementProvince getProvinceRec(nodeP pNode, int index);

static void Error(const char* s) {
    fprintf(stderr, "%s", s);
    exit(EXIT_FAILURE);
}

provinceList newProvinceList( void ) {
    return calloc(1, sizeof(struct listCDTprovince));
}

//int provinceListIsEmpty( provinceList list) {
//    return list->size == 0;
//}

static int contains(nodeP first, listElementProvince elem) {
    int c;

    if(first == NULL || (c=compareAllProvinces(first->head, elem)) > 0)
        return 0;

    if ( c == 0 )
        return 1;
    return contains( first->tail, elem);
}

//int provinceBelongs( provinceList list, listElementProvince element) {
//    return contains(list->first, element);
//}

static nodeP insertRec(nodeP first, listElementProvince elem, int * added) {
    int c;
    if(first == NULL || (c=compareAllProvinces(first->head, elem)) > 0 ) {
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

int insertProvince(provinceList list, listElementProvince element) {
    /* Una mala solucion seria primero llamar a elementBelongs, y si retorna 1 no hacer nada porque ya pertenece
     * a la lista. Y si retorna cero volver a recorrer para insertar */

    int added = 0;
    list->first = insertRec(list->first, element, &added);
    if (added)
        list->size++;
    return added;
}

static nodeP delRec(nodeP first, listElementProvince elem, int * res) {
    int c;
    if( first==NULL || (c=compareAllProvinces(first->head, elem)) > 0 )
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

int deleteProvince(provinceList list, listElementProvince element) {
    int del=0;
    list->first = delRec(list->first, element, &del);
    if ( del )
        list->size--;
    return del;
}

//void freeProvinceList(provinceList list) {
//    nodeP curr=list->first, aux;
//
//    while (curr != NULL) {
//        aux = curr->tail;
//        free(curr);
//        curr = aux;
//    }
//    free(list);
//}

int listProvinceSize(const provinceList list) {
    return list->size;
}

void toBeginProvinceList(provinceList list) {
    list->next = list->first;
}

int hasNextProvince(const provinceList list) {
    return list->next != NULL;
}

listElementProvince nextProvince(provinceList list){
    if (list->next==NULL)
        Error("No hay mas elementos a recorrer");
    listElementProvince ans = list->next->head;
    list->next = list->next->tail;

    return ans;
}

//void injectProvince(provinceList list, listElementProvince (*fn)(listElementProvince)) {
//    nodeP curr=list->first;
//    while(curr != NULL) {
//        curr->head = fn(curr->head);
//        curr=curr->tail;
//    }
//}

static listElementProvince searchProvinceRec(nodeP node, provinceStructPointer province){
    if(compareAllProvinces(node->head,province) == 0){
        return node->head;
    }
    return searchProvinceRec(node->tail,province);
}

listElementProvince searchProvince(provinceList list, provinceStructPointer province){
    return searchProvinceRec(list->first,province);
}

//listElementProvince getProvince(provinceList list, int index){
//    return getProvinceRec(list->first,index);
//}

listElementProvince getProvinceRec(nodeP node, int index) {
    if(index == 0){
        return node->head;
    }
    index--;
    return getProvinceRec(node->tail,index);
}