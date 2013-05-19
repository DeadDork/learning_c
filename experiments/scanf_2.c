////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of scanf (especially for easily formatting number input).

// Wow, OK, scanf doesn't flush the buffer on a bad input...

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	double d;

	/*
	// Basic scanf
	// Exits upon bad input, e.g. "tata!"; infinite loop with EOF.
	while (scanf ("%lf", &d))
		printf ("%f\n", d);
	*/

	/*
	// More complex scanf
	// Exits upon EOF; infinite loop with bad input.
	while (scanf ("%lf", &d) != EOF)
		printf ("%f\n", d);
	*/

	/*
	// More complex scanf
	// Exits upon EOF (assuming EOF == -1) & bad input.
	while (scanf ("%lf", &d) > 0)
		printf ("%f\n", d);
	*/

	// Very complex scanf
	// Exits upon EOF; ignores bad input.
	int check = 0;

	while (check != EOF) {
		if (!check)
			fpurge (stdin);
		else
			printf ("%f\n", d);
		check = scanf ("%lf", &d);
	}

	return 0;
}
