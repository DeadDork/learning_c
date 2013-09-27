////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to 4-12.

// Uses recursion to generate a string from an integer.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STRING 100

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Transforms an integer into a string
void itoa(char [], int);

// Recursively assigns a character to a string from a number
int itoa_recursion(char [], int, int);

////////////////////////////////////////////////////////////////////////////////
// Functions

int itoa_recursion(char string[], int element, int number) {
	if (number / 10)
		element = itoa_recursion(string, element, number / 10);

	string[element] = number % 10 + '0';

	return element + 1;
}

void itoa(char string[], int number) {
	int element = 0;

	if (number < 0) {
		string[element++] = '-';
		number = -number;
	}

	string[itoa_recursion(string, element, number)] = '\0';
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int character, element = 0;
	char input_string[MAX_STRING], number_string[MAX_STRING];

	while ((character = getchar()) != EOF) {
		if (isdigit(character) || character == '-')
			input_string[element++] = character;
		else {
			input_string[element] = '\0';
			itoa(number_string, atoi(input_string));
			printf("[%s] = [%s]\n", input_string, number_string);
			element = 0;
		}
	}

	return 0;
}
