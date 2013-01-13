////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the substring function.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char* s; // Source string
	char* t; // Target string
	int b; // Begin
	int e; // End

	printf( "Enter full string: " );
	s = d_s( s );

	printf( "Enter the substring begin point: " );
	scanf( "%d", &b );

	printf( "Enter the substring end point: " );
	scanf( "%d", &e );

	t = substring( s, b, e );

	printf( "The substring = [%s]\n", t );

	free( s );
	free( t );

	return 0;
}
