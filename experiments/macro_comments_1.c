// Explores what happens when a macro has a comment at it's end

// Conclusion: comments are not macro-expanded.
// (Thank god)

#include <stdio.h>

#define PrintExpressionish(x) #x " is [%c]\n", c // if comment is macro-expanded, this will fail

int main(void) {
	char c = 'm';

	printf(PrintExpressionish(c));

	return 0;
}
