////////////////////////////////////////////////////////////////////////////////
// Comments

// Determines the return value of ^D in a scanf.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	double * dptr;

	printf ("Enter ^D: ");
	printf ("%d\n", scanf ("%lf", dptr));

	return 0;
}