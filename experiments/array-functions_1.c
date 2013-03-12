////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests whether changes to an array in a function change the elements in the array.

// Indeed, the original array is changed in the function.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void dummyfunc( char s[] );
/* Copies over s[] with a new string.
 
   `s` = String to copy over. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void dummyfunc( char s[] )
{
	int e = 0; // Element
	char ss[] = "Goodbye"; // String (second)

	while( s[ e ] != '\0' )
	{
		s[ e ] = ss[ e ];
		++e;
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char s[ 8 ] = { 'H', 'e', 'l', 'l', 'o', ' ', ' ', '\0' };

	printf( "Original:\n\t[%s]\n", s );
	dummyfunc( s );
	printf( "Changed:\n\t[%s]\n", s );

	return 0;
}
