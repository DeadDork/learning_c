////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores autoincrementing a pointer while also dereferencing it.

// I hope that this isn't an undefined behavior thingymajigy, but it certainly
// appears as though `*(s++)` does exactly what you would think it does; namely
// it dereferences `s`, executes the expression, then it autoincrements `s`.
// That is, it doesn't autoincrement `s` then dereferences it (after all the
// autoincrement is parenthesized). If it did the latter, then the 'G' in "God"
// would not print.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	char * s; // Generic string

	s = malloc ((size_t) 50);
	s = strcat (s, "God be with you, goodwife Wallace!\n");

	while (*s != '\0')
		putchar (*(s++));

	free (s);

	return 0;
}
