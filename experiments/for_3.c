// Explores initializing a variable in the first argument of a for loop.

// Conclusion: can declare at least two variables in the first `for` argument.

#include <stdio.h>

int main(void) {
	//for (int i = 10, char c = 'a'; i >= 0 && c <= 'z'; --i, ++c) // Doesn't work
	for (int i = 10, c = 'a'; i >= 0 && c <= 'z'; --i, ++c)
		printf("%d%c ", i, c);
	putchar('\n');

	return 0;
}
