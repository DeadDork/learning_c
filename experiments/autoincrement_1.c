////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the two autoincrement positions.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int x = 5;
	int y = 5;

	printf( "x = [%d]\n", x );
	printf( "--x = [%d]\n", --x );
	printf( "--x = [%d]\n", --x );
	printf( "x = [%d]\n", x );
	printf( "for loop, while x >= 0 (--x):\n" );
	for( ; x >= 0; --x )
	{
		printf( "\tx = [%d]\n", x );
	}
	printf( "x = [%d]\n", x );

	printf( "y = [%d]\n", y );
	printf( "y-- = [%d]\n", y-- );
	printf( "y-- = [%d]\n", y-- );
	printf( "y = [%d]\n", y );
	printf( "for loop, while y >= 0 (y--):\n" );
	for( ; y >= 0; y-- )
	{
		printf( "\ty = [%d]\n", y );
	}
	printf( "y = [%d]\n", y );

	return 0;
}
