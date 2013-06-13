////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 4-2.

// Extends atof(), so that it can handle scientific notation.

// N.B. I'm fucking tired of documenting my code as heavily as I have been.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLINE 1000 // Stupid arbitrary string length

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Read a line from stdin
int getlin(char line[], int maxline);

// Exponentiate a base to a power.
double expon(double base, int exponent);

// Convert ASCII to float.
double atof(char string[]);

////////////////////////////////////////////////////////////////////////////////
// Functions

int getlin(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

double expon(double x, int y) {
    double t = x;

    if (y < 0)
        while (y++ <= 0)
            x /= t;
    else if (y > 0)
        while (--y >= 1)
            x *= t;
    else
        x = 1.0;

    return x;
}

double atof(char s[]) {
    double val, power; 
    int exp, expsign, i, sign; 

    // Skip white space
    for (i = 0; isspace(s[i]); i++);

    // Sign
    sign = (s[i] == '-') ? -1 : 1; 
    if (s[i] == '+' || s[i] == '-') 
        i++; 

    // Integer part
    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + (s[i] - '0'); 

    // Fractional part
    if (s[i] == '.') 
        i++; 
    for (power = 1.0; isdigit(s[i]); i++) { 
        val = 10.0 * val + (s[i] - '0'); 
        power *= 10; 
    } 

    // Scientific notation {{{
    if (s[i] == 'e' || s[i] == 'E')
        i++;

    // Exponent sign
    expsign = (s[i] == '-') ? -1 : 1; 
    if (s[i] == '+' || s[i] == '-') 
        i++; 

    // Exponent
    for (exp = 0; isdigit(s[i]); i++)
        exp = 10 * exp + (s[i] - '0');
    // }}}

    return sign * val / power * expon(10.0, expsign * exp);
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
    char line[MAXLINE];
    double sum = 0; 

    // Simple calculator
    while (getlin(line, MAXLINE) > 0) 
        printf("\t%g\n", sum += atof(line)); 

    return 0;
}
