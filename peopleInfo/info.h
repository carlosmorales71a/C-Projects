#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

 /* define typedef struct */
    /* to hold information */
    /* about a person */
typedef struct
{
    char firstName[20];
    int age;
    double money;
}   Info;

    /* declare prototypes for functions */
    /* to be used in our program */
void update(Info *);
Info updateAgain (Info);
#endif
