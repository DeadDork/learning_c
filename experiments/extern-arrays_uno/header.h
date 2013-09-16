////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests whether arrays need to have their size declared, too.

// This is the header file.

// Solved the macro issue.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 100

////////////////////////////////////////////////////////////////////////////////
// Macros

#define Print(x) (printf("%s = [%s]\n", #x, (x)))

////////////////////////////////////////////////////////////////////////////////
// External Variables

char s[MAXLEN] = "Hello, my darling wife.";