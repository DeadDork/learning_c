////////////////////////////////////////////////////////////////////////////////
// Comments

// Attempts to work out how to use the `static` keyword

// Conclusion: `static` makes an external variable only accessible by the object
// created by the source file it occurs in. That is to say, using the `extern`
// keyword in a different object file on a static external variable will fail,
// as it cannot access it. If the `static` keyword is not used, then the
// different object file can access that external variable via `extern`.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

#define Print(x) printf("\t%s = %d\n", #x, (x))

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Adds 1 to external2 (an external variable)
void add_to_external1(void);

// Adds 1 to external2 (a static external variable)
void add_to_external2(void);
