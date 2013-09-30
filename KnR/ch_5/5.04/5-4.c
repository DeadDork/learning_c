////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 5-4.

// Demonstrates strend().

// N.B. In strend(), I shouldn't need to initially autodecrement `source` &
// `target`, as they both equal '\0'. However, unless I do, strend() doesn't
// work. I have no idea what is going on.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STRING 100
#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// Functin Prototypes

// Returns TRUE if the target string occurs at the end of the source string,
// else FALSE.
int strend(char *, char *);

////////////////////////////////////////////////////////////////////////////////
// Functions

int strend(char *source, char *target) {
	char *placeholder = target;

	while (*target++ != '\0');
	while (*source++ != '\0');
	for (--source, --target; *source == *target && target > placeholder; --source, --target); // WTF, why do I need to initially autodecrement?

	return (*source == *target && target == placeholder) ? TRUE : FALSE;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char string1[MAX_STRING], string2[MAX_STRING];
	int character, element;

	for (;;) {
		for (element = 0; element < MAX_STRING - 1 && (character = getchar()) != EOF && character != '\n'; ++element)
			string1[element] = character;
		string1[element] = '\0';
		if (character == EOF)
			break;

		for (element = 0; element < MAX_STRING - 1 && (character = getchar()) != EOF && character != '\n'; ++element)
			string2[element] = character;
		string2[element] = '\0';
		if (character == EOF)
			break;

		if (strend(string1, string2))
			printf("The second string occurs at the end of the first string!\n");
		else
			printf("The second string does not occur at the end of the first string...\n");
	}

	return 0;
}
