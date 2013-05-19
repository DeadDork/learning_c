////////////////////////////////////////////////////////////////////////////////
// Comments

// Rebases an integer.

// (Slicing up eyeballs ha ha ho ho!)

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <float.h>
#include <math.h>
#include <regex.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

// Strings {{{
// Generic string array length
#define MAXBUF 1000

// Buffer size is equal to the maximum character length of a double in
// base-2 + 1 (for numbers that can't be factored into base-2)
#define MAXDBL (DBL_MAX_10_EXP * (log (10) / log (2)) + 1)

#define NUL '\0'
// }}}

// Regex match values
#define NOMATCH 0
#define MATCH 1

// Number sign values
#define NEG -1
#define POS 1

// Truth values
#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void usage (void);
/* Prints out program instructions. */

void chomp (void);
/* Gets rid of white space. */

int match (char * str, regex_t * re, FILE * errlog);
/* Determines whether a string matches to a compiled regex.
 
   `str` = The string to match.

   `re` = The compiled regex to match against.

   `errlog` = Error output file.

   Returns MATCH if the string matches; otherwise returns NOMATCH. */
   
int getnum (double * d, char * dptr, regex_t * numre, FILE * errlog);
/* Prompts for a double from stdin.

   `d` = Pointer to a double.

   `dptr` = Pointer to a memory block large enough for a number string
   equal to max double.

   `numre` = Pointer to a compiled regular expression of a number.

   `errlog` = Error output file.

   If the string input is in the form of a decimal number, then the value
   is assigned to `dptr` and the function returns TRUE. If the string input
   is not in the form of a decimal number, then an error is logged, the rest
   of the word is walked through, and the function returns FALSE. */

void reverse (char s[]);
/* Reverse the order of elements in an array.
 
   `s[]` = Array to reverse. */

char * rebase_i (double num, unsigned base, char * iptr);
/* Rebases integers.

   `num` = The integer to rease.

   `base` = The base to rebase the integer into.

   `iptr` = Pointer to a memory block large enough for a max double string.

   Returns '0' - '9' if 0 <= `n` <= 9; returns "a" - "z" if 10 <= `n` <= 36;
   returns "Aa" - "Az" if 37 <= `n` <= 63; returns "Ba" - "Bz" if
   64 <= `n` <= 90; and so forth.

   N.B. The base can be anything larger than or equal to 2. This is a very high
   upper limit, but the exact upper limit is implementation dependent. */

char * rebase_f (double frac, unsigned base, char * fptr, char * iptr);
/* Rebases fractions.
 
   `frac` = The fraction to rebase.

   `base` = The base to rebase the fraction into.

   `fptr` = Pointer to a memory block large enough for a max double string.

   `iptr` = Pointer to a memory block large enough for a max double string.

   Returns the rebased fraction; e.g. 0.75 base-2 = 0.11. If the base is 
   greater than 9, then the individual numbers in the rebased value are rebased
   in alphabetical numeration (e.g. base 11 would represent "10" as "a", such
   that "6.a" = "8.7" in base-10).

   N.B. Many fractions cannot be rebased exactly (e.g. "0.1" base-2 =
   "0.0001100110011...0011.."). */

char * rebase_d (double num, unsigned base, char * dptr, char * fptr, char * iptr);
/* Rebases double float.
 
   `num` = The float value to be rebase

   `base` = The base to the rebase the double into.
   
   `dptr` = Pointer to a memory block large enough for a double string
   represented as a double (e.g. "-179769313...858368.0").

   `fptr` = Pointer to a memory block large enough for a max double string.

   `iptr` = Pointer to a memory block large enough for a max double string.

   Returns the rebased double. e.g. "24.75" in base-2 = "11000.11". */

////////////////////////////////////////////////////////////////////////////////
// Functions

