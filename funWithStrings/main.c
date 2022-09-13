#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    /* declare prototypes for our functions */
void compareNames(char [], char []);
void convertToUpperCase(char [], int, int);
void substring(int, int, char [], char []);

int main()
{
        /* declare variables to be used */
        /* in program */
    int i, lenFirst, lenLast, num1, num2;
    int temp;
    char firstName[10], lastName[12];
    char fullName1[30], fullName2[30];
    char middle[10], mInitial[2];
    char newString[30];

    srand(time (NULL));

        /* prompt the user to enter their */
        /* first, last and middle name; then */
        /* read them in from the keyboard */
    printf("Please enter your first name: ");
    scanf("%s", firstName);

    printf("Please enter your last name: ");
    scanf("%s", lastName);

    printf("Please enter your middle name.\n");
    printf("\tIf you don't have a middle name ");
    printf("enter 'X': ");
    scanf("%s", middle);

        /* create a middle initial from */
        /* the middle name */
    mInitial[0] = middle[0];
    mInitial[1] = '\0'; /* add in null character */

        /* obtain length of the first */
        /* and last name, respectively, */
        /* then print them out */
    lenFirst = strlen(firstName);
    lenLast = strlen(lastName);
    printf("\nLength of the first name is %d\n"
           "Length of last name is %d\n",
           lenFirst, lenLast);

        /* build up the first name consisting of */
        /* the first, middle initial, and */
        /* last name. Then copy it to another */
        /* string. Then print them out */
    strcpy(fullName1, firstName);
    strcat(fullName1, " ");
    strcat(fullName1, mInitial);
    strcat(fullName1, " ");
    strcat(fullName1, lastName);
    strcpy(fullName2, fullName1);

        /* invoke the function 'compareNames' */
        /* to compare the two names */
    compareNames(fullName1, fullName2);

        /* convert first full name to all */
        /* upper case. Then print it out */
    convertToUpperCase(fullName1, lenFirst, lenLast);

        /* invoke the function 'compareNames' */
        /* again to compare the two names */
    compareNames(fullName1, fullName2);

        /* generate three separate substrings from */
        /* the first full name string by invoking */
        /* the newly created function 'substring' */
        /* and then print them out */
    for (i =0; i < 3; i++)
    {
        num1 = rand() % (lenFirst +lenLast + 3);
        num2 = rand() % (lenFirst +lenLast + 3);

        if (num2 < num1)
        {
            temp = num1;
            num1 = num2;
            num2 = temp;
        }

            /* invoke the function 'substring' to */
            /* acquire a new sub string. Then */
            /* print it out */
        substring(num1, num2, fullName1, newString);
        printf("\nOriginal string: %s\n", fullName1);
        printf("Substring of %d to %d is %s\n",
               num1, num2, newString);

    }   /* end for loop */

    printf("\nThis program was written by Carlos Morales.\n");
    printf("End of Program.\n");

    return 0;   /* end program normally */
}   /* end function main */

void substring(int start, int end, char name[],
               char newString[])
{
    int i, j;

    j = 0;

    for (i = start; i <= end; i++)
    {
        newString[j] =name[i];
        j++;
    }   /* end for loop */

        /* add null character to */
        /* terminate the string */
    newString[j] = '\0';

} /* end function substring */

void convertToUpperCase(char name[], int lenFirst,
                        int lenLast)
{
    int i;

        /* convert the first full name to all */
        /* upper case. Then print it out */
    for (i = 0; i < (lenFirst + lenLast + 3); i++)
    {
        name[i] = toupper(name[i]);
    }   /* end for loop */

    printf("\nNow the name has been changed "
           "to %s\n", name);

}   /* emd function convertToUpperCase */

void compareNames(char name1[], char name2[])
{
    printf("\nGoing to compare the following "
           "names");
    printf("\nname1: %s , and name2: %s\n",
           name1, name2);

    if (strcmp(name1, name2) == 0)
    {
        printf("\nBoth full names are the same!\n\n");
    }   /* end if statement */
    else if (strcmp(name1, name2) < 0)
    {
        printf("\nname1 is less than name2: "
               "%s and %s\n\n",
               name1, name2);
    }   /* end else if statement */
    else
    {
        printf("\nname1 is greater than name2: "
               "%s and %s\n\n",
               name1, name2);
    }   /* end else statement */

}   /* end compareNames function */
