////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the return values of scanf when the * flag is used to suppress
// assignment. Does it return a 0 or 1?

// Conclusion: It returns 0.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	int i;
	char * s = malloc (500);
	float f, ff, fff, ffff, fffff;

	printf ("Suppressed match:\n");
	for (i = 1; i <= 5 && (fgets (s, 500, stdin) != NULL); ++i)
		printf ("%d/5: Number of float matches = [%d]\n", i, sscanf (s, "%*f %*f %*f %*f %*f"));

	printf ("\nAssigned match:\n");
	for (i = 1; i <= 5 && (fgets (s, 500, stdin) != NULL); ++i)
		printf ("%d/5: Number of float matches = [%d]\n", i, sscanf (s, "%f %f %f %f %f", &f, &ff, &fff, &ffff, &fffff));

	free (s);

	return 0;
}