void usage (void) {
	printf ("Rebases base-10 numbers to a new arbitrary base (where the base is an integer equal to at least 2).\n\n");

	printf ("Data entry should take the form of one of the following:\n");

	printf ("\t1) rebaser (base) (number to rebase), e.g.:\n");
	printf ("\t\t$ ./rebaser 16 15 16 17\n");

	printf ("\t2) (stdin) | rebaser (base), e.g.:\n");
	printf ("\t\t$ echo 7 8 9 | ./rebaser 8\n");

	printf ("\t3) rebaser (file). N.B. The first value in (file) will be set as the base, e.g.\n");
	printf ("\t\t$ ./rebaser <test_file\n");
	printf ("\tWhere\n");
	printf ("\t\t$ cat test_file\n");
	printf ("\t\t31\n");
	printf ("\t\t30\n");
	printf ("\t\t31\n");
	printf ("\t\t32\n");

	printf ("\t4) rebaser (base) <(file), e.g.:\n");
	printf ("\t\t./rebaser 31 <test_file\n");
	printf ("\tWhere\n");
	printf ("\t\t$ cat test_file\n");
	printf ("\t\t31\n");
	printf ("\t\t30\n");
	printf ("\t\t31\n");
	printf ("\t\t32\n");
}

void chomp (void) {
	int c;

	// Walk through white space character stream
	while ((c = getchar ()) != EOF && isspace (c));

	// Push back the last character (either an EOF or a non-white space
	// character)
	ungetc (c, stdin);
}

int match (char * str, regex_t * re, FILE * errlog) {
	size_t nmatch = 1;
	regmatch_t pmatch[nmatch]; // Match whole string
	int re_err; // Regular expression error code
	char err_msg[MAXBUF]; // Regular expression error message

	// Match the regex to string
	if (!(re_err = regexec (re, str, nmatch, pmatch, 0)))
		return MATCH;
	else if (re_err == REG_NOMATCH)
		return NOMATCH;
	else {
		regerror (re_err, re, err_msg, MAXBUF);
		fprintf (errlog, "match(): %s\n", err_msg);
		return NOMATCH;
	}
}

int getnum (double * d, char * dptr, regex_t * numre, FILE * errlog) {
	int c;
	unsigned e;

	// Get rid of any leading white space
	chomp ();

	// Get non-white space string
	for (e = 0; e < MAXDBL && (c = getchar ()) != EOF && !isspace (c); ++e)
		dptr[e] = c;
	dptr[e] = NUL;

	// Determine whether string is a legitimate number string
	if ((c == EOF || isspace (c)) && match (dptr, numre, errlog)) {
		ungetc (c, stdin); // To push back EOF (prevents overflows)

		*d = strtod (dptr, NULL); // Legitimate number string

		return TRUE;
	} else if (c == EOF)
		return FALSE;
	else {
		// Log errors
		if (e == MAXDBL)
			fprintf (errlog, "getnum(): input string exceeds maxstr: [%s%c]\n", dptr, c);
		else
			fprintf (errlog, "getnum(): bad number: [%s%c]\n", dptr, c);

		// Walk through bad input until end of word or EOF, and pushes it back
		while (!isspace (c) && (c = getchar()) != EOF);
		ungetc (c, stdin);

		return FALSE;
	}
}

void reverse (char * s) {
	unsigned e, max;
	char tmp;

	for (e = 0; s[e] != NUL; ++e);
	max = e;

	/* Switch extrema values, then shift towards the middle on both extremas,
	   and repeat until at the middle */
	for (e = 0; e < max / 2; ++e) {
		tmp = s[e];
		s[e] = s[max - (e + 1)];
		s[max - (e + 1)] = tmp;
	}
}

char * rebase_i (double num, unsigned base, char * iptr) {
	unsigned tmp;
	char * tptr = iptr;

	// Rebase numbers individually to the new base backwards
	do {
		// Get the modulus
		// If it is < 10, then assign a number
		tmp = num;
		if ((tmp %= base) < 10)
			*(tptr++) = tmp + '0';

		// Otherwise assign an alphabetical number representation
		else {
			*(tptr++) = (tmp -= 10) % 26 + 'a';
			while ((tmp /= 26) > 0)
				*(tptr++) = (tmp - 1) % 26 + 'A';
		}
	} while ((num /= base) >= 1.0);
	*tptr = NUL;

	// Reverse backwards array
	reverse (iptr);

	return iptr;
}

