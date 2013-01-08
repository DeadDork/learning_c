////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the string to number conversion function (e.g. "123" => 123).

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
	float x;

	printf( "Enter a string that's in the same format of a number (e.g. '1234.5678'): " );
	s = d_s( s );

	x = str2num( s );
	//printf( "[%s] converts to [%f]\n", s, x );
	printf( "152.5 - %s = [%f]\n", s, 152.5 - x );

	free( s );

	return 0;
}
