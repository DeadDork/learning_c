////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests whether '\0' == '\0'.

// Conclusion: makes sense!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char c1 = '\0', c2 = '\0';

	if (c1 == c2)
		printf("Makes sense!\n");
	else
		printf("WTF?!\n");

	return 0;
}
