////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints charstream.

// I piped into mit-scheme `echo "(+ 1 2 3)"`, Edwin spun up, printed the result,
// then shut down. This made me wonder if echo was also sending an EOF. This
// program tests that idea.

// Indeed, I piped an echo into `echo_1`, and the final output was -1.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	int c = 1;

	while (c != EOF)
		printf ("[%d]\n", c = getchar());

	return 0;
}
