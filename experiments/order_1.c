// Explores evaluation order

// Expected: `-` should evaluate left to right.

// Conclusion: as expected, the printed value was 2, not 6.

#include <stdio.h>

#define PrintExpression(x) printf(#x " = %d\n", (x))

int main(void) {
	PrintExpression(10 - 5 - 2 - 1);

	return 0;
}
