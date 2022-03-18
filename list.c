#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;

    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* lista=(List*)calloc(10,sizeof(List));
    lista->head=NULL;

    lista->current=NULL;
     return lista;
}

void * firstList(List * list) {
    if(!list->head)
    {
        return NULL;
    }
    list->current=list->head;
    return list->head->data;
}

void * nextList(List * list) {
    void *dato;
    if(list->current==NULL)
    {
        return NULL;
    }
    else
    {
        if(list->current->next==NULL)
        {
            return NULL;
        }
        else
        {
            dato=list->current->next->data;
        }
    }
    list->current=list->current->next;
    return dato;
}

void * lastList(List * list) {
    if(!list->tail)
    {
        return NULL;
    }
    list->current=list->tail;
    return list->tail->data;
}

void * prevList(List * list) {
    void *dato;
    if(list->current==NULL)
    {
        return NULL;
    }
    else
    {
        if(list->current->prev==NULL)
        {
            return NULL;
        }
        else
        {
            dato=list->current->prev->data;
        }
    }
    list->current=list->current->prev;
    return dato;
}

void pushFront(List * list, void * data) {
    Node *datoNuevo;
    datoNuevo=createNode(data);
    if(list->head != NULL)
    {
        if(list->head->next==NULL)
        {
            list->tail=datoNuevo->data;
            list->head=datoNuevo->data;
            datoNuevo->prev=NULL;
        }
        else
        {
            datoNuevo=list->head;
            list->head->prev=datoNuevo;
            list->head=datoNuevo->data;
            datoNuevo->prev=NULL;
        }
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}