////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores whether function declaration order matters.

// N.B. Given the nature of the program, the usual program architecture will
// not be observed.

// Conclusion: I get a compile error if I put the multer() after main(), but I
// do get the correct result.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////

int adder(int, int);
int adder(int x, int y) {
	return x + y;
}

int subber(int, int);
int subber(int x, int y) {
	return x - y;
}

/*
int multer(int, int);
int multer(int x, int y) {
	return x * y;
}
*/

int main(void) {
	printf("adder:\n\t%d - %d = %d\n", 4, 5, adder(4, 5));
	printf("subber:\n\t%d - %d = %d\n", 4, 5, subber(4, 5));
	printf("multer:\n\t%d - %d = %d\n", 4, 5, multer(4, 5));

	return 0;
}

/*
int multer(int, int);
int multer(int x, int y) {
	return x * y;
}
*/
