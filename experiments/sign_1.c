// Explores whether 'signed' and 'unsigned' default to 'int'.

// Conclusion: it appears as though they do. However, it gets a little weird,
// given that unsigned ints seem to get signed ints...

#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))

int main(void) {
	signed x = -1;
	unsigned y = -1;
	unsigned char z = -1;

	PrintExpression(x);
	PrintExpression(y); // Prints -1???
	PrintExpression(z); 

	return 0;
}
