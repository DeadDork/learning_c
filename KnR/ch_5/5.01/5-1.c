////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exerce 5-1.

// Demonstrates a getint() that ignores lone [+-]'s.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include "getch.h"

////////////////////////////////////////////////////////////////////////////////
// Macros

#define PrintExpr(x) printf(#x " = %d\n", (x))

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Get next integer
int getint(int *);

////////////////////////////////////////////////////////////////////////////////
// Functions

int getint(int *number_pointer) {
	int current_character, next_character, sign;

	// Skip white space
	while (isspace(current_character = getch()));

	// If input not a number
	next_character = getch();
	ungetch(next_character);
	if (!isdigit(current_character) && current_character != EOF && !(current_character == '+' && isdigit(next_character)) && !(current_character == '-' && isdigit(next_character))) {
		ungetch(current_character);
		return 0;
	}

	// If input a number {{{
	sign = (current_character == '-') ? -1 : 1;

	if (current_character == '+' || current_character == '-')
		current_character = getch();

	for (*number_pointer = 0; isdigit(current_character); current_character = getch())
		*number_pointer = 10 * *number_pointer + (current_character - '0');

	*number_pointer *= sign;

	if (current_character != EOF)
		ungetch(current_character);

	return current_character;
	// }}}
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int *number, character;

	while ((character = getint(number)) != EOF) {
		if (isspace(character))
			PrintExpr(*number);
		else
			getch();
	}

	return 0;
}
