////////////////////////////////////////////////////////////////////////////////
// Comments

// Plays with printd() from K & R 4.10

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "is_number.h"

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STRING 100

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Print n in ascii
void printd(int);

////////////////////////////////////////////////////////////////////////////////
// Functions

void printd(int number) {
	if (number < 0) {
		putchar('-');
		number = -number;
	}

	if (number / 10)
		printd(number / 10);

	putchar(number % 10 + '0');
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int character, element = 0;
	char string[MAX_STRING];

	compile_re();

	while ((character = getchar()) != EOF) {
		if (element < MAX_STRING) {
			if (isnumber(character) || character == '-' || character == '.')
				string[element++] = character;
			else {
				string[element] = '\0';
				if (is_number(string)) {
					match_print(string);
					printd(atoi(string)); // string == doubles are integer-ed
					putchar('\n');
				}
				element = 0;
			}
		}
	}

	return 0;
}
