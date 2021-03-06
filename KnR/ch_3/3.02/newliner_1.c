////////////////////////////////////////////////////////////////////////////////
// Comments

// Works around the newline bug.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int cdbl[ 2 ] = { '\0', '\0' }; // two character array (Character DouBLe)

	while( ( cdbl[ 1 ] = getchar() ) != EOF )
	{
		putchar( cdbl[ 1 ] );

		cdbl[ 0 ] = cdbl[ 1 ];
	}
	if( cdbl[ 0 ] != '\n' )
	{
		putchar( '\n' );
	}

	return 0;
}
