////////////////////////////////////////////////////////////////////////////////
// Comments

// This is a very, VERY stupid calculator, created for the sole purpose of
// learning about bitwise operators.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char * c;
	unsigned int x, y, sum, carry;

	printf( "Enter x:" );
	while( ( *c = getchar() ) < '0' && ( *c = getchar() ) > '9' );
	x = atoi( c );

	printf( "Enter y:" );
	while( ( *c = getchar() ) < '0' && ( *c = getchar() ) > '9' );
	y = atoi( c );

	printf( "\nx = [%d]\n", x );
	printf( "y = [%d]\n", y );

	sum = x ^ y;
	carry = x & y;
	while( carry != 0 )
	{
		carry = carry << 1;
		x = sum;
		y = carry;
		sum = x ^ y;
		carry = x & y;
	}
	printf( "\nx + y = [%d]\n", sum );

	return 0;
}
