/**********************************************************
// Programmer:		Carlos Morales
// Course:          COSC 2436 Section 003
// Semester: 		Spring 2021
// Assignment #:	7
// Due Date: 		03/24/2021
**********************************************************/

#include <stdio.h>
#include <string.h>
#include "link2.h"

int main()
{
        /* declare variables to be */
        /* used in the program */
    char name[15];
    char inputChar, operation;
    int done = 0;
    int valid = 1, badOperation;

        /* invoke 'initList' to */
        /* populate the linked list */
    initList();

        /* print out the current linked list */
    printList();

        /* enter do-while to add/delete */
        /* to/from the linked list */
    do
    {
        printf("\nPlease enter a letter (or 'q' to quit)\n");
        inputChar = getc(stdin);
        getc(stdin);

            /* convert character to lower case */
        inputChar = tolower (inputChar);
        printf("You selected the character %c\n",
               inputChar);

        if (inputChar == 'q')
        {
            done = 1;
        }
        else
        {
            valid = validCharacter(inputChar);

            if (valid == 0)
            {
                    /* Error! Invalid character was entered */
                printf("\n\t***You must enter a "
                       "valid character!***\n\n");
            }   /* end if statement */
            else
            {
                do
                {
                    printf("\nWould you like to add or "
                           "delete this character? (a/d)\n");
                    operation = getc(stdin);
                    getc(stdin);
                    operation = tolower(operation);

                        /* add a node */
                    if  (operation == 'a')
                    {
                     add(createNewNode(inputChar));
                     badOperation = 0;
                    }
                        /* delete a node */
                    else if (operation == 'd')
                    {
                        delete(inputChar);
                        badOperation = 0;
                    }

                        /* invalid operation */
                    else
                    {
                        printf("\n\t***Invalid operation. "
                               "Please try again!***\n");
                        badOperation = 1;
                    }

                } while (badOperation);

                    /* print out current linked list */
                printList();
            }   /* end else statement */


        }   /* end else statement */

    } while (!done);

    printf("\nThis program was written by Carlos Morales.");
    printf("\nEnd of program.");

        /* exit program normally */
    return 0;
}       /* end function main */
