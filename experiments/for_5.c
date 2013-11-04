// Further explores defining an element inside a for loop.

// Conclusion: variables defined in the parameter of a for loop are indeed
// scoped.

#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))

int main(void) {
	int integer = 15;
	printf("Outside for loop:\n");
	PrintExpression(integer);
	putchar('\n');

	printf("Inside for loop:\n");
	for (int integer = 5; integer; --integer)
		PrintExpression(integer);
	putchar('\n');

	printf("Outside for loop:\n");
	PrintExpression(integer);

	return 0;
}
