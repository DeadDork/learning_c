// Explores the return value of a non-number.

// Conclusion: 0.0

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("[%f]\n", atof("hello"));

	return 0;
}
