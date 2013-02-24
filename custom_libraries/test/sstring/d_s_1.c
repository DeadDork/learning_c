////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the d_s() function from sstring.h

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

	printf( "String value before d_s() = [%s]\n", s );

	printf( "Enter string value: " );
	s = d_s( s );

	printf( "String value after d_s() = [%s]\n", s );

	free( s );

	return 0;
}
