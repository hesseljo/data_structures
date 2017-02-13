/* CS261- Assignment 1 - Q. 3*/
/* Name: Joshua Hesseltine
 * Date: 10/9/15
 * Solution description: sort array
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
  int tem = *a;
  *a = *b;
  *b = tem;
}

void sort(int* number, int n)
{
     /*Sort the given array number , of length n*/    
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (number[i] > number[j]) swap(number+i, number+j);	
		}
	}
}

int main()
{
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *a = malloc(sizeof(int)*n);
    /*Fill this array with random numbers between 0 and n, using rand().*/
    srand(time(NULL));
    for (int i = 0; i < n; ++i) a[i] = rand()%n;
    /*Print the contents of the array.*/
    for (int i = 0; i < n; ++i) printf("a[%d] = %d\n", i, a[i]);
    /*Pass this array along with n to the sort() function.*/
	sort(a, n);
    /*Print the contents of the array.*/    
    for (int i = 0; i < n; ++i) printf("a[%d] = %d\n", i, a[i]);
    
    return 0;
}
