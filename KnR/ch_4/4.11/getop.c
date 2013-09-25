////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to problem 4-11.

// I'm a lazy mofo, so the solution is presented only as it relates to
// <getop.c>. A better man would incorporate the whole calculator.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STRING 100

#define NUMBER '0'

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Get next character or numeric operand
int getop(char []);

////////////////////////////////////////////////////////////////////////////////
// Functions

int getop(char s[]) {
	int i, temp_c;
	static int c;

	// Eat up white space
	if (c == ' ' || c == '\t')
		while ((s[0] = c = getchar()) == ' ' || c == '\t');
	else if (s[0] == '\0') // First iteration
		s[0] = c = getchar();
	else // All following iterations
		s[0] = c;
	s[1] = '\0';

	// Return non-numbers
	if (!isdigit(c) && c != '.') {
		temp_c = c;
		c = getchar();
		return temp_c;
	}

	// Get number {{{
	// collect integer part
	i = 0;
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getchar()));

	// collect fraction part
	if (c == '.')
		while (isdigit(s[++i] = c = getchar()));

	// Close string
	s[i] = '\0';
	// }}}

	return NUMBER;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char s[MAX_STRING];
	s[0] = '\0';
	int i;

	while ((i = getop(s)) != EOF) {
		if (i == NUMBER)
			printf("Number = [%f]\n", atof(s));
		else if (i != '\n')
			printf("Input = [%c]\n", i);
	}

	return 0;
}
