////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests whether arrays need to have their size declared, too.

// I'm having issues with cross-file macros. Consolidating in one file to test
// the issue.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 100

////////////////////////////////////////////////////////////////////////////////
// Macros

#define Print(x) (printf("%s = [%s]\n", #x, (x)))

////////////////////////////////////////////////////////////////////////////////
// External Variables
char s[MAXLEN] = "Hello, my darling wife.";

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	extern char s[]; // Needs the `[]`

	Print(s);

	return 0;
}
