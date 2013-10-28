// Tests the warnings in a mathematical expression with logical operators.

// Conclusion: no warnings. Don't know why I'm getting weird warnings in 5-17.

#include <stdio.h>

int main(void) {
	int x;
	for (x = 0; x < 20; ++x)
		printf("%d + (%d %% 2 > 0) = %d\n", x, x, x + (x % 2 > 0));

	return 0;
}
