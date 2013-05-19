////////////////////////////////////////////////////////////////////////////////
// Comments

// Determines the return value of a string of length 0.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NUL '\0'

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	char * s = malloc (500);

	*s = NUL;
	printf ("strlen of a zero-length string = [%d]\n", (int) strlen (s));

	/*
	// Keeps printing + 1 than what I expect. Maybe it's countine the newline?
	// Yes, it is. Tested by piping input without a newline.
	while (fgets (s, 500, stdin) != NULL)
		printf ("strlen of stdin newline-terminated string = [%d]\n", (int) strlen (s));
	*/

	return 0;
}
