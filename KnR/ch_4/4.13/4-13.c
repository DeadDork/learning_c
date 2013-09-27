////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 4-13.

// Reverses a string in place via recursion.

// N.B. Recursions can't be escaped from as easily, making this version of
// reverse() run 1/2x as fast as the reverse() that uses loop structures.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STRING 1000

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

////////////////////////////////////////////////////////////////////////////////
// Functions

void reverse(char string[]) {
	static int element, offset;
	char temporary_character;

	if (string[element] == '\0') {
		--element;
		return;
	} else {
		++element;
		reverse(string);
	}

	if (element > offset) {
		temporary_character = string[element];
		string[element--] = string[offset];
		string[offset++] = temporary_character;
	} else
		element = offset = 0;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int character, element = 0;
	char string[MAX_STRING];

	while ((character = getchar()) != EOF) {
		if (element >= MAX_STRING || character == '\n') {
			string[element] = '\0';
			reverse(string);
			printf("%s\n", string);
			element = 0;
		} else
			string[element++] = character;
	}

	return 0;
}
