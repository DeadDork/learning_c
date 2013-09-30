////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests whether '\0' == '\0'.

// Conclusion: the world is still sane (so I really, really don't understand
// the bug I came across in my solution to 5-4).

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

#define PrintCompare(x, y) printf(#x " [aka '%c'] = " #y " [aka '%c']\n", *(x), *(y))
#define PrintDoesNotCompare(x, y) printf(#x " [aka '%c'] != " #y " [aka '%c']\n", *(x), *(y))

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Compares two characters to see if they are equal
void character_comparison(char *, char *);

////////////////////////////////////////////////////////////////////////////////
// Functions

void character_comparison(char *character1, char *character2) {
	if (*character1 == *character2)
		PrintCompare(character1, character2);
	else
		PrintDoesNotCompare(character1, character2);
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char character1, character2;

	character1 = 'a';
	character2 = 'b';
	character_comparison(&character1, &character2);

	character1 = 'z';
	character2 = 'z';
	character_comparison(&character1, &character2);

	character1 = '1';
	character2 = '2';
	character_comparison(&character1, &character2);

	character1 = '0';
	character2 = '0';
	character_comparison(&character1, &character2);

	character1 = '\0';
	character2 = '\0';
	character_comparison(&character1, &character2);

	return 0;
}
