#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    /* declare a constant of size */
    /* five for array size */
#define MAX 5

    /* declare prototypes for our functions */
void payAmount(int, int *, int *, int *, int *);
void populateArray(int [], int);
void printArray1(int [], int);
void updateTwoElements(int *,
                       int, int);

int main()
{
    /* declare variables to be used in program */
    int amount, twenties, tens, fives, ones;
    int numbers[MAX], first, second;
    int *ptr;

    srand(time (NULL));

        /* prompt the user to enter a dollar amount */
        /* (an integer) then read it in */
    printf("Enter a dollar amount (an integer): ");
    scanf("%d", &amount);

        /* invoke the function 'payAmount' to */
        /* calculate the amount of bills to return */
        /* to user. Pass 'amount' via pass-by-value */
        /* and all other variables via*/
        /* pass-by-reference (address) */
    payAmount(amount, &twenties, &tens, &fives, &ones);

        /* print out the amount of bills */
    printf("\nYour equivalent amount of bill for "
           "%d dollars is:\n", amount);
    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("$1 bills: %d\n", ones);

        /* just for fun assign the pointer "ptr' */
        /* to point to the variable 'tens' and */
        /* print out its value. Then print out */
        /* the address to which 'ptr' is pointing */
        /* to and compare it to the address of 'tens' */
    ptr = &tens;
    printf("Using a pointer, there are %d ten dollar "
           "bills\n", *ptr);
    printf("Printing the pointer's address to where it "
           "is pointing to %d and where 'tens' is "
           "located %d\n",
           ptr, &tens);

           /* invoke the function 'popularArray' */
           /* fill the array with random numbers */
    populateArray(numbers, MAX);

        /* invoke the function 'printArray1' */
        /* to print out the array elements */
        /* in a normal fashion */
    printArray1(numbers, MAX);

        /* invoke the function 'printArray2' */
        /* to print out the array elements */
        /* in a different way via pointers */
    printArray2(numbers, MAX);

        /* randomly select two numbers that */
        /* will represent two subscripts */
        /* for the array 'numbers' */
    first = rand() % MAX;
    second = rand() % MAX;

        /* invoke the function 'updatetTwoElements' */
        /* to modify the elements at position */
        /* 'first' and 'second' of the array */
        /* 'numbers' */
    updateTwoElements(numbers, first, second);

        /* print out the two elements of the */
        /* array 'numbers' that were modified */
    printf("\nBack in function main\n");
    printf("Element %d is now %d\n",
           first, numbers[first]);
    printf("Element %d is now %d\n",
           second, numbers[second]);

    printf("\n\nThis program was written by Carlos Morales.");
    printf("\nEnd of program.\n");


    return 0;   /* end program normally */
}   /* end function main */

void updateTwoElements(int *numbers,
                       int first, int second)
{
    printf("\nInside updateTwoElements\n");
    printf("Will be updating elements via pointers.\n");

    *(numbers + first) = (rand() % 100) + 1;
    *(numbers + second) = (rand() % 100) + 1;

    printf("Changed element %d to %d\n",
           first, *(numbers + first));

    printf("Changed element %d to %d\n",
           second, *(numbers + second));
}   /* end function updateTwoElements */

void printArray1(int numbers[], int n)
{
    int i;

    printf("\nInside printArray1\n");
    printf("Will be printing array in "
           "a normal fashion.\n");

        /* print out all the elements */
        /* of the array 'numbers' in a */
        /* normal fashion */
    for (i = 0; i < n; i++)
    {
        printf("Element %d has: %d\n",
               i, numbers[i]);
    }   /* end for loop */

}   /* end function printArray1 */

void printArray2(int *numbers, int n)
{
    int i;

    printf("\nInside printArray2\n");
    printf("Will be printing array "
           "via pointers.\n");

        /* print out all the elements */
        /* of the array 'numbers' in a */
        /* different ways using pointers */
    for (i = 0; i < n; i++)
    {
        printf("Element %d has: %d\n",
               i, *(numbers)++);
    }   /* end for loop */

}   /* end function printArray2 */

void populateArray(int numbers[], int n)
{
    int i;

        /* using a random number generator */
        /* populate the array 'numbers' */
    for (i = 0; i < n; i++)
    {
        numbers[i] = (rand() % 100) + 1;
    }   /* end for loop */

}   /* end function populateArray */

void payAmount(int dollars, int *twenties,
               int *tens, int *fives, int *ones)
{
        /* obtain twenties, tens, fives */
        /* and one dollar bills */
    *twenties = dollars / 20;
    dollars = dollars % 20;

    *tens = dollars / 10;
    dollars = dollars % 10;

    *fives = dollars / 5;
    dollars = dollars % 5;

    *ones = dollars;
}   /* end function payAmount */
