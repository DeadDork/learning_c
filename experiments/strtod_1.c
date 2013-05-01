////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of the strtod() function.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char ns[] = "1234.5678", nns[] = "-1234.5678"; // Number String (1st, 2nd)
	double x, xx; // generic number variable (1st, 2nd)

	x = strtod( ns, NULL );
	xx = strtod( nns, NULL );

	printf( "x:\n\t%s - %d = %.4f\n", ns, ( int )x, x - ( int )x );
	printf( "xx:\n\t%s - %d = %.4f\n", nns, ( int )xx, xx - ( int )xx );

	return 0;
}
