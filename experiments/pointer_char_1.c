////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests if a char pointer can point to a character constant.

// Conclusion: works!

////////////////////////////////////////////////////////////////////////////////
// Global Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Code

int main(void) {
	char *string = "Hey man, what's up?";

	printf("%s\n", string);

	return 0;
}