////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 4-7.

// Tests ungets(), which pushes back an entire string.

// I hate using external variables: they invite all kinds of bugs due to forcing
// the programmer to keep them in mind at all times (which is just so much of a
// PITA). As such, I adjusted ungetch() to return a value when buf[] is full--
// that is, ungets() should just use ungetch() rather than mess with buf[] &
// bufp.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define BUFSIZE 100 // Max buffer of "getching" stack
#define STRSIZE 200 // Max string (for multiple ungets()-ing)

////////////////////////////////////////////////////////////////////////////////
// External Variables

char buf[BUFSIZE]; // Buffer for ungetch
int bufp = 0; // Next free position in buf

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Get a (possibly pushed-back) character
int getch(void);

// Push character back on input
int ungetch(int);

// Reverses order of a string
void reverse(char []);

// Push back to input an entire string
void ungets(char []);

// Copy s[] to ss[]
void str_cpy(char s[], char ss[]);

////////////////////////////////////////////////////////////////////////////////
// Functions

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

int ungetch(int c) {
    if (bufp >= BUFSIZE)
        return 0;
    else {
        buf[bufp++] = c;
        return 1;
    }
}

void reverse(char s[]) {
    int i, max;
    char c;

    for (i = 0; s[i] != '\0'; ++i);
    max = i;
    for (i = 0; i < max / 2; ++i) {
        c = s[i];
        s[i] = s[max - (i + 1)];
        s[max - (i + 1)] = c;
    }
}

void ungets(char s[]) {
    int i = 0;

    reverse(s);
    while (s[i] != '\0'  && ungetch(s[i]))
        ++i;
}

void str_cpy(char s[], char ss[]) {
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        ss[i] = s[i];
    ss[i] = '\0';
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
    char s[STRSIZE], ss[STRSIZE];
    int i;

    for (i = 0; (s[i] = getch()) != EOF; ++i) {
        if (s[i] == '\n')
            --i; // Don't record newlines
        else if (i == STRSIZE - 1) {
            printf("\tString too long. Automatically clearing it... Now!\n");
            i = -1;
        } else if (i >= 5 && s[i - 5] == 'u' && s[i - 4] == 'n' && s[i - 3] == 'g' && s[i - 2] == 'e' && s[i - 1] == 't' && s[i] == 's') {
            // Ungets s[]
            i -= 6;
            s[i + 1] = '\0';
            str_cpy(s, ss); // Otherwise s[] is reversed in ungets()
            ungets(ss);
        } else if (i >= 4 && s[i - 4] == 'p' && s[i - 3] == 'r' && s[i - 2] == 'i' && s[i - 1] == 'n' && s[i] == 't') {
            // Prints s[]
            i -= 5;
            s[i + 1] = '\0';
            printf("%d:\t[%s]\n", i, s);
        } else if (i >= 4 && s[i - 4] == 'c' && s[i - 3] == 'l' && s[i - 2] == 'e' && s[i - 1] == 'a' && s[i] == 'r') {
            // Clears s[]
            bufp = 0;
            i = -1;
        }
    }

    return 0;
}
