////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the specprint functions.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include "../dynamic_string/d_s.h"
#include "specprint.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char* s;
	char* t;
	int b;
	int e;
	int i;

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
