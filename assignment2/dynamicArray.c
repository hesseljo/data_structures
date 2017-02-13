/* CS261- Assignment 2 - Q. 0*/
/* Name: Joshua Hesseltine
 * Date: 10/18/15
 * Solution description: Dynamic Array implementation */

#include <assert.h>
#include <stdlib.h>
#include "dynamicArray.h"


struct DynArr
{
    TYPE *data;		/* pointer to the data array */
    int size;		/* Number of elements in the array */
    int capacity;	/* capacity ofthe array */
    
    int beginning;
};

int _absoluteIndex (DynArr *v , int idx);

void initDynArr(DynArr *v, int capacity)
{
    assert(capacity > 0);
    assert(v!= 0);
    v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
    assert(v->data != 0);
    v->size = 0;
    v->capacity = capacity;
    v->beginning = 0;
    
}

DynArr* newDynArr(int cap)
{
    assert(cap > 0);
    DynArr *r = (DynArr *)malloc(sizeof( DynArr));
    assert(r != 0);
    initDynArr(r,cap);
    return r;
}

void freeDynArr(DynArr *v)
{
    if(v->data != 0)
    {
        free(v->data);
        v->data = 0;
    }
    v->size = 0;
    v->capacity = 0;
    v->beginning = 0;
}

void deleteDynArr(DynArr *v)
{
    freeDynArr(v);
    free(v);
}

void _dynArrSetCapacity(DynArr *v, int newCap)
{
    
    int i;
    
    TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
    assert(newData != 0);

    for(i = 0; i <  v->size; i++)
    {
        newData[i] = v->data[pDex(v,i)];
    }
    
    for(i = v->size; i < newCap; i++)
        newData[i] = 0;
    free(v->data);
    v->data = newData;
    v->capacity = newCap;
    v->beginning = 0;
}

int sizeDynArr(DynArr *v)
{
    return v->size;
}

void addDynArr(DynArr *v, TYPE val)
{
    if (v->size >= v->capacity)
        _dynArrSetCapacity(v, 2*v->capacity);
    
    v->data[pDex(v, v->size)] = val;
    v->size++;
    
}

TYPE getDynArr(DynArr *v, int pos)
{
    
    assert(pos < v->size);
    assert(pos >= 0);
    
    return v->data[pDex(v, pos)];
}


void putDynArr(DynArr *v, int pos, TYPE val)
{
    assert(pos < v->size);
    assert(pos >= 0);
    v->data[pDex(v,pos)] = val;
}

void swapDynArr(DynArr *v, int i, int  j)
{
    
    TYPE  temp;
    
    assert(i < v->size);
    assert(j < v->size);
    assert(i >= 0);
    assert(j >= 0);
    
    temp = v->data[pDex(v,i)];
    v->data[pDex(v,i)] = v->data[pDex(v,j)];
    v->data[pDex(v,j)] = temp;
    
}

void removeAtDynArr(DynArr *v, int idx)
{
    
    int i;
    
    assert(idx < v->size);
    assert(idx >= 0);
    
    for(i = idx; i <= v->size-2; i++)
    {
        v->data[pDex(v,i)] = v->data[pDex(v,i+1)];
    }
    
    v->size--;
    
}



/* ************************************************************************
	Stack Interface Functions
 ************************************************************************ */


int isEmptyDynArr(DynArr *v)
{
    return !(v->size);
}

void pushDynArr(DynArr *v, TYPE val)
{
    addDynArr(v, val);
}

TYPE topDynArr(DynArr *v)
{
    assert(!isEmptyDynArr(v));
    return v->data[pDex(v, v->size-1)]; //logical stack top is at size-1
}

void popDynArr(DynArr *v)
{
    assert(! isEmptyDynArr(v));
    v->size--;
}

/* ************************************************************************
	Bag Interface Functions
 ************************************************************************ */

int containsDynArr(DynArr *v, TYPE val)
{
    int i = 0;
    assert(!isEmptyDynArr(v));
    
    for(i = 0; i < sizeDynArr(v); i++)
        if(EQ(v->data[pDex(v,i)], val) )
            return 1;
    return 0;
    
}

void removeDynArr(DynArr *v, TYPE val)
{
    int i = 0;
    
    assert(!isEmptyDynArr(v));
    
    for(i = 0; i < sizeDynArr(v); i++)
        if(EQ(v->data[pDex(v,i)], val))
        {
            removeAtDynArr(v,i);
            break;
        }
}

#define MOD
#ifdef OFFSET
int pDex (DynArr *v , int idx)
{
    int offset = v->beginning + idx;
    int absIndex = offset;
    
    if(offset < 0)
        absIndex = offset + v->capacity;
    if(offset >= v->capacity)
        absIndex = offset - v->capacity;
    return absIndex;
}
#endif
#ifdef MOD
int pDex(DynArr *v, int lindex)
{
    assert(v!=0);
    return((lindex + v->beginning) % v->capacity);
}
#endif


