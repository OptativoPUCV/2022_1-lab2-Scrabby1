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
        datoNuevo->next=list->head;
        list->head->prev=datoNuevo;
        list->head=datoNuevo;
        if(list->head->next==NULL)
        {
            list->tail=datoNuevo;
        }
        datoNuevo->prev=NULL;
    }
    else
    {
        list->head=datoNuevo;
        list->tail=datoNuevo;
        datoNuevo->prev=NULL;
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node *datoNuevo;
    datoNuevo=createNode(data);
    if(list->current !=NULL)
    {
        if(list->current->next==NULL)
        {
            list->current->next=datoNuevo;
            datoNuevo->prev=list->current;
            datoNuevo->next=NULL;
            list->tail=datoNuevo;
        }
        else
        {
            datoNuevo->next=list->current->next->prev;
            list->current->next->prev=datoNuevo;
            list->current->next=datoNuevo;
            datoNuevo->prev=list->current;
        }
    }
    else
    {
        list->head=datoNuevo;
        list->tail=datoNuevo;
        list->current=datoNuevo;
        datoNuevo->prev=NULL;
        datoNuevo->next=NULL;
    }
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
    void * dato=list->current->data;
    if(list->current!=NULL)
    {
        if(list->current->prev != NULL && list->current->next != NULL)
        {
            list->current->prev->next=list->current->next;
            list->current->next->prev=list->current->prev;
        }
        else
        {
            if(list->current->next == NULL)
            {
                list->tail=list->current->prev;
                list->current->prev->next=NULL;
            }
            else
            {
                if(list->current->prev==NULL)
                {
                    list->head=list->current->next;
                    list->current->next->prev=NULL;
                }
                else
                {
                    free(list->current);
                }
            }
        }
        return dato;
    }
    else
    {
        return NULL;
    }
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}