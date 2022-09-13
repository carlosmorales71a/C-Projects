#include "info.h"

void writeFile(FILE *fp1, Info person)
{
        /* write person's info to file */
    fprintf(fp1, "%-15s\t%-12s\t%d\t%.2lf\n",
            person.lastName, person.firstName,
            person.age, person.money);

    printf("\nWrote this person's info "
           "to a file:\n");
    printf("%s\t%s\t%d\t%.2lf\n",
            person.lastName, person.firstName,
            person.age, person.money);
} /* end function writeFile */

void readFile(FILE *fp1, Info people[], int *num)
{
    char line[80];
    int i = 0;

    *num = 0;
    printf("\nGoing to read people info "
           "from file and store them "
           "into an array.\n");

        /* read an entire line from the file */
    while (fgets(line, 80, fp1) != NULL)
    {
        sscanf(line, "%s%s%d%lf",
               people[i].lastName,
               people[i].firstName,
               &people[i].age,
               &people[i].money);

            /* update our subscript */
        i++;

            /* keep track of how many*/
            /* people there being */
            /* read from the file and */
            /* being inserted into the */
            /* array 'people' */
        (*num)++;

    }   /* end while loop */

}   /* end function readFile */

void printArray(Info identity[], int n)
{
    int i;

    printf("\nGoing to print people info "
           "that was read from the file "
           "and was stored into an array.\n");

            /* print out a nice header */
    printf("\nLast Name\tFirst Name\tAge\tMoney\n");

    for (i =0; i < n; i++)
    {
        printf("%-15s\t%-12s\t%d\t$%.2lf\n",
                identity[i].lastName,
                identity[i].firstName,
                identity[i].age,
                identity[i].money);
    } /* end for loop */
} /* end function printArray */
