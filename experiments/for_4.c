// Explores scope of `for` declarations.

// Conclusion: Looks like a `for` loop scopes variable declarations internally.
#include <stdio.h>

#define PrintExpression(x) printf(#x " = %d\n", (x))

int main(void) {
	int j = 18;
	for (int j = 6; j < 10; ++j);
	PrintExpression(j);

	return 0;
}
