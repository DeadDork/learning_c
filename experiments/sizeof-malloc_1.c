////////////////////////////////////////////////////////////////////////////////
// Comments

// Checks the return from sizeof() of a malloc-ed pointer.

// Results is 8 across the board -- my guess is that this is the size of the address.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char *s;

	printf( "Before malloc:\n\tsizeof(s) = [%d]\n", ( int )sizeof( s ) );
	s = malloc( sizeof( char ) * 10 );
	printf( "After malloc(char * 10):\n\tsizeof(s) = [%d]\n", ( int )sizeof( s ) );
	s = realloc( s, sizeof( char ) * 100 );
	printf( "After realloc(char * 100):\n\tsizeof(s) = [%d]\n", ( int )sizeof( s ) );

	free( s );

	return 0;
}
