////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the substring() function from sstring.h.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char * s; // Source string
	char * t; // Target string
	int b; // Begin
	int e; // End

	printf( "Enter full string: " );
	s = d_s( s );

	printf( "Enter the substring begin point (a number, in array notation): " );
	scanf( "%d", &b );

	printf( "Enter the substring end point (a number, in array notation): " );
	scanf( "%d", &e );

	t = substring( s, b, e );

	printf( "The substring = [%s]\n", t );

	free( s );
	free( t );

	return 0;
}
