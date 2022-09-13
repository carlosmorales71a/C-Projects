#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct
{
    char oneChar;
}   Info;

    /* declare prototypes for functions */
    /* to be used in program */
void initStack(int);
int full();
int notEmpty();
void push(char);
char pop();

#endif
