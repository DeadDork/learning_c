////////////////////////////////////////////////////////////////////////////////
// Comments

// Testing out the d_s() function, but as a void return.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdlib.h>
#include <stdio.h>
#include "d_s-head_1.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

void d_s( char *s )
{
	int c;
	int sz = 0;

	s = malloc( sizeof( char ) );
	while( ( c = fgetc( stdin ) ) != '\n' && c != EOF )
	{
		s = realloc( s, sizeof( char ) * ++sz );
		*( s + ( sz - 1 ) ) = c;
	}
	*( s + sz ) = '\0';

	printf( "d_s: s = [%s]\n", s );
}
