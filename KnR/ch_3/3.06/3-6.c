////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 3-4.

// Demonstrates the use of itoa() with a minimum width.

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

int is_num( char c );
/* Determine if input is a number character.
 
   `c` = The input character to check.

   Return TRUE if `c` is a number character; otherwise return FALSE. */

int is_ws( char c );
/* Determine if input is a white space character.
 
   `c` = The input character to check.

   Return TRUE if `c` is a white space character; otherwise return FALSE. */

int get_num( int num[] );
/* Get an integer value from stdin.
 
   `num[]` = An array: first element holds the integer value; second element
   holds an EOF character if stdin reaches end of file.

   Returns NOERR if there is no error; otherwise return ERROR. */

void reverse( char s[] );
/* Reverse the order of elements in an array.
 
   `s[]` = Array to reverse. */

void itoa( int n, char s[], int min );
/* Transform an integer into a string array.
 
   `n` = The integer to transform.

   `s[]` = The string array the integer gets transformed into. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_num( char c )
{
	return ( c >= '0' && c <= '9' ) ? TRUE : FALSE;
}

int is_ws( char c )
{
	return ( c == ' ' || c == '\t' || c == '\n' ) ? TRUE : FALSE;
}

int get_num( int num[] )
{
	int c, sign;
	unsigned total = 0;

	/* Chomp & get first integer character */
	while( ( c = getchar() ) != EOF && c != '-' && !is_num( c ) );
	/* Negative integer */
	if( c == '-' )
	{
		sign = -1;
		total = 0;
	}
	/* Positive integer */
	else if( is_num( c ) )
	{
		sign = 1;
		total = c - '0';
	}
	/* Errors */
	else if( c == EOF )
	{
		num[ 1 ] = EOF; // tells main() to quit loop
		return ERROR; // no input
	}
	else
	{
		return ERROR; // not an integer
	}

	/* Get the rest of the integer characters */
	while( ( c = getchar() ) != EOF && is_num( c ) )
	{
		total = total * 10 + c - '0';
	}
	num[ 0 ] = total * sign; // assign sign (hehehe)

	/* Determine if integer entry has any errors */
	if( c == EOF )
	{
		num[ 1 ] = EOF;
		return NOERR; // final integer before end of file
	}
	else if( is_ws( c ) )
	{
		return NOERR; // integer separated by white space
	}
	else
	{
		return ERROR; // not an integer
	}
}

void reverse( char s[] )
{
	int e, max;
	char temp;

	for( e = 0; s[ e ] != NUL; ++e );
	max = e;

	for( e = 0; e < max / 2; ++e )
	{
		temp = s[ e ];
		s[ e ] = s[ max - ( e + 1 ) ];
		s[ max - ( e + 1 ) ] = temp;
	}
}

void itoa( int n, char s[], int min )
{
	int e, sign;

	e = 0;
	sign = ( n < 0 ) ? -1 : 1;

	/* Assign integer values to string backwards */
	do
	{
		s[ e++ ] = ( n % 10 ) * sign + '0';
	}
	while( ( n /= 10 ) * sign > 0 );

	/* Add integer sign */
	if( sign == -1 )
	{
		s[ e++ ] = '-';
	}

	/* Pads with blanks as necessary */
	while( e < min )
	{
		s[ e++ ] = ' ';
	}

	s[ e ] = '\0';

	reverse( s );
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int num[ 2 ] = { 0, ~EOF }; // num[0] = value & num[1] = EOF value
	char s[ 12 ]; // '-' + 10 digits of 2^32 + NUL

	while( num[ 1 ] != EOF )
	{
		if( get_num( num ) )
		{
			itoa( num[ 0 ], s, 7 ); // 7, why not?
			printf( "itoa(%d, s, 7) = [%s]\n", num[ 0 ], s );
		}
		num[ 0 ] = 0;
	}

	return 0;
}
