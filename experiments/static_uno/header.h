////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the `static` keyword.

// Conclusion: since making i1 static does not really seem to make it static
// (I can change its value in main()), I still have no idea how the `static`
// keyword is supposed to work.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Returns the address of i1 in <external.c>.
int *addresser(void);
