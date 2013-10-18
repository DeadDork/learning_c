// Explores the use of the `continue` keyword.

// Hypothesis: should only print values > 0.

// Conclusion: indeed, it did!

#include <stdio.h>

#define ARRAY_MAX 8

int main(void) {
	int element;
	int array[ARRAY_MAX] = {-1, 2, -3, 4, -5, 6, -7, 8};

	for (element = 0; element < ARRAY_MAX; ++element) {
		if (array[element] < 0)
			continue; // Skip negative values
		printf("%d ", array[element]);
	}
	putchar('\n');

	return 0;
}
