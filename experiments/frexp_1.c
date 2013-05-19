////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of the frexp function.

// Works exactly as you would expect.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <math.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	double d = 0.04296875; // Double (equals exactly 2^-5 + 2^-7 + 2^-8)
	double m; // Mantissa
	int e; // Exponent of 2

	m = frexp (d, &e);

	printf ("float = [%.8f]\n", d);
	printf ("(float = mantissa * 2^exponent)\n\n");
	printf ("\tmantissa = [%.5f]\n\n", m);
	printf ("\texponent = [%d]\n", e);

	return 0;
}
