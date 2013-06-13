////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out the reverse Polish calcultor in K & R, ch. 4.3.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define BUFSIZE 100 // Max buffer of "getching" stack
#define MAXOP 100 // Max size of operand or operator
#define MAXVAL 100 // Maximum depth of val stack
#define NUMBER '0' // Signal that a number was found

////////////////////////////////////////////////////////////////////////////////
// External Variables

char buf[BUFSIZE]; // Buffer for ungetch
int bufp = 0; // Next free position in buf
int sp = 0; // Next free stack position
double val[MAXVAL]; // Value stack

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Get next character or numeric operand
int getop(char []);

// Push a float onto value stack
void push(double);

// Pop and return top value from stack 
double pop(void);

// Get a (possibly pushed-back) character 
int getch(void);

// Push character back on input
void ungetch(int);

////////////////////////////////////////////////////////////////////////////////
// Functions

void push(double f) {
    if (sp < MAXVAL) 
        val[sp++] = f; 
    else 
        printf("error: stack full, can't push %g\n", f); 
} 

double pop(void) {
    if (sp > 0) 
        return val[--sp]; 
    else { 
        printf("error: stack empty\n"); 
        return 0.0; 
    } 
}

int getop(char s[]) {
    int i, c; 

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0'; 

    // Get number {{{

    // Check if input is a number
    if (!isdigit(c) && c != '.') 
        return c; // Not a number

    // Integral part
    i = 0; 
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));

    // Fractional part
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));

    // End string
    s[i] = '\0';

    // }}}
    
    if (c != EOF) 
        ungetch(c); 

    return NUMBER; 
} 

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) 
        printf ("ungetch: too many characters\n"); 
    else 
        buf[bufp++] = c; 
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}
