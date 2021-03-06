/* CS261- Assignment 1 - Q. 1*/
/* Name: Joshua Hesseltine
 * Date: 10/9/15
 * Solution description: struct primer
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

struct student
{
	int id;
	int score;
};

struct student* allocate()
{
     /*Allocate memory for ten students*/
     struct student *p = malloc(sizeof(struct student)*10);
     /*return the pointer*/
     return p;
}

void generate(struct student* students)
{
     int n = 10;
     int ids[n];
     int a, b;
     srand(time(NULL));

     for (int i = 0; i < n; ++i) ids[i] = i+1;
     for (int i = 0; i < 100; ++i)
     {
       a = rand()%10;
       b = rand()%10;
       swap(ids+a, ids+b);
     }
     for (int i = 0; i < n; ++i)
     {
       students[i].id = ids[i];
       students[i].score = rand()%100+1;
     }
}

void output(struct student* students)
{
     for (int i = 0; i < 10; ++i)
     {
       printf("%d %d\n", students[i].id, students[i].score);
     }
}

void summary(struct student* students)
{
     int min = students[0].score;
     int max = min;
     int sum = 0;
     int average = 0;

     for (int i = 1; i < 10; ++i)
     {  
       int tem = students[i].score;
       if (tem < min) min = tem;
       if (tem > max) max = tem;
       sum += tem;
     }
     average = sum/10;
     printf("Min: %d\nMax: %d\nAverage: %d\n", min, max, average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    assert(stud);
    free(stud);
}

// Swap two elements in a array
void swap(int* a, int* b)
{
  int tem = *a;
  *a = *b;
  *b = tem;
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
