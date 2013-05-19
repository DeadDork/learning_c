////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores negation of complex parenthesized tests.

// The truth value of complex statements can be negated parenthetically.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	double d;
	char * s = malloc (500);

	while (fgets (s, 500, stdin) != NULL)
		if (!(sscanf (s, "%lf", &d) && d > 10.0))
			puts ("Either not a double or a double greater than 10.0");

	return 0;
}
