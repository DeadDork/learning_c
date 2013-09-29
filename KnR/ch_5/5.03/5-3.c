////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 5-3.

// Demonstrates a pointer version of strcat().

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STRING 100

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Concatenate a target string to a source string
void strcat(char *, char *);

////////////////////////////////////////////////////////////////////////////////
// Functions

void strcat(char *source, char *target) {
	while (*source++ != '\0');
	for (--source; (*source++ = *target++) != '\0';);
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char string1[2 * MAX_STRING], string2[MAX_STRING];
	int character, element;

	for (;;) {
		for (element = 0; (character = getchar()) != '\n' && character != EOF && element < MAX_STRING - 1; ++element)
			string1[element] = character;
		string1[element] = '\0';
		if (character == EOF)
			break;

		for (element = 0; (character = getchar()) != '\n' && character != EOF && element < MAX_STRING - 1; ++element)
			string2[element] = character;
		string2[element] = '\0';
		if (character == EOF)
			break;

		strcat(string1, string2);
		printf("string1 + string2:\n\t[%s]\n", string1);
	}

	return 0;
}
