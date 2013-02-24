////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out the d_s() function in isolation.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define BUFSZ 100 // BUFfer SiZe

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

char * d_s( char * s );
/* Sets a pointer to a string of arbitrary length.
 
   `s` = The variable that will point to the string.

   Returns the address of the pointer. */

////////////////////////////////////////////////////////////////////////////////
// Functions

char * d_s( char * s )
{
	int c; // Character
	int mult = 1; // MULTiple
	long int sz = 0; // SiZe

	/* Dynamically allocates memory for a string input. */
	s = malloc( sizeof( char ) * BUFSZ );
	while( ( c = fgetc( stdin ) ) != '\n' && c != EOF )
	{
		if( ++sz > ( mult * BUFSZ ) )
		{
			s = realloc( s, sizeof( char ) * BUFSZ * ++mult );
		}
		*( s + ( sz - 1 ) ) = c;
	}
	*( s + sz ) = '\0';

	return s;
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char * dynstr;
	dynstr = d_s( dynstr );

	printf( "[%s]\n", dynstr );

	free( dynstr );

	return 0;
}
