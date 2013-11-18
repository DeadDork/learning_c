// Explore defining a multidimensional array.

// Conclusion: works!

#include <stdio.h>

int main(void) {
	char *array[] = {
		"alpha", // 0
		"beta", // 1
		"gamma", // 2
		"delta" // 3
	};

	for (int element = 3; element >= 0; --element)
		printf("%s\n", array[element]);

	return 0;
}
