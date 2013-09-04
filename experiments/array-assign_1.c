////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores assigning to an array a string much shorter than it's max length.

// Assigning a string to a character array in the declaration statement appears
// to be agnostic with regards to the memory assigned to the array.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXSTR 100

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char s[] = "Control";
	char ss[MAXSTR] = "Schmoopie!";
	char sss[MAXSTR] = "Schmoopie!\0";

	printf("Control:\n");
	printf("\t%s\n", s);

	printf("Test 1:\n");
	printf("\t%s\n", ss);

	printf("Test 2:\n");
	printf("\t%s\n", sss);

	return 0;
}
