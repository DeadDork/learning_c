////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores putting a return midway in a loop.

// N.B. Son of a gun! This works! I should take a look at return() someday...

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NUL '\0' // NULl character

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

signed int cmatch( char c, char str[] );
/* Retrieves the array position in a string of the first occurrence of a character.
 
   `c` = The matching character.

   `str[]` = The string being matched against.

   If there is a match, returns the position of the match; if there is no match,
   returns 0.
   
   N.B. cmatch() uses return() in a way I have never used before. I have no idea
   if it breaks posix or whatnot. */

////////////////////////////////////////////////////////////////////////////////
// Functions

signed int cmatch( char c, char str[] )
{
	int e; // Element

	for( e = 0; str[ e ] != NUL; ++e )
	{
		if( str[ e ] == c )
		{
			return e;
		}
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char s[] = "Hello, my darling wife."; // input String
	int c; // Character

	while( ( c = getchar() ) != EOF )
	{
		if( c != '\n' )
		{
			printf( "First occurrence of [%c] = [%d]\n", c, cmatch( c, s ) );
		}
	}

	return 0;
}
