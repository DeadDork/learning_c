////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out srandom().

// Conclusion: yay random numbers!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	static int element;

	while (element++ < 10) {
		srandomdev();
		printf("%d ", (int)random());
	}
	putchar('\n');

	return 0;
}