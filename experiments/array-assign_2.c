// Explores array assignments outside of definition.

// Conclusion: can only use list assignment in the definition.

#include <stdio.h>

#define MAX_ARRAY 3

int main(void) {
	int array[MAX_ARRAY] = {1, 2, 3};

	for (int element = 0; element < MAX_ARRAY; ++element)
		printf("array[%d] = [%d]\n", element, array[element]);

	array = {4, 5, 6};
	for (int element = 0; element < MAX_ARRAY; ++element)
		printf("array[%d] = [%d]\n", element, array[element]);

	return 0;
}
