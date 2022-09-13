/******************************************************
 * Programmer:		Carlos Morales
 * Course: 			COSC 2436 Section 003
 * Semester: 		Spring 2021
 * Assignment #:	3
 * Due Date: 		2/17/2021
 ******************************************************/

#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
        /* declare variables to be used */
        /* in our program */
     char string[80], reverseString[80];
     char oneChar;
     int strLength, done = 0, i;

        /* enter do while loop to be read in */
        /* strings from the user until */
        /* user wishes to stop */
    do
    {
            /* prompt and read in string */
            /* from console. Then obtain */
            /* its length */
        printf("Please enter a string (or 'q' to quit):\n");
        fgets(string,80,stdin);
        strLength = strlen(string) - 1;

        printf("\nYou entered\n%s\n", string);
        printf("It's length is %d\n", strLength);

        /* does user want to quit? */
        if (strLength == 1 &&
            tolower(string[0]) == 'q')
        {
            done = 1;
        }   /* end if statement */
        else if (strLength == 0)
        {
            printf("\n\t***You must enter a string!***\n\n");
        }   /* end if else statement */
        else    /* valid string has been entered */
        {
                /* set up stack */
            initStack(strLength);

                /* traverse entire sentence that was */
                /* read and push each character onto */
                /* the stack */
            for (i = 0; i < strLength; i++)
            {
                    /* is the stack full? */
                if (full() == 1)
                {
                    printf("Can't push the character %c "
                           "on to stack!", string[i]);
                }   /* end if statement */

                else /* there is room to push the */
                {    /* character onto the stack */
                    if (string[i] != ' ')
                    {
                        push(string[i]);
                    }
                    else
                    {
                        push('*');
                    }
                }   /* end outer else statement */

            }   /* end for loop */
        }   /* end most outer else statement */

            /* proceed if we are not done */
        if (!done)
        {
            strcpy(reverseString, "");
            i = 0;

                /* pop off characters from the stack */
                /* and build a string (backwards) */
                /* with them */
            while (notEmpty())
            {
                oneChar = pop();
                reverseString[i] = oneChar;
                i++;
            }   /* end while loop */

                /* don't forget to add the */
                /* null character at the end */
                /* of our manually built string */
            reverseString[i] = '\0';
            printf("\n\nHere is the string reversed: %s\n",
                   reverseString);

        }   /* end if statement */

    } while (!done);

    printf("\nThis program was written by Carlos Morales.");
    printf("\nEnd of program.\n");

        /* exit program normally */
    return 0;
}   /* end function main */
