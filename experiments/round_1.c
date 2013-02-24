////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out round(), ceil(), and floor() from math.h.

// Also tests out converting a float to an int.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <math.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	float a = 101.1;
	float b = 99.9;

	printf( "round()\n\ta: [%f], [%lf]\n\tb: [%f], [%lf]\n", a, round( a ), b, round( b ) );
	printf( "ceil()\n\ta: [%f], [%lf]\n\tb: [%f], [%lf]\n", a, ceil( a ), b, ceil( b ) );
	printf( "floor()\n\ta: [%f], [%lf]\n\tb: [%f], [%lf]\n", a, floor( a ), b, floor( b ) );
	printf( "convert to a to int:\n\ta: [%f], [%d]\n\tb: [%f], [%d]\n", a, ( int )a, b, ( int )b );

	return 0;
}
