////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the function isideogram().

// Yeah, so isideogram() is absolutely fucking useless.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int c;

	while ((c = getchar()) != EOF) {
		if (isideogram(c))
			printf("[%c] = ideogram\n", c); // Test
		if (isalnum(c))
			printf("[%c] = alnum\n", c); // Control
	}

	return 0;
}
