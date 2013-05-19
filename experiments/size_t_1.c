////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores size_t's range (specifically, whether it can be negative).

// This experiment is bad: the results are ambiguous.

// N.B. A negative result does not mean that it always can be negative. It
// could be an undefined behavior.

// Wiki-ed this question: size_t is unsigned; ssize_t is signed.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	size_t i = 1;
	unsigned ii = 1;

	puts ("size_t:");
	i = -i;
	printf ("\t%d\n", (int) i);
	printf ("\t%u\n", (unsigned) i);

	puts ("unsigned:");
	ii = -ii;
	printf ("\t%d\n", (int) ii);
	printf ("\t%u\n", (unsigned) ii);

	return 0;
}
