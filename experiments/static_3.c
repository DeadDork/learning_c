////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of a static applied to an internal variable.

// Conclusion: The not-static internal variable had some garbage value which did auto-
// increment, and the static internal variable auto-incremented from 0. Perhaps
// for loops do not count as functions?

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

#define Print(x) printf("\t%s = %d\n", #x, (x))

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int counter;

	printf("*NOT* static internal variable:\n");
	for (counter = 0; counter < 10; ++counter) {
		int i1;
		++i1;
		Print(i1);
	}

	printf("Static internal variable:\n");
	for (counter = 0; counter < 10; ++counter) {
		static int i2;
		++i2;
		Print(i2);
	}

	return 0;
}
