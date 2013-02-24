////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the str2num() conversion function (e.g. "123" => 123) from sstring.h.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char * s;
	double x;
	double y = 1234.5678;

	printf( "Enter a string that's in the same format of a number (e.g. '1234.5678'): " );
	s = d_s( s );

	x = str2num( s );
	//printf( "[%s] converts to [%f]\n", s, x );
	printf( "%.4lf - %s = [%.4lf]\n", y,  s, y - x );

	free( s );

	return 0;
}
