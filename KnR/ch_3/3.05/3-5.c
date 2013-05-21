////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 3-5.

// Demonstrates the use of itob(): reads 2 or more numbers, the first being the
// unit base, and the second+ being the numbers to be rebased.

// N.B. I chose to set the max to 2^64 to allow for freaky int's that use 64
// bits.

// N.B. Overflow and underflow input handling is implementation dependent.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NUL '\0'

#define NEG -1
#define POS 1

#define FALSE 0
#define TRUE 1

#define ERROR 0
#define NOERR 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int is_numstr (char s[]);
/* Determines if a string is a number.
 
   `s[]` = String to check.

   Return TRUE if `s[]` is a number string; otherwise return FALSE. */

int strtoi (char s[]);
/* Convert signed ascii number string to an integer.
 
   `s[]` = Number string to convert to a number.

   Return the integer value. */

int getnum (int num[]);
/* Get an integer value from stdin.
 
   `num[0]` = The only element in this set is the number retrieved from stdin.

   Returns NOERR if there is no error; otherwise return ERROR. */

char rebase (unsigned n);
/* Uses alphabet characters to represent digits greater than 9.

   `n` = The number to be rebased.
 
   N.B. I chose 'unsigned' to clearly indicate that `n` is always a positive
   integer when being rebased this way.

   N.B. This is not a safe function, so be sure to condition it appropriately,
   i.e. make sure that the base isn't less than 2 nor greater than 26 + 9
   (all the numerical set + alphabetical set). */

void reverse (char s[]);
/* Reverse the order of elements in an array.
 
   `s[]` = String to reverse. */

void itob (int n, char s[], int b);
/* Rebase an integer to base-2 through base-36.
 
   `n` = The integer to transform.

   `s[]` = The string array the integer gets transformed into.
   
   `b` = Desired base value. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_numstr (char s[]) {
	int i;

	for (i = 0; s[i] != NUL; ++i);
	for (; i > 0 && isnumber(s[i]); --i);

	if (i == 0 && (isnumber(s[i]) || s[i] == '-'))
		return TRUE; // s[] is a number string
	else
		return FALSE; // s[] is not a number string
}

int strtoi (char s[]) {
	int i = 0, sign = POS;
	int total;

	// Sign
	if (s[i] == '-') {
		sign = NEG;
		total = 0;
	} else if (isnumber(s[i])) {
		total = s[i] - '0';
	}

	// Magnitude
	for (++i; s[i] != NUL; ++i)
		total = total * 10 + s[i] - '0';

	return total * sign;
}

int getnum (int num[]) {
	int c, i = 0;
	int maxstr = 1 + 20; // '-' + 2^64 in base-10
	char numstr[maxstr + 1]; // Space for NUL

	// Get number string {{{
	// Eat up bad leading data & get start of number string
	while ((c = getchar()) != EOF && c != '-' && !isnumber(c));
	if (c == EOF)
		return ERROR; // No entry
	numstr[i] = c;

	// Get rest of number string
	for (++i; (c = getchar()) != EOF && isnumber(c) && i < maxstr; ++i)
		numstr[i] = c;
	numstr[i] = NUL;
	// }}}

	// Return number value
	if (isspace(c) || c == EOF) {
		num[0] = strtoi(numstr);
		return NOERR; // Entry is a number
	} else
		return ERROR; // Entry is *not* a number
}

char rebase (unsigned n) {
	if (n >= 10)
		return 'A' + (n - 10); // returns an alphabetical character when n >= 10,
		                       // with 'A' = 10, 'B' = 11, and so forth
	else
		return n; // return a numerical character when n < 10
}

void reverse (char s[]) {
	int i, max;
	char temp;

	for (i = 0; s[i] != NUL; ++i);
	max = i;

	// Switch extrema values, then shift to the middle on both extremas,
	// and repeat until at the middle 
	for (i = 0; i < max / 2; ++i) {
		temp = s[i];
		s[i] = s[max - (i + 1)];
		s[max - (i + 1)] = temp;
	}
}

void itob (int n, char s[], int b) {
	int i, sign;

	i = 0;
	sign = (n < 0) ? NEG : POS;

	// Assign rebased number values to array backwards
	do {
		s[i++] = ((n % b) * sign <= 9) ? (n % b) * sign + '0' : rebase((n % b) * sign);
	} while ((n /= b) * sign > 0);

	/* Assign signage */
	if (sign == NEG)
		s[i++] = '-';

	s[i] = '\0';

	reverse (s);
}

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	int num[1] = {0}; // num[0] = value (ch.3-compliant version of a pointer)
	int base, error = NOERR;
	char s[1 + 65 + 1]; // '-' + 2^64 in base-2 digits + NUL

	// Get base
	error = getnum(num);
	base = num[0];
	if (base < 2 || base > 36)
		return 1; // base too small or too large

	// Convert numbers from stdin to base
	while (getnum(num)) {
		itob (num[0], s, base);
		printf("%s\n", s);
	}

	return 0;
}
