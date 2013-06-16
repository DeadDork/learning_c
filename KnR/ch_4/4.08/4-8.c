////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 4-8.

// Tests a getch() and ungetch() that that only can manage to push/pull one
// character.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// External Variables

char buf; // Buffer for ungetch() (only one element)

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Get a (possibly pushed-back) character
int getch(void);

// Push character back
void ungetch(int);

////////////////////////////////////////////////////////////////////////////////
// Functions

int getch(void) {
    char c;

    if (buf > '\0') {
        c = buf;
        buf = '\0';
        return c;
    } else
        return getchar();
}

void ungetch(int c) {
    if (buf > '\0')
        printf("ungetch: buffer full\n");
    else
        buf = c;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
    int c;

    while ((c = getch()) != EOF) {
        if (c == '\n'); // Do nothing
        else if (c >= '0' && c <= '9') {
            ungetch(c);
            printf("[%c] is a number\n", getch());
        } else
            printf("[%c] is not a number\n", c);
    }

    return 0;
}
