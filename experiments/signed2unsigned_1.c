////////////////////////////////////////////////////////////////////////////////
// Comments

// Takes a signed INT_MIN and makes it unsigned. I'm curious to see whether it makes it
// equal to INT_MAX + 1.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	signed x = -1;

	printf( "signed x = [%d]\n", x );
	printf( "unsigned x = [%u]\n", ( unsigned )x );

	return 0;
}
