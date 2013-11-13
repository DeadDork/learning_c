// Explores whether 'signed' and 'unsigned' default to 'int'.

// Conclusion: it appears as though they do.

#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))

int main(void) {
	signed x = -1;
	unsigned y = 1;
	unsigned int z = -1;

	PrintExpression(x);
	PrintExpression(y);
	PrintExpression(z); // Prints -1??? Is clang being "helpful"...?

	return 0;
}
