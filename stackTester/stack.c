#include <stdio.h>
#include "stack.h"

    /* declare stack and other variables */
    /* to be used in program */
Info stack[80];
int stackCounter, stackLength;

void initStack(int strLength)
{
    stackCounter = 0;
    stackLength = strLength;
}   /* end function initStack */

int full()
{
    if (stackCounter == stackLength)
    {
        return 1; /* stack is full! */
    }
    else
    {
        return 0; /* stack is not full yet */
    }
}   /* end function full */

int notEmpty()
{
    if (stackCounter !=0)
    {
        return 1; /* stack is not empty */
    }
    else
    {
        return 0; /* stack is empty */
    }
}   /* end function notEmpty */

void push (char element)
{
    stack[stackCounter].oneChar = element;
    stackCounter++;
    printf("Pushed %c\n", element);
}   /* end function push */

char pop()
{
    char oneItem;

    --stackCounter;
    oneItem = stack[stackCounter].oneChar;
    printf("Popped: %c\n", oneItem);
    return oneItem;
}   /* end function pop */
