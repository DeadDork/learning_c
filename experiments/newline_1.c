////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests how C handles very long lines separated by newlines in its source code.

// Well, it compiles without warning even with -Wextra and -Wall, so I have
// to conclude that I can end overlong lines without a '\'.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int x; // Some garbage integer

	printf( "Garbage int x = [%d]\n", x );

	if( ( x <= 2 ) ||
		( x <= 4 ) ||
		( x <= 8 ) ||
		( x <= 16 ) ||
		( x <= 32 ) ||
		( x <= 64 ) ||
		( x <= 128 ) ||
		( x < 256 ) )
	{
		printf( "Garbage int x is less than 256.\n" );
	}
	else if( x > 256 )
	{
		printf( "Garbage int x is more than 256.\n" );
	}

	return 0;
}
