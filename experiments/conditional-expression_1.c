////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests whether the ternary expresion '?:' can be modified into the binary
// expression '?'.

// Nope, it can't.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int x; // garbage integer

	printf( "x = %d\n", x );
	x = ( x > 1000 ) ? 1000;
	printf( "x = %d\n", x );

	return 0;
}