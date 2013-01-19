////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests a dynamic-sized array.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int i;
	char ** pa;
	pa = malloc( sizeof( char * ) * 2 );

	pa[ 0 ] = malloc( sizeof( char ) * 3 );
	pa[ 0 ] = "hi";

	pa[ 1 ] = malloc( sizeof( char ) * 4 );
	pa[ 1 ] = "bye";

	pa = realloc( pa, sizeof( char * ) * 3 );

	pa[ 2 ] = malloc( sizeof( char ) * 6 );
	pa[ 2 ] = "again";

	printf( "pa[0] = [%s]\n", pa[ 0 ] );
	printf( "pa[1] = [%s]\n", pa[ 1 ] );
	printf( "pa[2] = [%s]\n", pa[ 2 ] );

	/* To verify null at the end of "hi" */
	printf( "Disposition of chars in pa[0] = " );
	for ( i = 0; i < 4; ++i )
	{
		printf( "[%d]", ( int )pa[ 0 ][ i ] );
	}
	printf( "\n" );

	return 0;
}
