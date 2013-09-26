////////////////////////////////////////////////////////////////////////////////
// Comments

// This is the header for a stupid library to check if a string is a number.

// N.B. After the fact, I realized that I could happily get by with something
// like scanf().

// This is driving me crazy: '--123' matches for some freakish reason. But not ---123.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <regex.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NO_MATCH 0
#define MATCH 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Checks if an input string is a number.
int is_number(char *);

// Compiles the number regex.
void compile_re(void);

// Prints the matching string
void match_print(char *string);
