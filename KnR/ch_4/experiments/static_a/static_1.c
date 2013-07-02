////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of `static`.

// This experiment uses two files:
//
//// 1) static_func_1.c (functions that use static external variables)
//
//// 2) static_1.c (main function + function prototypes [+ test functions to
//// explore `static`])

// The results of using `static` suggets that indeed it will not be retrieved
// from another file.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// External Variables

extern int i;

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void plus1(void);

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int ii;

	for (ii = 0; ii < 5; ++ii) {
		printf("start:\n\ti = [%d]\n", i);
		plus1();
		printf("plus1():\n\ti = [%d]\n", i);
		i += 2;
		printf("i += 2:\n\ti = [%d]\n", i);
	}

	return 0;
}
