////////////////////////////////////////////////////////////////////////////////
// Comments

// Attempts to solve the question of 'return "hello"'.
// Hypothesis: returns a pointer.

// Yeppers.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NUL '\0'

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

char * returner (char * s);

////////////////////////////////////////////////////////////////////////////////
// Functions

char * returner (char * s) {
	float f;

	if (strlen (s) <= 1)
		return "Nothing";
	else if (sscanf (s, "%f", &f))
		return "Float";
	else
		return "String";
}

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	char * s = malloc (500), * sptr;

	while (fgets (s, 500, stdin) != NULL) {
		sptr = returner (s);
		printf ("Pointer address = [%p]\n", sptr);
		printf ("Pointer[0] = [%c], Pointer[1] = [%c], Pointer[2] = [%c]\n", sptr[0], sptr[1], sptr[2]);
		printf ("Full string of pointer address = [%s]\n", sptr);
	}

	return 0;
}
