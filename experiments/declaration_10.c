// Explores multiple assignments in a declaration.

// Conclusion: you need at least a comma.

#include <stdio.h>

#define PrintExpression(x) printf(#x " = %d\n", (x))

int main(void) {
	int x = y = 1; // error: use of undeclared identifier 'y'

	PrintExpression(x);
	PrintExpression(y);

	return 0;
}
