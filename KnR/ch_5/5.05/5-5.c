////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 5-5.

// Demonstrates strncpy(), strncat(), and strncmp().

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STRING 100
#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// Macros

#define PrintExpression(x) printf(#x " = [%s]\n", (x))

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Copy n-length of a target string to a source string.
char *strncpy(char *, char *, unsigned int);

// Concatenate n-length of a target string to the end of a source string.
char *strncat(char *, char *, unsigned int);

// Compare the n-lengths of a target string and source string: return TRUE if
// they match, FALSE if they don't.
int strncmp(char *, char *, unsigned int);

// Get a string from stdin.
int get_string(char *);

// Get a positive integer from stdin. Returns EOF (-1?) if EOF is read.
int get_positive_integer(void);

////////////////////////////////////////////////////////////////////////////////
// Functions

char *strncpy(char *source, char *target, unsigned int length) {
	char *source_start = source;

	while (length-- && *target != '\0')
		*source++ = *target++;
	*source = '\0';

	return source_start;
}

char *strncat(char *source, char *target, unsigned int length) {
	char *source_start = source;

	while (*source++ != '\0');
	for (source--; length-- && *target != '\0';)
		*source++ = *target++;
	*source = '\0';

	return source_start;
}

int strncmp(char *source, char *target, unsigned int length) {
	if (length > 0) {
		while (--length && *source++ == *target++);
		return (!length && *source == *target) ? TRUE : FALSE;
	} else
		return FALSE;
}

int get_string(char *string) {
	int character, element;

	for (element = 0; element < MAX_STRING - 1 && (character = getchar()) != EOF && character != '\n'; ++element)
		string[element] = character;
	string[element] = '\0';

	if (element == MAX_STRING - 1)
		return 0;
	else
		return character;
}

int get_positive_integer(void) {
	int character, number = 0;

	while (isdigit(character = getchar()))
		number = number * 10 + character - '0';

	if (character == EOF)
		return EOF; // EOF (almost?) always equals -1
	else
		return number; // will always equal >= 0
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char string1[MAX_STRING], string2[MAX_STRING];
	int length, demo;

	for (;;) {
		printf("Enter string1: ");
		if (get_string(string1) == EOF)
			break;

		printf("Enter string2: ");
		if (get_string(string2) == EOF)
			break;

		printf("Enter length: ");
		if ((length = get_positive_integer()) == EOF)
			break;

		printf("(1) strncpy()\n(2) strncat()\n(3) strncmp()\nChoose which function to demo: ");
		if ((demo = get_positive_integer()) == EOF)
			break;
		else if (demo == 1)
			PrintExpression(strncpy(string1, string2, length));
		else if (demo == 2)
			PrintExpression(strncat(string1, string2, length));
		else if (demo == 3) {
			if (strncmp(string1, string2, length))
				printf("The first %d characters of the strings match!\n", length);
			else
				printf("The first %d characters of the strings *do not* match...\n", length);
		} else
			printf("Input error\n");
	}
	putchar('\n');

	return 0;
}
