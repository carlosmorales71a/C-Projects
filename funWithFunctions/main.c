/******************************************
 * Programmer:      Carlos Morales
 * Course:          COSC 1437 Section 004
 * Semester:        Summer 2019
 * Assignment #:    15
 * Due Date:        July 17, 2019
 ******************************************/

#include <stdio.h>

#define N 5 /* identifier/constant for array size */

    /* prototype for our functions */
int addThem(int, int);
void modifyThem(int, int);
int modifyArray(int[], int);

int main()
{
        /* declare variables to be used */
    int i, x, y, answer;
    int numbers[N] = {10, 15, 3, 5, 2};

        /* prompt the user to enter two numbers */
        /* then read them in */
    printf("Please enter two numbers:\n");
    scanf("%d %d", &x, &y);

    printf("\nBefore invoking 'addThem'. x is %d,"
           "y is %d\n", x, y);

        /* invoke the function 'addThem' to add */
        /* x and y, then return the answer */
    answer = addThem(x,y);

    printf("After invoking 'addThem'. %d plus "
           "%d is %d\n", x, y, answer);

    /*******************************************************/

    printf("\n\nBefore invoking 'modifyThem'. x is %d "
           "and y is %d\n", x, y);

           /* test to see if you can modify x and y */
           /* in the function 'modifyThem' */
           /* pass the arguments via pass by value */
    modifyThem(x,y);

    printf("After invoking 'modifyThem'. x is %d "
           "and y is %d\n", x, y);

    /*******************************************************/

    printf("\nBefore invoking 'modifyArray' the "
           "number in the array are:\n");

    for (i = 0; i < N; i++)
    {

        printf("index %d of array has %d\n",
               i, numbers[i]);
    }   /* end for loop */

    /* invoke the function 'modifyArray' to */
    /* modify each element and return back */
    /* its summation */
    answer = modifyArray (numbers, N);

    printf("\nAfter invoking 'modifyArray' the "
           "numbers in the array are:\n");

    for (i = 0; i < N; i++)
    {
        printf("index %d of array has %d\n",
               i, numbers[i]);
    }   /* end for loop */

    printf("\nSummation of modified array %d\n",
           answer);

    printf("\nThis program was written by Carlos Morales.\n");
    printf("End of program.\n");

    return 0;   /* end program normally */
}   /* end function main */

int addThem(int a, int b)
{
    int localAnswer;

    localAnswer = a + b;
    return localAnswer;
}   /* end function addThem */

void modifyThem(int a, int b)
{

    a = a + 10;
    b = b + 7;
    printf("Inside function 'modifyThem'. x is %d "
           "and y is %d\n", a, b);
}   /* end function modifyThem */

int modifyArray(int numbers[], int n)
{
    int i, sum;

    sum = 0;

    for (i = 0; i < n; i++)
    {
        numbers[i] = numbers[i] * 2;
        sum = sum + numbers[i];
    }   /* end for loop */

    return sum;
}   /* end function modifyArray */
