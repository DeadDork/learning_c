////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the possibility of writing a function without braces.

// Conclusion: you *must* brace functions.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

#define Print(x) printf("%d + 1 = %d\n", x, add_one(x))

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int add_one(int);

////////////////////////////////////////////////////////////////////////////////
// Functions

// Works
int add_one(int i) {
	return ++i;
}

/* Doesn't work
int add_one(int i)
	return ++i;
*/

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int c;

	while ((c = getchar()) != EOF)
		if (isdigit(c))
			Print(c - '0');

	return 0;
}
