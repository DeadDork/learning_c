////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the continue loop function.

// The continue function essentially ends the loop body prematurely, going back
// to the loop head as if it had gone all the way to the end of the loop body.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int max = 10;
	int e, a[ max ]; // Element, Array

	a[ 0 ] = 1;
	for( e = 1; e < max; ++e )
		a[ e ] = a[ e - 1 ] * -e;

	for( e = 0; e < max; ++e )
	{
		if( a[ e ] < 0 )
			continue;

		printf( "a[%d] = [%d]\n", e, a[ e ] );
	}

	return 0;
}
