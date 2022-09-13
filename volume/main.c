#include <stdio.h>

#define PI 3.14159    /* identifier/constant for the number PI */

int main(void)
{
        /*declare variables to be used in our program */
    double volume, radius;

        /* prompt the user to enter the */
        /* radius, then read it in */
    printf("Enter the radius of sphere: ");
    scanf("%lf", &radius);

        /* calculate the volume of the */
        /* sphere and then print it out */
    volume = (4.0/3.0) * PI * radius * radius * radius;
    printf("\nThe volume of the sphere with a %.2lf "
           "meter radius is %.4lf cubic meters.",
           radius, volume);

    printf("\nThis program was written by Carlos Morales.");
    printf("\nEnd of program.");

    return 0; /* end program normally */
} /* end function main */
