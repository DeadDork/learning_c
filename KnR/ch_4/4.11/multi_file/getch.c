////////////////////////////////////////////////////////////////////////////////
// Comments

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include "calc.h"

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STACK_DEPTH 100

////////////////////////////////////////////////////////////////////////////////
// External Variables

char getch_stack[MAX_STACK_DEPTH];
int getch_stack_depth = 0;

////////////////////////////////////////////////////////////////////////////////
// Functions

int getch(void) {
    return (getch_stack_depth > 0) ? getch_stack[--getch_stack_depth] : getchar();
}

void ungetch(int character) {
    if (getch_stack_depth >= MAX_STACK_DEPTH)
        printf("ungetch(): too many characters\n");
    else
        getch_stack[getch_stack_depth++] = character;
}
