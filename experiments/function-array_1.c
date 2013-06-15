////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests creating a function prototype that takes a type parameter that
// is actually an array to that type.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Vertically prints a string
//void vprintf(char); // Compile error
void vprintf(char []); // Works
//void vprintf(char *); // Works

////////////////////////////////////////////////////////////////////////////////
// Functions

void vprintf(char s[]) {
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		printf("[%c]\n", s[i]);
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char s[] = "Hello, my darling wife!";

	vprintf(s);

	return 0;
}
