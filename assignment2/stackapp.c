/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamicArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
    char temp=*s;
    int testcap = 5;
    struct DynArr *balanceA = newDynArr(testcap);
    struct DynArr *balanceB = newDynArr(testcap);
    struct DynArr *balanceC = newDynArr(testcap);
    
    
    assert(s!=NULL);
    
    
    while(temp!='\0')
    {
        if (temp=='(')
            pushDynArr(balanceA,'a');
        else if (temp==')')
            popDynArr(balanceA);
        else if (temp=='{')
            pushDynArr(balanceB,'b');
        else if (temp=='}')
            popDynArr(balanceB);
        else if (temp=='[')
            pushDynArr(balanceC,'c');
        else if (temp==']')
            popDynArr(balanceC);
        else ;
        temp =nextChar(s);
        
    }
    
    printf("\n");
    /* FIXME: You will write this function */		
    if (isEmptyDynArr(balanceA)&&isEmptyDynArr(balanceB)&&isEmptyDynArr(balanceC))
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

