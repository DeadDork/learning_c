////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores complex if tests.

// No, doesn't illuminate why rebaser is being a twat.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	double d;
	unsigned i;
	char * s = malloc (500);

	while (fgets (s, 500, stdin) != NULL) {
		if (sscanf (s, "%lf\n", &d) && (i = (unsigned) fabs (d)) >= 5)
			printf ("Greater than or equal to 5:\n\td = [%f]\n\ti = [%d]\n", d, i);
		else if (sscanf (s, "%lf\n", &d) && (i = (unsigned) fabs (d)) < 5)
			printf ("Less than 5:\n\td = [%f]\n\ti = [%d]\n", d, i);
	}

	free (s);

	return 0;
}
