////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the slength function

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char* s;

	printf( "Enter a string: " );
	s = d_s( s );

	printf( "String length = [%d]\n", slength( s ) );

	free( s );

	return 0;
}
