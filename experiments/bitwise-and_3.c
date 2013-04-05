////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints the products of a number of different bitwise expressions.

// N.B. The last is particularly important, as it demonstrates a means of
// retrieving a bit value.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main( int argc, char * argv[] )
{
	unsigned int x = ( unsigned int )atoi( argv[ 1 ] );
	unsigned int y = ~x;

	printf( "x = [%u]\n", x );
	printf( "~x = [%u]\n", y );
	printf( "x | ~x = [%u]\n", x | y );
	printf( "x & ~x = [%u]\n", x & y );
	printf( "(~x | 1) & x = [%u]\n", ( ~x | 1 ) & x );

	return 0;
}
