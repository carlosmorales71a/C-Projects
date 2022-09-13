#include <stdio.h>
#include <string.h>
#include "info.h"

int main()
{
        /* declare variables to be */
        /* used in program */
    FILE *fp1;
    Info hollywoodStar;
    Info person;
    Info people[MAX];
    int i, num;

        /* enter a hollywood star's info */
    strcpy(hollywoodStar.firstName, "Tom");
    strcpy(hollywoodStar.lastName, "Hanks");
    hollywoodStar.age = 56;
    hollywoodStar.money = 1000000;

        /* open a file to be written to */
    if ((fp1 = fopen("sample.dat", "w")) == NULL)
    {
        printf("\nFile could not be opened "
               "for writing!\n");
        exit(1);
    }

        /* prompt and read in first name, */
        /* last name, age, and money amount. */
        /* Write the info to a file. Do this */
        /* for two respective people */
    for (i =0; i < 2; i++)
    {
        printf("\nPlease enter your first name: ");
        scanf("%s", person.firstName);

        printf("Please enter your last name: ");
        scanf("%s", person.lastName);

        printf("\nPlease enter your age: ");
        scanf("%d", &person.age);

        printf("\nPlease enter your money amount: ");
        scanf("%lf", &person.money);

            /* invoke the function 'writeFile' */
            /* to write this person's */
            /* info to file */
        writeFile(fp1, person);
    }   /* end for loop */

        /* close file */
    fclose(fp1);

        /* open file for appending */
    if ((fp1 = fopen("sample.dat", "a")) == NULL)
    {
      printf("\nFile could not be open for appending!\n");
      exit(1);
    }

        /* append Hollywood star's info to the file */
    fprintf(fp1, "%-15s\t%-12s\t%d\t%.2lf\n",
                    hollywoodStar.lastName,
                    hollywoodStar.firstName,
                    hollywoodStar.age,
                    hollywoodStar.money);

    printf("\nAppended this Hollywood "
           "star's info to a file:\n");

    printf("%-15s\t%-12s\t%d\t%.2lf\n",
                    hollywoodStar.lastName,
                    hollywoodStar.firstName,
                    hollywoodStar.age,
                    hollywoodStar.money);

        /* close the file */
    fclose(fp1);

        /* open file for reading */
    if ((fp1 = fopen("sample.dat", "r")) == NULL)
    {
        printf("\nFile could not be opened "
               "for reading!\n");
        exit(1);
    }

        /* invoke the function 'readFile' to read */
        /* from the file all the people's info */
    readFile(fp1, people, &num);

        /* close the file */
    fclose(fp1);

        /* invoke the function 'printArray' */
        /* to print out info from */
        /* array of 'people' */
    printArray(people, num);

    printf("\nThis program was written by Carlos Morales.");
    printf("\nEnd of program.\n");

    return 0;   /* end program normally */
}   /* end function main */
