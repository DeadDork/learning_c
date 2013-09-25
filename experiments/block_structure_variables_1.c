////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of defining variables in a block-structured fashion.

// Conclusion: yeppers, defining a variable inside a block structure creates
// a new variable of the same name.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

#define Print(x) printf("\t%s = %d\n", #x, (x))

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int i = 5, count;

	printf("In block structure:\n");
	for (count = 0; count < 3; ++count) {
		int i;

		printf("\tBlock %d:\n", count);
		for (i = 0; i < 10; ++i)
			Print(i);
	}

	printf("Out of block structure:\n");
	Print(i);

	return 0;
}