char * rebase_f (double frac, unsigned base, char * fptr, char * iptr) {
	unsigned e = 0;
	double ntgr;

	frac = modf (frac * base, &ntgr);
	do {
		fptr = strcat (fptr, rebase_i (ntgr, base, iptr));
	} while (++e < MAXDBL && (frac = modf (frac * base, &ntgr)) > 0.0);

	return fptr;
}

char * rebase_d (double num, unsigned base, char * dptr, char * fptr, char * iptr) {
	int sign = POS;
	double ntgr, frac;

	// Determine sign
	if (num < 0.0) {
		num *= -1;
		sign = NEG;
	}

	// Split the floating point into an integer & fraction
	frac = modf (num, &ntgr);

	// "Reset" dptr value & set signage
	if (sign == NEG) {
		*dptr = '-';
		*(dptr + 1) = NUL;
	} else
		*dptr = NUL;

	// Integer
	dptr = strcat (dptr, rebase_i (ntgr, base, iptr));

	// Fraction
	dptr = strcat (dptr, ".");
	dptr = strncat (dptr, rebase_f (frac, base, fptr, iptr), (MAXDBL <= strlen (dptr)) ? 1 : MAXDBL - strlen (dptr));

	// Reset iptr & fptr
	*iptr = *fptr = NUL;

	return dptr;
}

////////////////////////////////////////////////////////////////////////////////
int main (int argc, char * argv[]) {
	unsigned base;
	int c, e;
	char * dptr, * fptr, * iptr;
	FILE * errlog;
	double num;
	regex_t renum;

	// Buffer for rebase_d
	dptr = malloc ((MAXDBL + 4)); // '-' + maxstr + '.' + 0 + NUL

	// Buffer for fraction in rebase_f
	fptr = malloc (MAXDBL + 1); // maxstr + NUL

	// Buffer for integer in rebase_i
	iptr = malloc (MAXDBL + 1); // maxstr + NUL

	// Open the erro log file
	errlog = fopen (".rebaser.log", "a");

	// Compiles an internal regex of a decimal number
	regcomp (&renum, "^-?[0-9]*.?[0-9]+$", REG_EXTENDED);

	// Get base {{{
	// From arguments
	if (argc > 1) {
		// Get base from argument
		if (match (argv[1], &renum, errlog) && strtod (argv[1], NULL) >= 2.0)
			base = (unsigned) fabs (strtod (argv[1], NULL)); // Idiot-proofs the base input

		// Otherwise log error & exit
		else {
			fprintf (errlog, "Bad base: [%s]\n", argv[1]);
			usage ();
			exit (1);
		}
	}

	// From stdin
	else if (!(getnum (&num, iptr, &renum, errlog) && (base = (unsigned) fabs (num)) >= 2)) {
		fprintf (errlog, "Bad base: [%d]\n", base);
		usage ();
		exit (1);
	}
	// }}}

	// Rebase input {{{
	// Rebase any number arguments
	if (argc > 2) {
		for (e = 2; e < argc; ++e )
			if (match (argv[e], &renum, errlog))
				printf ("%s\n", rebase_d (strtod (argv[e], NULL), base, dptr, fptr, iptr));
		goto end;
	}

	// Rebase any numbers from stdin
	while ((c = getchar()) != EOF) {
		ungetc (c, stdin);
		if (getnum (&num, iptr, &renum, errlog))
			printf ("%s\n", rebase_d (num, base, dptr, fptr, iptr));
	}
	// }}}

end:
	fclose (errlog);
	free (dptr);
	free (fptr);
	free (iptr);
	regfree (&renum);

	return 0;
}
