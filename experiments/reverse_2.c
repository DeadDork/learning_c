////////////////////////////////////////////////////////////////////////////////
// Comments

// Reverses line order

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NUL '\0'

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

char * reverser (char * s);
/* Reverses a string.
 
   `s` = String to reverse.

   Returns the reversed string.

   N.B. Would it be better to make this function return a void, and just change
   the order of the char pointer? */

////////////////////////////////////////////////////////////////////////////////
// Functions

char * reverser (char * s) {
	unsigned e, max;
	char temp;

	for (e = 0; s[e] != NUL; ++e);
	max = e;

	for (e = 0; e < max / 2; ++e) {
		temp = s[e];
		s[e] = s[max - (e + 1)];
		s[max - (e + 1)] = temp;
	}

	return s;
}

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	char * s = malloc (500);

	while (gets (s) != NULL)
		printf ("%s\n", reverser (s));

	free (s);

	return 0;
}
