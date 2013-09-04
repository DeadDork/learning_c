////////////////////////////////////////////////////////////////////////////////
// Comments

// Cats two arrays in different ways to see what happens.

// Lesson: A pointer to an array is different (or thereabouts) is wildly
// different from the array itself!!!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 100

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char a[MAXLEN] = "Hello" ", " "my" " darling" " wife!";
	//char b[MAXLEN] = a " will this work?"; // Nope!
	//char c[MAXLEN] = "Yummy yummy yummy!";

	printf("Control:\n");
	printf("\t%s\n", a);

	/* b[] is an error
	printf("Test1:\n");
	printf("\t%s", b);
	*/

	/* 'a c' is an error
	printf("Test2:\n");
	printf("\t%s\n", a c);
	*/

	printf("Test3:\n");
	printf("\t%s\n", "King" " Wah!");

	return 0;
}
