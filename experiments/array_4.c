////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests what happens when a string is assigned to another string.

// Fails.

// N.B. The salient difference between a pointer and an array is that an array
// is not a variable.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char s[] = "hello";
	char ss[] = "goodbye";

	printf( "s = [%s]\n", s );
	printf( "ss = [%s]\n", ss );

	s = ss;
	printf( "New s = [%s]\n", s );

	return 0;
}
