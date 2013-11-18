// Explores the use of `const`.

// Conclusion: as expected, `cons` is read-only.

#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))

int main(void) {
	const int constant = 1;

	for (int element = 1; element <= 10; ++element) {
		PrintExpression(element);
		PrintExpression(constant++); // error: read-only variable is not assignable
	}

	return 0;
}
