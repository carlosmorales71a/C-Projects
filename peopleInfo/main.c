/******************************************
 * Programmer:      Carlos Morales
 * Course:          COSC 1437 Section 004
 * Semester:        Summer 2019
 * Assignment #:    20
 * Due Date:        July 30, 2019
 ******************************************/

#include <stdio.h>
#include <string.h>
#include "info.h"

int main()
{
        /* declare variables to be used */
        /* in program */
    Info onePerson, somebody;
    int i;

        /* enter first name. age, and */
        /* money for two separate people */
    for (i = 0; i < 2; i++)
    {
        printf("\n\nPlease enter your first name: ");
        scanf("%s", onePerson.firstName);

        printf("Please enter your age: ");
        scanf("%d", &onePerson.age);

        printf("Please enter the amount of money "
               "you have in your pocket: ");
        scanf("%lf", &onePerson.money);

            /* send structure to be updated via */
            /* pass by reference/address, then */
            /* print out results */
        update(&onePerson);
        printf("%s %d %.2lf", onePerson.firstName,
               onePerson.age, onePerson.money);

    }   /* end for loop */

        /* send last structure info to */
        /* construct a new person, then */
        /* print out the results; send via */
        /* pass by value */
    somebody = updateAgain(onePerson);
    printf("\n\nYou are now: %s %d %.2lf\n",
           somebody.firstName, somebody.age,
           somebody.money);

    printf("\nThis program was written by Carlos Morales.\n");
    printf("End of program.\n");

    return 0;   /* end program normally */
}   /* end function main */
