////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out random().

// DANGER DANGER DANGER will use the same random numbers. E.G. if the first
// pseudo random number is 5, then 5 will be printed out as the first
// number every time the program is run.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	static int element;

	while (element++ < 10)
		printf("%d ", (int)random());
	putchar('\n');

	return 0;
}
