////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 4-1.

// Returns the rightmost occurrence of a match.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NOMATCH 0
#define MATCH 1

#define CURRCH 0 // Current character from stdin
#define LINDEX 1 // Current line index maxima
#define RMATCH 2 // Line index of  the right-most match

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void getmatch (int c[], char s[]);
/* Tries to match STDIN against the match string.
 
   `c[]` = A pseudo-struct for matching (c[0] = current string, c[1] = the line
   index, c[2] = the right-most match).

   `s[]` = The match string. */

int strindex (int c[], char s[]);
/* Determines the start position of the right-most match of a string.

   `c[]` = A pseudo-struct for matching (c[0] = current string, c[1] = the line
   index, c[2] = the right-most match).

   `s[]` = The match string.
   
   Returns MATCH or NOMATCH accordingly. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void getmatch (int c[], char s[]) {
	int i;

	for (i = 0; s[i] != '\0'; ++i, ++c[LINDEX]) {
		if ((c[CURRCH] = getchar()) != s[i]) {
			++c[LINDEX];
			break;
		}
	}

	if (s[i] == '\0')
		c[RMATCH] = c[LINDEX] - i;
}

int strindex (int c[], char s[]) {
	c[LINDEX] = 0;
	c[RMATCH] = -1;

	while (c[CURRCH] != EOF) {
		getmatch (c, s);
		if (c[CURRCH] == '\n') 
			break;
	}

	if (c[RMATCH] > -1)
		return MATCH;
	else
		return NOMATCH;
}

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	int c[3]; // pseudo-struct: current char, current line index, right most
	          // match index 
	char mstring[] = "too sexy"; // Match string

	c[0] = ~EOF;
	while (c[CURRCH] != EOF)
		if (strindex(c, mstring))
			printf ("%d\n", c[RMATCH]);

	return 0;
}
