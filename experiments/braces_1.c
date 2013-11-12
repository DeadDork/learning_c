// Apparently for's and while's don't need braces?

// Conclusion: this is just weird... The else is a new statement, but because
// it is related to if, it is considered as part of the same statement.

#include <stdio.h>

int main(void) {
	int element;
	for (element = 0; element < 10; ++element)
		if (element % 2 == 0)
			printf("%d is even.\n", element);
		else
			printf("%d is odd.\n", element);
		int temporary = element;
		printf("++%d = %d.\n", temporary, ++element);

	return 0;
}
