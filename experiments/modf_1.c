////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the modf function.

// Bug: this only prints the first 9 characters after the decimal, not 10.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <math.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	double x = 1234567890.0987654321; // Generic positive double
	double y = -1234567890.0987654321; // Generic negative double
	double ntgr, frac; // Integer, fraction

	// Positive
	frac = modf (x, &ntgr);
	printf ("%.10f:\n", x);
	printf ("\tInteger portion  = %.0f\n", ntgr);
	printf ("\tFraction portion = %.10f\n", frac);

	// Negative
	frac = modf (y, &ntgr);
	printf ("%.10f:\n", y);
	printf ("\tInteger portion  = %.0f\n", ntgr);
	printf ("\tFraction portion = %.10f\n", frac);

	return 0;
}
