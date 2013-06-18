////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 4-9.

// Fixes getch() and ungetch() EOF handling.

// N.B. This is the dumbest program I have written in ages.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define BUFSIZE 100 // Max buffer of "getching" stack

////////////////////////////////////////////////////////////////////////////////
// External Variables

int buf[BUFSIZE]; // Buffer for ungetch
int bufp = 0; // Next free position in buf

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Get a (possibly pushed-back) character
int getch(void);

// Push character back on input
void ungetch(int);

// Dump buffer to STDOUT
void dump(void);

////////////////////////////////////////////////////////////////////////////////
// Functions

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf ("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void dump(void) {
    int i;

    for (i = 0; i < bufp; ++i)
        putchar(buf[i]);
    putchar('\n');
    bufp = 0;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
    int c;

    while (1) {
        printf("Put input into buffer:\n\t");
        while (bufp <= BUFSIZE && (c = getchar()) != EOF && c != '\n')
            ungetch(c);
        if (c == EOF) {
            dump();
            break;
        } else {
            if (bufp == BUFSIZE)
                printf("Buffer full. You should dump it's contents.\n");
            printf("Dump buffer [y/n]? ");
            if ((c = getchar()) == 'y' || c == 'Y')
                dump();
            getchar(); // Eat up '\n'
        }
    }

    return 0;
}
