////////////////////////////////////////////////////////////////////////////////
// Comments

// Examines the content of arrays of a declared length.

// Interesting: char arrays are given an extra element (presumably the end NULL), and all unassigned values are initialized to zero; int arrays are not given an extra element, but all elements are initialized to 0.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char c[ 10 ] = "hello";
	int i[ 4 ];
	i[ 0 ] = 1;
	i[ 1 ] = 2;
	int e;

	printf( "c:\n" );
	for( e = 0; e < 15; ++e )
	{
		printf( "\t[%c]/[%d]\n", c[ e ], ( int )c[ e ] );
	}

	printf( "i:\n" );
	for( e = 0; e < 9; ++e )
	{
		printf( "\t[%d]\n", i[ e ] );
	}

	return 0;
}
