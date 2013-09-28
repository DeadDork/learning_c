////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exerce 5-2.

// Demonstrates a getfloat().

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include "getch.h"

////////////////////////////////////////////////////////////////////////////////
// Macros

#define PrintExpr(x) printf(#x " = %f\n", (x))

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Gets rid of leading white space
void chomp(void);

// Get next integer
int getfloat(float *);

////////////////////////////////////////////////////////////////////////////////
// Functions

void chomp(void) {
	int character;

	while (isspace(character = getch()) && character != EOF);

	if (character != EOF)
		ungetch(character);
}

int getfloat(float *number) {
	int sign, character;
	float decimal_power;

	// Leading [+-]
	character = getch();
	sign = (character == '-') ? -1 : 1;
	if (character == '-' || character == '+')
		character = getch();

	// Integral
	for (*number = 0.0; isdigit(character); character = getch())
		*number = *number * 10 + (character - '0');

	// Decimal
	if (character == '.') {
		character = getch();
		for (decimal_power = 10.0; isdigit(character); character = getch(), decimal_power *= 10)
			*number += (character - '0') / decimal_power;
	}

	// Sign
	*number *= sign;

	if (character != EOF)
		ungetch(character);

	return character;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int character;
	float number;

	do {
		chomp();
		character = getfloat(&number);
		if (isspace(character))
			PrintExpr(number);
		else
			getch();
	} while (character != EOF);

	return 0;
}
