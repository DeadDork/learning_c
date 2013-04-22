////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 3-5.

// Demonstrates the use of itob(): reads 2 or more numbers, the first of which
// is the unit base, and where the second number--and all subsequent numbers--is
// the number to be rebased.

// To make this program more useful, I've included a number of features that go
// beyond the scope of 3.6.

// Because this program is useful, it gets a real name: rebaser (slicing up
// eyeballs ha ha ha ho!)

// Bug: This program doesn't handle empty entries correctly. For instance, if
// there is a newline at the end of a file, it will be read as an error. At the
// same time, setting this value to NOERR makes it repeat the last value.

/* Proper input (1 < base < 37):
	1) rebaser (base) (number to rebase), e.g.:
		$./rebaser 16 40

	2) (stdin) | rebaser (base), e.g.:
		echo 7 8 9 | ./rebaser 8

	3) rebaser (file). N.B. The first value in (file) will be set as the base, e.g.
		./rebaser <test_file

	4) rebaser (base) <(file), e.g.:
		./rebaser 15 <test_file
*/

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NUL '\0'

#define FALSE 0
#define TRUE 1

#define ERROR 0
#define NOERR 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int is_numchar( char c );
/* Determines if input is a number character.
 
   `c` = The input character to check.

   Return TRUE if `c` is a number character; otherwise return FALSE. */

int is_numstr( char s[] );
/* Determines if a string is a number.
 
   `s[]` = String to check.

   Return TRUE if `s[]` is a number string; otherwise return FALSE. */

int atoi( char s[] );
/* Convert ascii number string to an integer.
 
   `s[]` = Number string to convert to a number.

   Return the integer value. */

int is_ws( char c );
/* Determine if input is a white space character.
 
   `c` = The input character to check.

   Return TRUE if `c` is a white space character; otherwise return FALSE. */

void chomp( void );
/* Eats up white space.
 
   N.B. Uses ungetc(), which goes beyond the scope of 3.6. */

int get_num( int num[] );
/* Get an integer value from stdin.
 
   `num[]` = An array: first element holds the integer value; second element
   holds an EOF character if stdin reaches end of file.

   Returns NOERR if there is no error; otherwise return ERROR. */

char rebase( int n );
/* Uses alphabet characters to represent digits greater than 9.
 
   N.B. This is not a safe function, so be sure to condition it appropriately,
   i.e. make sure that the base isn't less than 2 nor greater than 26 + 9
   (all the numerical set + alphabetical set). */

void reverse( char s[] );
/* Reverse the order of elements in an array.
 
   `s[]` = Array to reverse. */

void itob( int n, char s[], int b );
/* Transform an integer into a string array of an arbitrary base.
 
   `n` = The integer to transform.

   `s[]` = The string array the integer gets transformed into.
   
   `b` = Desired base value. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_numchar( char c )
{
	if( c >= '0' && c <= '9' )
	{
		return TRUE; // c is a number character
	}
	else
	{
		return FALSE; // c is not a number character
	}
}

int is_numstr( char s[] )
{
	int e;

	for( e = 0; s[ e ] != NUL && is_numchar( s[ e ] ); ++e );

	if( s[ e ] == NUL )
	{
		return TRUE; // s[] is a number string
	}
	else
	{
		return FALSE; // s[] is not a number string
	}
}

int atoi( char s[] )
{
	int e, sign;
	unsigned total;

	if( s[ 0 ] == '-' )
	{
		sign = -1;
		total = 0;
	}
	else if( is_numchar( s[ 0 ] ) )
	{
		sign = 1;
		total = s[ 0 ] - '0';
	}

	for( e = 1; s[ e ] != NUL; ++e )
	{
		total = total * 10 + s[ e ] - '0';
	}

	return ( int )( total * sign );
}

int is_ws( char c )
{
	if( c == ' ' || c == '\t' || c == '\n' )
	{
		return TRUE; // c is a white space character
	}
	else
	{
		return FALSE; // c is not a white space character
	}
}

void chomp( void )
{
	int c;

	while( ( c = getchar() ) != EOF && is_ws( c ) );
	ungetc( c, stdin );
}

int get_num( int num[] )
{
	int c, e;
	int maxstr = 21; // round up ln(2^64)/ln(10) + NUL
	char numstr[ maxstr ];

	/* Get number string */
	chomp();
	for( e = 0; ( c = getchar() ) != EOF && !is_ws( c ) && e < maxstr; ++e )
	{
		numstr[ e ] = c;
	}
	numstr[ e ] = NUL;

	if( c == EOF )
	{
		num[ 1 ] = EOF; // not necessarily an error
	}

	if( e == 0 )
	{
		return ERROR; // no entry
	}

	if( is_numstr( numstr ) )
	{
		num[ 0 ] = atoi( numstr );
		return NOERR; // entry a number
	}
	else
	{
		return ERROR; // entry not a number
	}
}

char rebase( int n )
{
	if( n >= 10 )
	{
		return 'A' + ( n - 10 ); // returns an alphabetical character when n >= 10,
	                             // with 'A' = 10, 'B' = 11, and so forth
	}
	else
	{
		return n; // return a numerical character when n < 10
	}
}

void reverse( char s[] )
{
	int e, max;
	char temp;

	for( e = 0; s[ e ] != NUL; ++e );
	max = e;

	/* Switch extrema values, then shift to the middle on both extremas,
	   and repeat until at the middle */
	for( e = 0; e < max / 2; ++e )
	{
		temp = s[ e ];
		s[ e ] = s[ max - ( e + 1 ) ];
		s[ max - ( e + 1 ) ] = temp;
	}
}

void itob( int n, char s[], int b )
{
	int e, sign;

	e = 0;
	sign = ( n < 0 ) ? -1 : 1;

	/* Assign rebased number values to array backwards */
	do
	{
		s[ e++ ] = ( ( n % b ) * sign <= 9 ) ? ( n % b ) * sign + '0' : rebase( ( n % b ) * sign );
	}
	while( ( n /= b ) * sign > 0 );

	/* Assign signage */
	if( sign == -1 )
	{
		s[ e++ ] = '-';
	}

	s[ e ] = '\0';

	reverse( s );
}

////////////////////////////////////////////////////////////////////////////////
int main( int argc, char * argv[] )
{
	int e, num[ 2 ] = { 0, ~EOF }; // Element, num[0] = value & num[1] = EOF value
	int base = 10, error = NOERR; // BASE number (default is base 10), ERROR
	char s[ 66 ]; // '-' + 2^64 in base 2 digits + NUL

	/* GET BASE */
	/* From arguments */
	if( argc > 1 )
	{
		for( e = 1; e < argc && is_numstr( argv[ e ] ); ++e );
		if( e != argc )
		{
			return 1; // Error (bad arguments)
		}

		base = atoi( argv[ 1 ] );
	}
	/* From stdin */
	else
	{
		error = get_num( num );
		base = num[ 0 ];
	}
	if( base < 2 || base > 35 )
	{
		return 1; // base too small or too large
	}

	/* Convert numbers from arguments to base */
	if( argc > 2 )
	{
		for( e = 1; e < argc; ++e )
		{
			itob( atoi( argv[ e ] ), s, base );
			printf( "%s\n", s );
		}
		return 0;
	}
	else
	/* Convert numbers from stdin to base */
	while( num[ 1 ] != EOF && error == NOERR )
	{
		if( ( error = get_num( num ) ) )
		{
			itob( num[ 0 ], s, base );
			printf( "%s\n", s );
		}
	}

	/* Error reporting */
	return ( error == NOERR ) ? 0 : 1;
}
