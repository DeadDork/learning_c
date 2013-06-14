////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 4-5.

// Adds access to common <math.h> functions.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define BUFSIZE 100 // Max buffer of "getching" stack
#define MAXOP 100 // Max size of operand or operator
#define MAXVAL 100 // Maximum depth of val stack
#define NOMATCH 0 // False return value for match()
#define MATCH 1 // True return value  for match()

// Operators
enum ops_t {
    NUMBER,
    SIN,
    COS,
    TAN,
    ASIN,
    ACOS,
    ATAN,
    ATAN2,
    SINH,
    COSH,
    TANH,
    EXP,
    LOG,
    LOG10,
    POW,
    SQRT,
    CEIL,
    FLOOR,
    FABS,
    LDEXP,
    FMOD,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    PRINT,
    DUP,
    CLR,
    SWAP,
    NL,
    FILEEND,
    ERROR
};

////////////////////////////////////////////////////////////////////////////////
// External Variables

char buf[BUFSIZE]; // Buffer for ungetch
int bufp = 0; // Next free position in buf
int sp = 0; // Next free stack position
double val[MAXVAL]; // Value stack

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Push a float onto value stack
void push(double);

// Pop and return top value from stack
double pop(void);

// Determines whether two strings are identical
int strcomp(char s[], char ss[]);

// Match operators to an ops type
enum ops_t match(char s[]);

// Get next character or numeric operand
enum ops_t getop(char []);

// Get a (possibly pushed-back) character
int getch(void);

// Push character back on input
void ungetch(int);

// Prints all values in the value stack
void printstack(void);

// Takes the top most value in the stack and duplicates it
void duplicate(void);

// Clears the stack
void clearstack(void);

// Swaps the values of the top two values in the stack
void swap(void);

// Executes calc commands
void exec(char s[], enum ops_t op);

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

int strcomp(char s[], char ss[]) {
    int i;

    for (i = 0; s[i] != '\0' && ss[i] != '\0' && s[i] == ss[i]; ++i);

    if (s[i] == ss[i])
        return MATCH;
    else
        return NOMATCH;
}

enum ops_t match(char s[]) {
    if (strcomp(s, "sin"))
        return SIN;
    else if (strcomp(s, "cos"))
        return COS;
    else if (strcomp(s, "tan"))
        return TAN;
    else if (strcomp(s, "asin"))
        return ASIN;
    else if (strcomp(s, "acos"))
        return ACOS;
    else if (strcomp(s, "atan"))
        return ATAN;
    else if (strcomp(s, "atan2"))
        return ATAN2;
    else if (strcomp(s, "sinh"))
        return SINH;
    else if (strcomp(s, "cosh"))
        return COSH;
    else if (strcomp(s, "tanh"))
        return TANH;
    else if (strcomp(s, "exp"))
        return EXP;
    else if (strcomp(s, "log"))
        return LOG;
    else if (strcomp(s, "log10"))
        return LOG10;
    else if (strcomp(s, "pow"))
        return POW;
    else if (strcomp(s, "sqrt"))
        return SQRT;
    else if (strcomp(s, "ceil"))
        return CEIL;
    else if (strcomp(s, "floor"))
        return FLOOR;
    else if (strcomp(s, "fabs"))
        return FABS;
    else if (strcomp(s, "ldexp"))
        return LDEXP;
    else if (strcomp(s, "fmod"))
        return FMOD;
    else if (strcomp(s, "+"))
        return PLUS;
    else if (strcomp(s, "*"))
        return MULT;
    else if (strcomp(s, "/"))
        return DIV;
    else if (strcomp(s, "%"))
        return MOD;
    else if (strcomp(s, "prnt"))
        return PRINT;
    else if (strcomp(s, "dup"))
        return DUP;
    else if (strcomp(s, "clr"))
        return CLR;
    else if (strcomp(s, "swp"))
        return SWAP;
    else if (strcomp(s, "\n"))
        return NL;
    else if (s[0] == EOF)
        return FILEEND;
    else
        return ERROR;
}

enum ops_t getop(char s[]) {
    int i, c;

    // Clear whitespace & get number/operation
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    // Get operator (if any) {{{

    // Match operator to return value
    if (!isdigit(c) && c != '-' && c != '.') {
        if (c != '\n' && c != EOF) {
            for (i = 1; i < BUFSIZE - 1 && islower(s[i] = c = getch()); ++i);
            ungetch(c);
            s[i] = '\0';
        }
        return match(s);
    }

    // Determine whether a '-' is a negative sign or a subtraction
    if (c == '-') {
       if (!isdigit(c = getch()))
           return MINUS; // A subtraction
       else {
           s[1] = c;
           i = 1;
       }
    } else
        i = 0;

    // }}}

    // Get number {{{

    // Integral part
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
    else
        return FILEEND;

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

void printstack(void) {
    int c, i;

    // Eats '\n'
    c = getch();
    if (c != '\n')
        ungetch(c);

    if (sp > 0)
        for (i = 0; i < sp; ++i)
            printf("\tvalue_stack[%d] = %f\n", i, val[i]);
    else
        printf("error: stack empty\n");
}

void duplicate(void) {
    int c;
    double d;

    // Eats '\n'
    c = getch();
    if (c != '\n')
        ungetch(c);

    if (sp > 1) {
        d = pop();
        pop();
        push(d);
        push(d);
    } else
        printf("error: not enough values in stack\n");
}

void clearstack(void) {
    int c;

    // Eats '\n'
    c = getch();
    if (c != '\n')
        ungetch(c);

    sp = 0;
}

void swap(void) {
    double d;
    int c;

    // Eats '\n'
    c = getch();
    if (c != '\n')
        ungetch(c);

    if (sp > 1) {
        d = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = d;
    } else
        printf("error: not enough values in stack\n");
}

void exec(char s[], enum ops_t op) {
    double op2;

    switch (op) {
        case NUMBER:
            push(atof(s));
            break;
        case SIN:
            push(sin(pop()));
            break;
        case COS:
            push(cos(pop()));
            break;
        case TAN:
            push(tan(pop()));
            break;
        case ASIN:
            push(asin(pop()));
            break;
        case ACOS:
            push(acos(pop()));
            break;
        case ATAN:
            push(atan(pop()));
            break;
        case ATAN2:
            push(atan2(pop(), pop()));
            break;
        case SINH:
            push(sinh(pop()));
            break;
        case COSH:
            push(cosh(pop()));
            break;
        case TANH:
            push(tanh(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case LOG:
            push(log(pop()));
            break;
        case LOG10:
            push(log10(pop()));
            break;
        case POW:
            push(pow(pop(), pop()));
            break;
        case SQRT:
            push(sqrt(pop()));
            break;
        case CEIL:
            push(ceil(pop()));
            break;
        case FLOOR:
            push(floor(pop()));
            break;
        case FABS:
            push(fabs(pop()));
            break;
        case LDEXP:
            push(ldexp(pop(), (int)pop()));
            break;
        case FMOD:
            push(fmod(pop(), pop()));
            break;
        case PLUS:
            push(pop() + pop());
            break;
        case MINUS:
            op2 = pop();
            push(pop() - op2);
            break;
        case MULT:
            push(pop() * pop());
            break;
        case DIV:
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case MOD:
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;
        case PRINT:
            printstack();
            break;
        case DUP:
            duplicate();
            break;
        case CLR:
            clearstack();
            break;
        case SWAP:
            swap();
            break;
        case NL:
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
    enum ops_t type;
    char s[MAXOP];

    while ((type = getop(s)) != FILEEND) {
        exec(s, type);
    }

    return 0;
}
