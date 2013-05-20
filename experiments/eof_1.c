////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores what happens when you call getchar() at EOF repeatedly.

// Interesting. I hope this isn't implementation dependent, but at least on my
// machine, I see the very sane behavior of a stream staying closed once it's
// closed with EOF.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	int c, i;

	for (i = 0; i < 100; ++i) {
		c = getchar ();
		printf ("%3d : %d\n", i, c);
	}

	return 0;
}
