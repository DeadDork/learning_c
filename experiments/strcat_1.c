////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of strcat().

// strcat() cats s2 on to s1.
// strcpy() copies s2 on to s1.
// In both cases, catching the output pointer (...to s1...) is not terribly
// useful, at least in this limited use case.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 100

////////////////////////////////////////////////////////////////////////////////
// Macros

#define Print(x) (printf("\t%s = [%s]\n", #x, (x)))

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char a[MAXLEN] = "Happiness";
	char b[MAXLEN] = "A penis";
	char * c;
	c = malloc(MAXLEN);
	strcpy(c, "Come on...");

	printf("Control:\n");
	Print(a);
	Print(b);
	Print(c);

	printf("Test:\n");
	c = strcat(a, b);
	Print(a);
	Print(b);
	Print(c);

	//free(c); // I have no idea why this is bugging out

	return 0;
}
