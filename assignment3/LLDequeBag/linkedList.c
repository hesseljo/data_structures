/* CS261- Assignment 2 - Q. 0*/
/* Name: Joshua Hesseltine
 * Date: 10/25/15
 * Solution description: Linked List Implementation */

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

void _initList (struct linkedList *lst) {
  
    assert(lst != 0);
    lst->size = 0;
    lst->firstLink = (struct DLink *) malloc(sizeof(struct DLink));
    lst->lastLink = (struct DLink *) malloc(sizeof(struct DLink));
    assert(lst->firstLink != 0);
    assert(lst->lastLink != 0);
    lst->firstLink->next = lst->lastLink;
    lst->lastLink->prev = lst->firstLink;
}

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
    assert(lst != 0);
    assert(l != 0);
    struct DLink* newLink = (struct DLink *) malloc(sizeof(struct DLink));
    assert(newLink != 0);
    newLink->value = v;
    newLink->next = l;
    newLink->prev = l->prev;
    l->prev->next = newLink;
    l->prev = newLink;
    lst->size++;

}

void addFrontList(struct linkedList *lst, TYPE e)
{

    assert(lst != 0);
    _addLinkBefore(lst, lst->firstLink->next, e);
}

void addBackList(struct linkedList *lst, TYPE e) {
  
    assert(lst != 0);
    _addLinkBefore(lst, lst->lastLink, e);
}

TYPE frontList (struct linkedList *lst) {

    assert(lst != 0);
    assert(lst->size != 0);
    return(lst->firstLink->next->value);
}

TYPE backList(struct linkedList *lst)
{
    assert(lst != 0);
    assert(lst->size != 0);
    return(lst->lastLink->prev->value);
}

void _removeLink(struct linkedList *lst, struct DLink *l)
{

    assert(lst != 0);
    assert(l != 0);
    l->prev->next = l->next;
    l->next->prev = l->prev;
    lst->size--;
    free(l);
	
}


void removeFrontList(struct linkedList *lst) {
    assert(lst != 0);
    assert(lst->size != 0);
    _removeLink(lst, lst->firstLink->next);
}


void removeBackList(struct linkedList *lst)
{	
    assert(lst != 0);
    assert(lst->size != 0);
    _removeLink(lst, lst->lastLink->prev);
}


int isEmptyList(struct linkedList *lst) {
    assert(lst != 0);
    if(lst->size > 0){
        return(1);
    }
    return(0);
}


void _printList(struct linkedList* lst)
{

    assert(lst != 0);
    struct DLink* tempLink = (struct DLink *) malloc(sizeof(struct DLink));
    tempLink = lst->firstLink;
    while(tempLink->next != lst->lastLink){
        tempLink = tempLink->next;
        printf("%d\n", tempLink->value);
    }
    free(tempLink);
}


void addList(struct linkedList *lst, TYPE v)
{
    assert(lst != 0);
    _addLinkBefore(lst, lst->firstLink->next, v);

}


int containsList (struct linkedList *lst, TYPE e) {
    
    assert(lst != 0);
    assert(lst->size != 0);
    struct DLink* tempLink = (struct DLink *) malloc(sizeof(struct DLink));
    tempLink = lst->firstLink;
    while(tempLink->next != lst->lastLink){
        tempLink = tempLink->next;
        if(tempLink->value == e){
            free(tempLink);
            return(1);
        }
    }
    free(tempLink);
    return(0);

}


void removeList (struct linkedList *lst, TYPE e) {
    
    assert(lst != 0);
    assert(lst->size != 0);
    struct DLink* tempLink = (struct DLink *) malloc(sizeof(struct DLink));
    tempLink = lst->firstLink;
    while(tempLink->next != lst->lastLink){
        tempLink = tempLink->next;
        if(tempLink->value == e){
            _removeLink(lst, tempLink);
            free(tempLink);
        }
    }
    free(tempLink);
}