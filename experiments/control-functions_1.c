////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints out the return values of control functions.

// Doesn't work.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	int i = 0, ii;

	printf ("i = [%d]\n", i);
	printf ("i = [%d]\n", for(ii = 0; ii < 3; ++ii));

	return 0;
}