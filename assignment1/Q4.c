/* CS261- Assignment 1 - Q. 4*/
/* Name: Joshua Hesseltine
 * Date: 10/9/15
 * Solution description: more sort
 */

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    int score;
};

void sort(struct student* students, int n)
{
     /*Sort the n students based on their score*/
    if (n <= 1) return;

    struct student p = students[n/2];
    struct student* l = students;
    struct student* r = students+n-1;
    
    while (l <= r)
    {
        if (l->score < p.score) {l++; continue;}
        if (r->score > p.score) {r--; continue;}
        struct student tem = *l;
        *l++ = *r;
        *r-- = tem;
    }
}

int main(){
    //struct student* stud = NULL;
    // /*Declare an integer n and assign it a value.*/
    //int n = 10;
    // /*Allocate memory for n students using malloc.*/
    //stud = allocate(n);
    // /*Generate random IDs and scores for the n students, using rand().*/
    //rand(stud,n);
    // /*Print the contents of the array of n students.*/
    //printf(stud,n);
    // /*Pass this array along with n to the sort() function*/
    //sort(stud,n);
    // /*Print the contents of the array of n students.*/
    //printf(stud,n);
    return 0;
}
