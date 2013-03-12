////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests a function that removes trailing whitespace from a string.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int is_ws( char c );
/* Checks whether a given input character is a whitespace character.
 
   `c` = The input character.

   Returns TRUE if `c` is a whitespace character; otherwise returns FALSE. */

void despace( char str[] );
/* Removes trailing whitespace on a string.
 
   `str` = The string that will have any trailing whitespace removed. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_ws( char c )
{
	int value; // return VALUE

	if( c == ' ' || c == '\t' || c == '\n' )
	{
		value = TRUE;
	}
	else
	{
		value = FALSE;
	}

	return value;
}

void despace( char str[] )
{
	int e; // Element

	for( e = 0; str[ e ] != '\0'; ++e );
	for( --e; is_ws( str[ e ] ) && e >= 0; --e );
	str[ e + 1 ] = '\0';
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char s[] = "10 spaces          ";

	printf( "Before despacing:\n\t[%s]\n", s );
	despace( s );
	printf( "After despacing:\n\t[%s]\n", s );

	return 0;
}
