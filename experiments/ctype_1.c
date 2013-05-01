////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of the <ctype.h> library.

////////////////////////////////////////////////////////////////////////////////
// Library

#include <stdio.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c = 9, cc = '9'; // Character (1st, 2nd)

	if( isnumber( c ) )
	{
		printf( "c is a digit (%d/%c)\n", c, c );
	}
	else
	{
		printf( "c is not a digit (%d/%c)\n", c, c );
	}

	if( isnumber( cc ) )
	{
		printf( "cc is a digit (%d/%c)\n", cc, cc );
	}
	else
	{
		printf( "cc is not a digit (%d/%c)\n", cc, cc );
	}

	return 0;
}
